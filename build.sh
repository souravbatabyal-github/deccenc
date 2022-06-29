#!/bin/bash
# Usage: 
#   sh build.sh <logtype>
# Possible values:
#   logtype: clog, flog, rlog, syslog

help()
{
    echo "Usage: build.sh [ -l | --logtype ] [ -b | --buildtype ]"
    exit 2
}

######################################### Main Code ###################################################
SHORT=l:,b
LONG=logtype:,buildtype:,help
OPTS=$(getopt -a -n build --options $SHORT --longoptions $LONG -- "$@")
VALID_ARGUMENTS=$# # Returns the count of arguments that are in short or long options
if [ "$VALID_ARGUMENTS" -eq 0 ]; then
  help
fi
eval set -- "$OPTS"
while :
do
  case "$1" in
    -l | --logtype )
      logtype="$2"
      shift 2
      ;;
    -b | --buildtype )
      buildtype="$2"
      shift 2
      ;;
    -h | --help)
      help
      ;;
    --)
      shift;
      break
      ;;
    *)
      echo "Unexpected option: $1"
      help
      ;;
  esac
done

if [ -z $logtype ]; then
    help
    exit 1
fi
echo "LOG - logtype: $logtype"

#if [ -z $buildtype ]; then
#    help
#    exit 1
#fi
#echo "buildtype: $buildtype"

# build
aclocal
autoconf
automake -i --add-missing
./configure logtype=$logtype --prefix=$PWD
make
make install
