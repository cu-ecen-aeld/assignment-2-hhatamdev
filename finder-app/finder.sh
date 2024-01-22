#!/bin/sh
filesdir="$1"
searchstr="$2"
if [ $# -ne 2 ]
then
   echo "Usage: $0 filesdir searchstr"
   exit 1
fi

#echo "Searching for \"${searchstr}\" in folder:\"${filesdir}\""

 
if ! [ -d ${filesdir} ] 
then 
    echo " Folder ${filesdir} does not exist"
    exit 1
fi

grep -c -r "${searchstr}" ${filesdir} | grep -P ".*:([\d]+)" | cut -d: -f2 | awk 'BEGIN{filecnt=0;matchcnt=0}{filecnt=filecnt+1;matchcnt=matchcnt+$1}END{print "The number of files are ",filecnt,"and the number of matching lines are ",matchcnt}'


