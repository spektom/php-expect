--TEST--
PECL Bug #22566 CGI
--SKIPIF--
<?php if (!extension_loaded("expect")) print "skip"; ?>
--FILE--
<?php
var_dump(ini_set('expect.timeout', 3));
var_dump(ini_set('expect.match_max', '2000'));
var_dump(ini_get('expect.timeout'));
var_dump(ini_get('expect.match_max'));
?>
--EXPECT--
string(2) "10"
string(4) "5000"
string(1) "3"
string(4) "2000"
