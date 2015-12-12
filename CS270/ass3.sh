#!/bin/bash
# Jonathan Buch CS270 Assignment #3 September 30th, 2015

directory=`pwd`


# Were files supplied on the command line
if [ -z $1 ] ; then
	echo "No Files Were Given"
	exit 1
fi

echo "The arguments are $@"
echo "The full path of the file is $directory"

# Name of tsubdir needs to be $1(NO ext).tmp
	subdir="${1##*/}"
	tsubdir="${subdir%.[^.]*}.tmp"

# If tsubdir already exists, rename to preserve it
if [ -f $tsubdir ] ; then
	echo "File already exists, preserving name: $tsubdir to .cp"
	mv $tsubdir $tsubdir.cp
fi

echo "Creating directory: $tsubdir"
mkdir $tsubdir

# If the subdirectory wasn't created, exit
if [ ! -e $tsubdir ] ; then
	echo "Can't find the created subdirectory. Exiting..."
	exit 1
fi

for fullpath in "$@"
	do

	fname="${fullpath##*/}"

# Is the file locatable?
		if [ ! -e $fullpath ] ; then
			echo "File doesn't exist"
			break
		fi

# If a file can't be copied, print message
		if [ ! -r $fullpath ] ; then
			echo "Unable to copy $fullpath"
			break
		fi

# New name creation
		new=""

# If more than one file has the same name copied into the tsubdir, prompt user
		if [ -e $tsubdir/$fname ] ; then
			echo "File in Question: $tsubdir/$fname"
			OPTIONS="Overwrite DontCopy Rename"
			select opt in $OPTIONS ; do
				if [ "$opt" = "Overwrite" ] ; then
					echo "Overwritting File..."
					break
				elif [ "$opt" = "DontCopy" ] ; then
					echo "Leaving file as is..."
					continue 2
				elif [ "$opt" = "Rename" ] ; then
					echo -n "Choose File Name: " && read new
					echo "Renaming File to $new..."
					break
				else
					echo "No Choice"
				fi
			done
		fi


# Copy list to temporary subdirectory
		cp -rf $fullpath $tsubdir/$new
	done

# Execute tar to create tar file with files inside
cd $tsubdir
tar -cvf $tsubdir.tar *
mv $tsubdir.tar ..
cd $directory

# Tempdir needs to be deleted after tar has been executed
echo "Removing $tsubdir..."
rm -rf $tsubdir

# Restore the orignal file name that was preserved
if [ -f $tsubdir.cp ] ; then
	echo "Restoring $tsubdir.cp..."
	mv $tsubdir.cp $tsubdir
fi	

# Exit Program
