/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2004 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Michael Spector <michael@php.net>                            |
  +----------------------------------------------------------------------+
*/

/* $ Id: $ */ 

#ifndef PHP_EXPECT_H
#define PHP_EXPECT_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>

#include <tcl.h>
#include <expect_tcl.h>
#include <expect.h>

extern zend_module_entry expect_module_entry;
#define phpext_expect_ptr &expect_module_entry

#define PHP_EXPECT_VERSION "0.2.7-dev"

#ifdef PHP_WIN32
#define PHP_EXPECT_API __declspec(dllexport)
#else
#define PHP_EXPECT_API
#endif

PHP_MINIT_FUNCTION(expect);
PHP_MSHUTDOWN_FUNCTION(expect);
PHP_MINFO_FUNCTION(expect);

PHP_FUNCTION(expect_popen);
PHP_FUNCTION(expect_expectl);

extern php_stream_wrapper php_expect_wrapper;

ZEND_BEGIN_MODULE_GLOBALS(expect)
	php_stream* logfile_stream;
ZEND_END_MODULE_GLOBALS(expect)

#ifdef ZTS
#define EXPECT_G(v) TSRMG(expect_globals_id, zend_expect_globals *, v)
#else
#define EXPECT_G(v) (expect_globals.v)
#endif

#ifdef ZTS
#include "TSRM.h"
#endif /* ZTS */

#endif /* PHP_EXPECT_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
