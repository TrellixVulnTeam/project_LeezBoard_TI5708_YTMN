## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,em4 linker.cmd package/cfg/edma3_drv_bios6_tda2xx_m4_c1_st_sample_pem4.oem4

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/edma3_drv_bios6_tda2xx_m4_c1_st_sample_pem4.xdl
	$(SED) 's"^\"\(package/cfg/edma3_drv_bios6_tda2xx_m4_c1_st_sample_pem4cfg.cmd\)\"$""\"/oe/bld/build-CORTEX_1/arago-tmp-external-linaro-toolchain/work/am57xx_evm-linux-gnueabi/edma3-lld-rtos/2.12.05.30C-r0.1/git/examples/edma3_driver/evmtda2xx_M4/obj/tda2xx-evm/m4/debug/edma3_drv_arm_tda2xx_core1_sample_configuro/\1\""' package/cfg/edma3_drv_bios6_tda2xx_m4_c1_st_sample_pem4.xdl > $@
	-$(SETDATE) -r:max package/cfg/edma3_drv_bios6_tda2xx_m4_c1_st_sample_pem4.h compiler.opt compiler.opt.defs
