#!/bin/bash

#####################################
#
# args: full filename with path 
#       text to write to file
#

# Simple arg checker
if [ $# -lt 2 ]
then
  echo "Wrong number of arguments, 2 required, $# given"
  exit 1
fi

path_name=$( dirname $1 )
file_name=$( basename $1 )

# echo "path = $path_name, file = $file_name"

if ! [ -d $path_name ]
then
 mkdir $path_name -p
fi

echo $2 > $1
