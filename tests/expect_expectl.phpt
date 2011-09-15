--TEST--
expect_expectl()
--SKIPIF--
<?php if (!extension_loaded("expect")) print "skip"; ?>
--INI--
expect.loguser=Off
--FILE--
<?php
$cases = array (
	array (0 => "part", 1 => "glob", EXP_GLOB),
	array (0 => ".*reg.*ression", 1 => "regexp", EXP_REGEXP),
	array (0 => "Matching exact string", 1 => "exact", EXP_EXACT)
);

$fp = fopen ("expect://echo Matching a part of the sentence", "r");
print expect_expectl ($fp, $cases)."\n";
fclose ($fp);

$fp = fopen ("expect://echo Matching regular expression", "r");
print expect_expectl ($fp, $cases)."\n";
fclose ($fp);

$fp = fopen ("expect://echo Matching exact string", "r");
print expect_expectl ($fp, $cases)."\n";
fclose ($fp);
?>
--EXPECT--
glob
regexp
exact
