#define QT_VERSION_MAJOR    5
#define QT_VERSION_MINOR    7
#define QT_VERSION_PATCH    1
#define QT_VERSION_STR      "5.7.1"

/* Everything */
/* Compile time features */
#define QT_LARGEFILE_SUPPORT 64

// Compiler sub-arch support

#ifndef QT_BOOTSTRAPPED

#if defined(QT_NO_ALSA) && defined(QT_ALSA)
# undef QT_NO_ALSA
#elif !defined(QT_NO_ALSA) && !defined(QT_ALSA)
# define QT_NO_ALSA
#endif

#if defined(QT_NO_CUPS) && defined(QT_CUPS)
# undef QT_NO_CUPS
#elif !defined(QT_NO_CUPS) && !defined(QT_CUPS)
# define QT_NO_CUPS
#endif

#if defined(QT_NO_EGL_X11) && defined(QT_EGL_X11)
# undef QT_NO_EGL_X11
#elif !defined(QT_NO_EGL_X11) && !defined(QT_EGL_X11)
# define QT_NO_EGL_X11
#endif

#if defined(QT_NO_GLIB) && defined(QT_GLIB)
# undef QT_NO_GLIB
#elif !defined(QT_NO_GLIB) && !defined(QT_GLIB)
# define QT_NO_GLIB
#endif

#if defined(QT_NO_HARFBUZZ) && defined(QT_HARFBUZZ)
# undef QT_NO_HARFBUZZ
#elif !defined(QT_NO_HARFBUZZ) && !defined(QT_HARFBUZZ)
# define QT_NO_HARFBUZZ
#endif

#if defined(QT_NO_ICONV) && defined(QT_ICONV)
# undef QT_NO_ICONV
#elif !defined(QT_NO_ICONV) && !defined(QT_ICONV)
# define QT_NO_ICONV
#endif

#if defined(QT_NO_IMAGEFORMAT_JPEG) && defined(QT_IMAGEFORMAT_JPEG)
# undef QT_NO_IMAGEFORMAT_JPEG
#elif !defined(QT_NO_IMAGEFORMAT_JPEG) && !defined(QT_IMAGEFORMAT_JPEG)
# define QT_NO_IMAGEFORMAT_JPEG
#endif

#if defined(QT_NO_LIBPROXY) && defined(QT_LIBPROXY)
# undef QT_NO_LIBPROXY
#elif !defined(QT_NO_LIBPROXY) && !defined(QT_LIBPROXY)
# define QT_NO_LIBPROXY
#endif

#if defined(QT_NO_MITSHM) && defined(QT_MITSHM)
# undef QT_NO_MITSHM
#elif !defined(QT_NO_MITSHM) && !defined(QT_MITSHM)
# define QT_NO_MITSHM
#endif

#if defined(QT_NO_OPENVG) && defined(QT_OPENVG)
# undef QT_NO_OPENVG
#elif !defined(QT_NO_OPENVG) && !defined(QT_OPENVG)
# define QT_NO_OPENVG
#endif

#if defined(QT_NO_SESSIONMANAGER) && defined(QT_SESSIONMANAGER)
# undef QT_NO_SESSIONMANAGER
#elif !defined(QT_NO_SESSIONMANAGER) && !defined(QT_SESSIONMANAGER)
# define QT_NO_SESSIONMANAGER
#endif

#if defined(QT_NO_SHAPE) && defined(QT_SHAPE)
# undef QT_NO_SHAPE
#elif !defined(QT_NO_SHAPE) && !defined(QT_SHAPE)
# define QT_NO_SHAPE
#endif

#if defined(QT_NO_TSLIB) && defined(QT_TSLIB)
# undef QT_NO_TSLIB
#elif !defined(QT_NO_TSLIB) && !defined(QT_TSLIB)
# define QT_NO_TSLIB
#endif

#if defined(QT_NO_XCURSOR) && defined(QT_XCURSOR)
# undef QT_NO_XCURSOR
#elif !defined(QT_NO_XCURSOR) && !defined(QT_XCURSOR)
# define QT_NO_XCURSOR
#endif

#if defined(QT_NO_XFIXES) && defined(QT_XFIXES)
# undef QT_NO_XFIXES
#elif !defined(QT_NO_XFIXES) && !defined(QT_XFIXES)
# define QT_NO_XFIXES
#endif

#if defined(QT_NO_XKB) && defined(QT_XKB)
# undef QT_NO_XKB
#elif !defined(QT_NO_XKB) && !defined(QT_XKB)
# define QT_NO_XKB
#endif

#if defined(QT_NO_XRANDR) && defined(QT_XRANDR)
# undef QT_NO_XRANDR
#elif !defined(QT_NO_XRANDR) && !defined(QT_XRANDR)
# define QT_NO_XRANDR
#endif

#if defined(QT_NO_XRENDER) && defined(QT_XRENDER)
# undef QT_NO_XRENDER
#elif !defined(QT_NO_XRENDER) && !defined(QT_XRENDER)
# define QT_NO_XRENDER
#endif

#if defined(QT_NO_XSYNC) && defined(QT_XSYNC)
# undef QT_NO_XSYNC
#elif !defined(QT_NO_XSYNC) && !defined(QT_XSYNC)
# define QT_NO_XSYNC
#endif

#if defined(QT_NO_ZLIB) && defined(QT_ZLIB)
# undef QT_NO_ZLIB
#elif !defined(QT_NO_ZLIB) && !defined(QT_ZLIB)
# define QT_NO_ZLIB
#endif

#if defined(QT_OPENGL_ES) && defined(QT_NO_OPENGL_ES)
# undef QT_OPENGL_ES
#elif !defined(QT_OPENGL_ES) && !defined(QT_NO_OPENGL_ES)
# define QT_OPENGL_ES
#endif

#if defined(QT_OPENGL_ES_2) && defined(QT_NO_OPENGL_ES_2)
# undef QT_OPENGL_ES_2
#elif !defined(QT_OPENGL_ES_2) && !defined(QT_NO_OPENGL_ES_2)
# define QT_OPENGL_ES_2
#endif

#if defined(QT_THREADSAFE_CLOEXEC) && defined(QT_NO_THREADSAFE_CLOEXEC)
# undef QT_THREADSAFE_CLOEXEC
#elif !defined(QT_THREADSAFE_CLOEXEC) && !defined(QT_NO_THREADSAFE_CLOEXEC)
# define QT_THREADSAFE_CLOEXEC 1
#endif

#endif // QT_BOOTSTRAPPED

#define QT_VISIBILITY_AVAILABLE

#define QT_QPA_DEFAULT_PLATFORM_NAME "wayland"
