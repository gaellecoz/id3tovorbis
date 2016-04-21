AC_CONFIG_MACRO_DIR([m4])

PACKAGE=id3tovorbis
VERSION=0.0.1
BUG_REPORT_ADDRESS=id3tovorbis@le-coz.net

AC_PREREQ(2.59)
AC_INIT(id3tovorbis, 0.0.1, id3tovorbis@le-coz.net)

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

# AC_SUBST(ACLOCAL_AMFLAGS, "-I m4")
AC_CONFIG_MACRO_DIR([m4])

AC_LANG([C++])

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL

# Checks for libraries.
#AC_ARG_VAR(taglib-libraries,AC_HELP_STRING([--with-taglib-libraries=DIR],[Directory where taglib library is installed (optional)]), tag_libraries="$withval", tag_libraries="")
#AC_ARG_VAR(taglib-includes,AC_HELP_STRING([--with-taglib-includes=DIR],[Directory where taglib header files are installed (optional)]), tag_includes="$withval", tag_includes="")

  if test "x$tag_libraries" != "x" ; then
    TAGLIB_LIBS="-L$tag_libraries"
    #LDFLAGS="$LDFLAGS -L$tag_libraries"
  fi

  if test "x$tag_includes" != "x" ; then
    TAGLIB_CFLAGS='-I$tag_includes'
  fi


#PKG_PROG_PKG_CONFIG
#if test "x$PKG_CONFIG" != "x"
#then
#  PKG_CHECK_MODULES([TAGLIB], [tag])
#fi
#AC_CHECK_LIB([tag], [], [], [AC_MSG_ERROR([libtag not found])])
AC_CHECK_LIB([tag], [TagLib::FileRef])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdlib.h])

#AC_CHECK_HEADERS([tag.h], [], [AC_MSG_ERROR([libtag header not found])])
AC_CHECK_HEADERS([tag.h])


# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.

AC_CONFIG_FILES([Makefile
				m4/Makefile
                 src/Makefile
                 tests/Makefile])

AC_OUTPUT
