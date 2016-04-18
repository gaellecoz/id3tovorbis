AC_CONFIG_MACRO_DIR([m4])

PACKAGE=id3tovorbis
VERSION=0.0.1
BUG_REPORT_ADDRESS=id3tovorbis@le-coz.net

AC_PREREQ(2.59)
AC_INIT([PACKAGE], [VERSION], [BUG_REPORT_ADDRESS])

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

# Checks for programs.
AC_PROG_CC_C99
AC_PROG_INSTALL

# Checks for libraries.
LDFLAGS="$LDFLAGS -L/opt/local/lib"
AC_CHECK_LIB([m], [libvorbis], [], [AC_MSG_ERROR([libvorbis not found])])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdlib.h])

CFLAGS="$CFLAGS -I/opt/local/include/"
AC_CHECK_HEADERS([vorbis/vorbisfile.h], [], [AC_MSG_ERROR([libvorbis header not found])])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])

AC_OUTPUT
