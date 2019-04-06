export PATH=$OECORE_NATIVE_SYSROOT/usr/bin/qt5:$PATH
export OE_QMAKE_CFLAGS="$CFLAGS"
export OE_QMAKE_CXXFLAGS="$CXXFLAGS"
export OE_QMAKE_LDFLAGS="$LDFLAGS"
export OE_QMAKE_CC=$CC
export OE_QMAKE_CXX=$CXX
export OE_QMAKE_LINK=$CXX
export OE_QMAKE_AR=$AR
export QT_CONF_PATH=$OECORE_NATIVE_SYSROOT/usr/bin/qt5/qt.conf
export OE_QMAKE_LIBDIR_QT=`qmake -query QT_INSTALL_LIBS`
export OE_QMAKE_INCDIR_QT=`qmake -query QT_INSTALL_HEADERS`
export OE_QMAKE_MOC=$OECORE_NATIVE_SYSROOT/usr/bin/qt5/moc
export OE_QMAKE_UIC=$OECORE_NATIVE_SYSROOT/usr/bin/qt5/uic
export OE_QMAKE_RCC=$OECORE_NATIVE_SYSROOT/usr/bin/qt5/rcc
export OE_QMAKE_QDBUSCPP2XML=$OECORE_NATIVE_SYSROOT/usr/bin/qt5/qdbuscpp2xml
export OE_QMAKE_QDBUSXML2CPP=$OECORE_NATIVE_SYSROOT/usr/bin/qt5/qdbusxml2cpp
export OE_QMAKE_QT_CONFIG=`qmake -query QT_INSTALL_LIBS`/qt5/mkspecs/qconfig.pri
export OE_QMAKE_PATH_HOST_BINS=$OECORE_NATIVE_SYSROOT/usr/bin/qt5
export QMAKESPEC=`qmake -query QT_INSTALL_LIBS`/qt5/mkspecs/linux-oe-g++