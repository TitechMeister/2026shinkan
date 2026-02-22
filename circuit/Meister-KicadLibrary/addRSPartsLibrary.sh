#! /bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 {PartName}.zip"
    exit 1
fi

DIRPATH=$(dirname $BASH_SOURCE)
LIBNAME=$(basename $1 | sed 's/\.[^\.]*$//' | sed 's/^LIB_//')

mkdir -p $DIRPATH/dist
mkdir $DIRPATH/$LIBNAME

unzip -o $1 -d $DIRPATH/dist
cp $DIRPATH/dist/license.txt $DIRPATH/$LIBNAME/
cp $DIRPATH/dist/$LIBNAME/Kicad/$LIBNAME.dcm $DIRPATH/$LIBNAME/
cp $DIRPATH/dist/$LIBNAME/Kicad/$LIBNAME.lib $DIRPATH/$LIBNAME/
mkdir $DIRPATH/$LIBNAME/$LIBNAME.pretty
cp $DIRPATH/dist/$LIBNAME/KiCad/*.kicad_mod $DIRPATH/$LIBNAME/$LIBNAME.pretty/
