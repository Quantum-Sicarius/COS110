#!/bin/bash

parentdir=$(basename "$PWD")

# if we don't have a file, start at zero
if [ ! -f "/tmp/${parentdir}/value.dat" ] ; then
  value=0

# otherwise read the value from the file
else
  value=`cat /tmp/${parentdir}/value.dat`
fi

# increment the value
value=`expr ${value} + 1`

# show it to the user
echo "Currently compressing: ${parentdir}Rev${value}"

#files=$(ls *.cpp *.h)
#echo ${files}

files="person.cpp student.cpp staff.cpp"

tar -zcvf "${parentdir}Rev${value}".tar.gz ${files}

# and save it for next time
echo "${value}" > /tmp/${parentdir}/value.dat
