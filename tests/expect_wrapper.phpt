--TEST--
expect stream wrapper
--SKIPIF--
<?php if (!extension_loaded("expect")) print "skip"; ?>
--FILE--
<?php
$fp = fopen ("expect://echo working", "r");
print fgets($fp);
fclose ($fp);
?>
--EXPECT--
working
