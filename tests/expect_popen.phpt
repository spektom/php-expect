--TEST--
expect_popen()
--SKIPIF--
<?php if (!extension_loaded("expect")) print "skip"; ?>
--FILE--
<?php
$fp = expect_popen ("echo working");
print fgets($fp);
fclose ($fp);
?>
--EXPECT--
working
