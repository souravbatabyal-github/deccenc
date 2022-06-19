#!/bin/bash
# Usage: 
#   ./BUILD <logtype>
# Possible values:
#   logtype: rlog, clog

usage()
{
    echo "Usage: "
    echo "        ./BUILD <logtype>"
    echo "Possible values:"
    echo "        logtype: rlog, clog"

}
# Main Code
logtype=none
if [[ -z $1 ]]; then
    usage
    exit 1
else
    logtypeval=$1
fi
make distclean
aclocal
autoconf
automake -i --add-missing
./configure logtype=$logtypeval --prefix=$PWD
make
make install
