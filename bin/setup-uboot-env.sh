#!/bin/sh

# This distribution contains contributions or derivatives under copyright
# as follows:
#
# Copyright (c) 2010, Texas Instruments Incorporated
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# - Redistributions of source code must retain the above copyright notice,
#   this list of conditions and the following disclaimer.
# - Redistributions in binary form must reproduce the above copyright
#   notice, this list of conditions and the following disclaimer in the
#   documentation and/or other materials provided with the distribution.
# - Neither the name of Texas Instruments nor the names of its
#   contributors may be used to endorse or promote products derived
#   from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
# OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
# ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

cwd=`dirname $0`
. $cwd/common.sh

do_expect() {
    echo "expect {" >> $3
    check_status
    echo "    $1" >> $3
    check_status
    echo "}" >> $3
    check_status
    echo $2 >> $3
    check_status
    echo >> $3
}


echo
echo "--------------------------------------------------------------------------------"
echo "This step will set up the u-boot variables for booting the EVM."
echo "--------------------------------------------------------------------------------"

ipdefault=`ifconfig | grep 'inet addr:'| grep -v '127.0.0.1' | cut -d: -f2 | awk '{ print $1 }'`
platform=`grep PLATFORM= $cwd/../Rules.make | cut -d= -f2`

# Configure prompt for U-Boot 2016.05
prompt="=>"


echo "Autodetected the following ip address of your host, correct it if necessary"
read -p "[ $ipdefault ] " ip
echo

if [ ! -n "$ip" ]; then
    ip=$ipdefault
fi

if [ -f $cwd/../.targetfs ]; then
    rootpath=`cat $cwd/../.targetfs`
else
    echo "Where is your target filesystem extracted?"
    read -p "[ ${HOME}/targetNFS ]" rootpath

    if [ ! -n "$rootpath" ]; then
        rootpath="${HOME}/targetNFS"
    fi
    echo
fi

kernelimage="zImage-""$platform"".bin"
kernelimagesrc=`ls -1 $cwd/../board-support/prebuilt-images/$kernelimage`
kernelimagedefault=`basename $kernelimagesrc`


echo "Select Linux kernel location:"
echo " 1: TFTP"
echo " 2: SD card"
echo
read -p "[ 1 ] " kernel

if [ ! -n "$kernel" ]; then
    kernel="1"
fi

echo
echo "Select root file system location:"
echo " 1: NFS"
echo " 2: SD card"
echo
read -p "[ 1 ] " fs

if [ ! -n "$fs" ]; then
    fs="1"
fi



