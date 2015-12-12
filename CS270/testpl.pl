#!/usr/bin/perl

$OPENFILE = "filename.txt";

$result = 0;
open(OPENFILE);

while(<OPENFILE>){
	$result = $_ + $result;
	print;
}
print $result;
print "\n";
