--TEST--
PECL Bug #12268 CGI
--SKIPIF--
<?php if (!extension_loaded("expect") || php_sapi_name() == 'cli') print "skip"; ?>
--INI--
expect.loguser=0
expect.logfile=php://output
--FILE--
<?php
if (php_sapi_name() == 'cli') exit;

$stream = expect_popen("echo Hello");

ob_start();

expect_expectl ($stream, array());

$r = ob_get_contents();
fclose ($stream);

print "Output: $r";
?>
--EXPECT--
Output: Hello
