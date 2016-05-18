AC_ARG_WITH(taglib-libraries,AC_HELP_STRING([--with-taglib-libraries=DIR],[Directory where taglib library is installed (optional)]), tag_libraries="$withval", tag_libraries="")
AC_ARG_WITH(taglib-includes,AC_HELP_STRING([--with-taglib-includes=DIR],[Directory where taglib header files are installed (optional)]), tag_includes="$withval", tag_includes="")

  if test "x$tag_libraries" != "x" ; then
    TAGLIB_LIBS="-L$tag_libraries"
  fi

  if test "x$tag_includes" != "x" ; then
    TAGLIB_CFLAGS="-I$tag_includes"
  fi
