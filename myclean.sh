find src tests -type f -name "Makefile" -exec rm {} \;
find src tests -type f -name "Makefile.in" -exec rm {} \;
find src tests -type d -name ".deps" -exec rm -rf {} \;
rm Makefile
rm Makefile.in

find src tests -type f -name "*.o" -exec rm {} \;

rm .autotools
rm INSTALL
rm aclocal.m4
rm -rf autom4te.cache/
rm compile
rm config.guess
rm config.log
rm config.status
rm config.sub
rm configure
rm depcomp
rm install-sh
rm missing
rm test-driver
