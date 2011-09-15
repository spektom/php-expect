dnl
dnl $Id: config.m4 269919 2008-11-27 10:10:11Z michael $
dnl 

PHP_ARG_WITH(expect,for expect support, 
[  --with-expect[=DIR]        Include expect support (requires libexpect >= 5.43.0).])

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

  PHP_ADD_LIBRARY_WITH_PATH(expect, $LIBEXPECT_DIR/lib, EXPECT_SHARED_LIBADD)
  PHP_ADD_INCLUDE($LIBEXPECT_INCLUDE_DIR)

  PHP_NEW_EXTENSION(expect, expect.c expect_fopen_wrapper.c, $ext_shared)
  PHP_SUBST(EXPECT_SHARED_LIBADD)
fi
