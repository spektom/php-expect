dnl
dnl $Id: config.m4 319689 2011-11-22 16:27:35Z michael $
dnl 

PHP_ARG_WITH(expect,for expect support, 
[  --with-expect[=DIR]        Include expect support (requires libexpect >= 5.43.0).])

PHP_ARG_WITH(tcldir,specify path to Tcl needed by expect, 
[  --with-tcldir[=DIR]        Specify path to Tcl config script (tclConfig.sh).])

if test "$PHP_EXPECT" != "no"; then

  for i in $PHP_EXPECT/include/expect.h $PHP_EXPECT/include/*/expect.h \
        /usr/local/include/expect.h /usr/local/include/*/expect.h \
        /usr/include/expect.h /usr/include/*/expect.h ;
  do
    if test -f $i; then
      LIBEXPECT_INCLUDE_DIR=`dirname $i`
      LIBEXPECT_DIR=`dirname $LIBEXPECT_INCLUDE_DIR`
      break
    fi
  done

  for i in $PHP_TCLDIR/tclConfig.sh /usr/lib/tcl*/tclConfig.sh \
        /usr/local/lib/tcl*/tclConfig.sh \
	/System/Library/Frameworks/Tcl.framework/Versions/Current/tclConfig.sh;
  do
    if test -f $i; then
      . $i
      break
    fi
  done

  PHP_ADD_LIBRARY_WITH_PATH(tcl$TCL_VERSION, $TCL_PREFIX/lib, EXPECT_SHARED_LIBADD)
  PHP_ADD_LIBRARY_WITH_PATH(expect, $LIBEXPECT_DIR/lib, EXPECT_SHARED_LIBADD)
  PHP_ADD_INCLUDE($LIBEXPECT_INCLUDE_DIR)

  PHP_NEW_EXTENSION(expect, expect.c expect_fopen_wrapper.c, $ext_shared)
  PHP_SUBST(EXPECT_SHARED_LIBADD)
fi