if [ "$kernel" -eq "1" ]; then
    echo
    echo "Available kernel images in /tftproot:"
    for file in /tftpboot/*; do
	basefile=`basename $file`
	echo "    $basefile"
    done
    echo
    echo "Which kernel image do you want to boot from TFTP?"
    read -p "[ $kernelimagedefault ] " kernelimage

    if [ ! -n "$kernelimage" ]; then
	kernelimage=$kernelimagedefault
    fi
fi

board="unknown"
check_for_board() {
    lsusb -vv -d 0403:6001 > /dev/null 2>&1

    if [ "$?" = "0" ]
    then
        board="x15"
    fi

    lsusb -vv -d 0403:6010 > /dev/null 2>&1

    if [ "$?" = "0" ]
    then
        board="am5-idk"
    fi
}

echo "timeout 300" > $cwd/setupBoard.minicom
echo "verbose on" >> $cwd/setupBoard.minicom
do_expect "\"stop autoboot:\"" "send \" \"" $cwd/setupBoard.minicom
do_expect "\"$prompt\"" "send \"env default -f -a\"" $cwd/setupBoard.minicom
do_expect "\"$prompt\"" "send \"saveenv\"" $cwd/setupBoard.minicom
do_expect "\"$prompt\"" "send \"reset\"" $cwd/setupBoard.minicom
do_expect "\"stop autoboot:\"" "send \" \"" $cwd/setupBoard.minicom

if [ "$kernel" -eq "1" ]; then
	if [ "$fs" -eq "1" ]; then
		#TFTP and NFS Boot
		do_expect "\"$prompt\"" "send \"setenv serverip $ip\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send setenv rootpath '$rootpath'" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv bootfile $kernelimage\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv ip_method dhcp\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv nfsopts 'nolock,v3,tcp,rsize=4096,wsize=4096'\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv getuenv 'mmc dev \${mmcdev}; if mmc rescan; then if run loadbootenv; then run importbootenv; fi; fi;'\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send setenv bootcmd 'run findfdt; run getuenv; setenv autoload no;dhcp ;tftp \${loadaddr} $kernelimage; tftp \${fdtaddr} \${fdtfile}; run netargs; bootz \${loadaddr} - \${fdtaddr}'" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"saveenv\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"boot\"" $cwd/setupBoard.minicom
	else
		#TFTP and SD Boot
		do_expect "\"$prompt\"" "send \"setenv serverip $ip\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv bootfile $kernelimage\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv ip_method none\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv getuenv 'mmc dev \${mmcdev}; if mmc rescan; then if run loadbootenv; then run importbootenv; fi; fi;'\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send setenv bootcmd 'run findfdt; run getuenv; setenv autoload no; dhcp ; tftp \${loadaddr} $kernelimage; tftp \${fdtaddr} \${fdtfile}; run args_mmc; bootz \${loadaddr} - \${fdtaddr}'" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"saveenv\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"boot\"" $cwd/setupBoard.minicom
	fi
else
	if [ "$fs" -eq "1" ]; then
		#SD and NFS Boot
		do_expect "\"$prompt\"" "send \"setenv serverip $ip\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send setenv rootpath '$rootpath'" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv bootfile zImage\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv ip_method dhcp\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv nfsopts 'nolock,v3,tcp,rsize=4096,wsize=4096'\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv getuenv 'mmc dev \${mmcdev}; if mmc rescan; then if run loadbootenv; then run importbootenv; fi; fi;'\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send setenv bootcmd 'setenv autoload no; mmc rescan; run findfdt; run getuenv; setenv devtype mmc; run loadimage; run loadfdt; run netargs; bootz \${loadaddr} - \${fdtaddr}'" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"saveenv\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"boot\"" $cwd/setupBoard.minicom
	    else
		#SD and SD boot.
		do_expect "\"$prompt\"" "send \"setenv ip_method none\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv bootfile zImage\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"setenv getuenv 'mmc dev \${mmcdev}; if mmc rescan; then if run loadbootenv; then run importbootenv; fi; fi;'\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send setenv bootcmd 'mmc rescan; run findfdt; run getuenv; setenv devtype mmc; run loadimage; run loadfdt; run args_mmc; bootz \${loadaddr} - \${fdtaddr}'" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"saveenv\"" $cwd/setupBoard.minicom
		do_expect "\"$prompt\"" "send \"boot\"" $cwd/setupBoard.minicom

	fi
fi
echo "! killall -s SIGHUP minicom" >> $cwd/setupBoard.minicom

echo "--------------------------------------------------------------------------------"
echo "Would you like to create a minicom script with the above parameters (y/n)?"
read -p "[ y ] " minicom
echo

if [ ! -n "$minicom" ]; then
    minicom="y"
fi

if [ "$minicom" = "y" ]; then

    echo -n "Successfully wrote "
    readlink -m $cwd/setupBoard.minicom

    while [ yes ]
    do
        check_for_board

        if [ "$board" != "unknown" ]
        then
            break
        else
            echo ""
            echo "Board could not be detected. Please connect the board to the PC."
            read -p "Press any key to try checking again." temp
        fi
    done

    if [ "$board" != "unknown" ]
    then
        ftdiInstalled=`lsmod | grep ftdi_sio`
        if [ -z "$ftdiInstalled" ]
        then
            sudo modprobe -q ftdi_sio
        fi

        while [ yes ]
        do
            echo ""
            echo -n "Detecting connection to board... "
            loopCount=0
            port=`dmesg | grep FTDI | grep "tty" | tail -1 | grep "attached" |  awk '{ print $NF }'`
            while [ -z "$port" ] && [ "$loopCount" -ne "10" ]
            do
                #count to 10 and timeout if no connection is found
                loopCount=$((loopCount+1))

                sleep 1
                port=`dmesg  | grep FTDI | grep "tty" | tail -1 | grep "attached" |  awk '{ print $NF }'`
            done

            #check to see if we actually found a port
            if [ -n "$port" ]; then
                echo "/dev/$port"
                break;
            fi

            #if we didn't find a port and reached the timeout limit then ask to reconnect
            if [ -z "$port" ] && [ "$loopCount" = "10" ]; then
                echo ""
                echo "Unable to detect which port the board is connected to."
                echo "Please reconnect your board."
                echo "Press 'y' to attempt to detect your board again or press 'n' to continue..."
                read -p "(y/n)" retryBoardDetection
            fi

            #if they choose not to retry, ask user to reboot manually and exit
            if [ "$retryBoardDetection" = "n" ]; then
                echo ""
                echo "Please reboot your board manually and connect using minicom."
                exit;
            fi
        done

        sed -i -e "s|^pu port.*$|pu port             /dev/$port|g" ${HOME}/.minirc.dfl
    fi

    echo
    echo "--------------------------------------------------------------------------------"
    echo "Would you like to run the setup script now (y/n)?"
    echo
    echo "Please connect the ethernet cable as described in the Quick Start Guide."
    echo "Once answering 'y' on the prompt below, you will have 300 seconds to connect"
    echo "the board and power cycle it before the setup times out"
    echo
    echo "After successfully executing this script, your EVM will be set up. You will be "
    echo "able to connect to it by executing 'minicom -w' or if you prefer a windows host"
    echo "you can set up Tera Term as explained in the Software Developer's Guide."
    echo "If you connect minicom or Tera Term and power cycle the board Linux will boot."
    echo
    read -p "[ y ] " minicomsetup

    if [ ! -n "$minicomsetup" ]; then
       minicomsetup="y"
    fi

    if [ "$minicomsetup" = "y" ]; then
      cd $cwd
      sudo minicom -w -S setupBoard.minicom
      cd -
    fi

    echo "You can manually run minicom in the future with this setup script using: minicom -S $cwd/setupBoard.minicom"
    echo "--------------------------------------------------------------------------------"

fi
