AC_CONFIG_MACRO_DIR([m4])

AC_PREREQ(2.59)
AC_INIT([id3tovorbis], [0.0.1], [id3tovorbis@le-coz.net])

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

# AC_SUBST(ACLOCAL_AMFLAGS, "-I m4")
AC_CONFIG_MACRO_DIR([m4])

AC_LANG([C++])

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL

# Checks for libraries.
#AC_CHECK_LIB([tag], [TagLib::ID3v2::Tag], [], [AC_MSG_ERROR([libtag not found])])
AC_PATH_PROG(TAGLIB_CONFIG, taglib-config)
	if test "$TAGLIB_CONFIG" != "" ; then
		CPPFLAGS="$CPPFLAGS `$TAGLIB_CONFIG --cflags`"
		LIBS="$LIBS `$TAGLIB_CONFIG --libs`"
		AC_CHECK_HEADERS([taglib.h], ,
			if test "$taglib" = "yes" ; then
				AC_MSG_ERROR([missing taglib.h header])
			fi
		)
	else
		if test "$taglib" = "yes" ; then
			AC_MSG_ERROR([taglib-config executable is missing])
		fi
	fi
LIBS="$LIBS -ltag"

AC_CHECK_LIB([z], [inflate], [], [AC_MSG_ERROR([zlib not found])])



# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stdlib.h])

AC_CHECK_HEADERS([taglib/tag.h], [], [AC_MSG_ERROR([libtag header not found])])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.

AC_CONFIG_FILES([Makefile
				m4/Makefile
                 src/Makefile
                 tests/Makefile])

AC_OUTPUT
