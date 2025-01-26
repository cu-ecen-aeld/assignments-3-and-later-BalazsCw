#!/bin/bash

##############################
#
# Args: filesdir searchstr
#


if [ $# -lt 2 ]
then
  echo "Not enough args, 2 required: found $# args"
  exit 1
fi

if ! [ -d $1 ]
then
  echo "$1 is not a directory"
  exit 1
fi

# Get X = Number of files in (filesdir) and all subdirectories
# Get Y = is the number of matching lines (searchstr) found in the respective files

X=$( find $1 -type f| wc -w )
Y=$( grep -r "$2" $1 | wc -w )
echo "The number of files are $X and the number of matching lines are $Y"
exit 0


