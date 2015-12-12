#!/usr/bin/perl

# Jonathan Buch CS 270 Assignment #4 October 13th, 2015

# NOTE: USE BASH COMMANDS WHENEVER POSSIBLE (LOOKUP HOW TO USE)

use File::Compare;

$currdir = `pwd`;
$trashcan = $ENV{"HOME"}."/trashcan";
chomp $currdir;
$flag = 0;

# Check if subdirectory "trashcan" exists with home directory
if (not -e $trashcan) {
	my $make = `mkdir ~/trashcan`;
} 

if (@ARGV[0] eq "-e" || @ARGV[0] eq "-i" || @ARGV[0] eq "-e" || @ARGV[0] eq "-r") {
	$flag = "Set"; 
}

# Evaluating the options supplied

# If the arguments supplied include "-e", "-i", "-l", or "-r"
# Use its respective option:

# Empty: "-e" All files should be deleted (USE RM -rf)

if (@ARGV[0] eq "-e") {
	$delete = `rm -rf ~/trashcan/*`;
}

# Interactive: "-i" Prompt user before move any file to the trashcan

elsif (@ARGV[0] eq "-i") {
	shift();
	foreach my $files (@ARGV) {
		print "Move $files to trashcan. Continue? ('yes' to Continue)";
		my $input = <STDIN>;
		chomp $input;
		if ($input eq "yes") {
			my $move = `mv -v $currdir/$files $trashcan`;
			print $move;
		}
		else {
		}
	}
}

# List: "-l" List the files in the trashcan subdirectory (USE ls -l trashcan)

elsif ($ARGV[0] eq "-l") {
	$list = `ls -l $trashcan`;
	print $list;
}

# Retrieve: "-r" Copy the argument specified from the trashcan into current subdirectory
# ^ If same file name exists already, prompt user. If yes, replace. If no, do nothing.	

elsif ($ARGV[0] eq "-r") {
	shift();
	foreach my $files (@ARGV) {
		if (-e "$trashcan/$files") {
			if (-e "$currdir/$files") {
				print "$files already exists. Replace? (Yes or No)";
				my $input = <STDIN>;
				chomp $input;
				if ($input eq "yes") {
					my $move = `mv -vf $trashcan/$files $currdir`;
					print $move;
				}
				else {
					print "Ignoring File";
				}
			}
			else {
				my $move = `mv -vf $trashcan/$files $currdir`;
				print $move;
			}
		}
	}
}

if (not $flag eq "Set") {
	foreach $files (@ARGV) {	
		shift();

		# If the argument is a directory:
		if (-d $files) {
			# Copy the entire directory including its files to the trashcan
			my $move = `mv -v $files ~/trashcan`;
			print $move;
		}
		# If the argument is a file:
		elsif (-f $files) {
			# If the file exists in the trashcan already
			if (-e "$trashcan/$files") {
				# Ex. "file1.txt" to "file1.txt.1"	
				# If not, the new file should replace the old one
				# Counts the number of files with the same file name to append a new numbered version
				++$count while glob "$trashcan/$files*";
				if (compare("$trashcan/$files", "$currdir/$files") == 0) {
					my $move = `mv -v $files $trashcan`;
					print $move;
				}
				# If it has been changed, append .i to the file with i being the "version"
				else {
					if ($count > 1) {
						my $rename = `mv $files $files.$count`;
						print $rename;
						my $move = `mv $files.$count $trashcan`;
						print $move;
					}
					else {
						my $rename = `mv -v $files $files.$count`;
						print $rename;
						my $move = `mv -v $files.$count $trashcan`;
						print $move;
						$count = 1;
					}
				}
			}
			else {
				my $move = `mv -v $files $trashcan`;
				print $move;
			}
		}
	}
}
