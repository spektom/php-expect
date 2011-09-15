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

/* $Id: expect_fopen_wrapper.c 312443 2011-06-24 19:35:30Z michael $ */

#include "php.h"
#include "php_expect.h"
#include "php_streams.h"
#include <sys/wait.h>

php_stream *php_expect_stream_open (php_stream_wrapper *wrapper, char *command, char *mode, int options, 
							  char **opened_command, php_stream_context *context STREAMS_DC TSRMLS_DC)
{
	FILE *fp;
	if (strncasecmp("expect://", command, sizeof("expect://")-1) == 0) {
		command += sizeof("expect://")-1;
	} 

	if ((fp = exp_popen(command)) != NULL) {
		php_stream* stream = php_stream_fopen_from_pipe (fp, mode);
		zval *z_pid;
		MAKE_STD_ZVAL (z_pid);
		ZVAL_LONG (z_pid, exp_pid);
		stream->wrapperdata = z_pid;
		return stream;
	}
	
	return NULL;
}

static int php_expect_stream_close (php_stream_wrapper *wrapper, php_stream *stream TSRMLS_DC)
{
	zval* z_pid = stream->wrapperdata;
	int s = 0;
	waitpid (Z_LVAL_P(z_pid), &s, 0);
	zval_ptr_dtor (&z_pid);
	stream->wrapperdata = NULL;
	return s;
}
/* }}} */


static php_stream_wrapper_ops php_expect_wrapper_ops = {
	php_expect_stream_open,
	php_expect_stream_close, /* close */
	NULL, /* stat */
	NULL, /* stat_url */
	NULL, /* opendir */
	"expect",
	NULL, /* unlink */
	NULL, /* rename */
	NULL, /* mkdir */
	NULL  /* rmdir */
};

php_stream_wrapper php_expect_wrapper = {
	&php_expect_wrapper_ops,
	NULL,
	0, /* is_url */
};

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
