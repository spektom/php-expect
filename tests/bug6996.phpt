--TEST--
PECL Bug #6996
--SKIPIF--
<?php if (!extension_loaded("expect")) print "skip"; ?>
--FILE--
<?php
$stream = popen ("expect://echo 2>/dev/null", "r");

expect_expectl ($stream, array());

fclose ($stream);
?>
--EXPECTF--
Fatal error: expect_expectl(): supplied argument is not a valid stream resource in %s on line %d
