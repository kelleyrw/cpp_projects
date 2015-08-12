#!/bin/bash

# get the project dir
tools_dir=$(cd -P "$(dirname "${BASH_SOURCE[0]}")" && pwd)
project_dir=$(cd -P $tools_dir/.. && pwd)

# host name of the computer
export HOSTNAME=`hostname`

# setup root (if its not already setup)
if [ -z $ROOTSYS ]; then
    source /usr/local/root/6.02.00.patches/bin/thisroot.sh                             
    alias root='root -l'
fi

# setup boost (if its not already setup)
if [ -z $BOOST_CURRENT ]; then
    export BOOST_ROOT=/usr/local/boost/1.58.0
    export BOOST_CURRENT=$BOOST_ROOT
    export BOOST_BUILD_PATH=$BOOST_CURRENT/tools/build
    export PATH=$PATH:$BOOST_CURRENT
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$BOOST_CURRENT/stage/lib
    export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:$BOOST_CURRENT/stage/lib
    alias bjamr='bjam variant=release address-model=64 architecture=ia64 threading=multi'
    alias bjamd='bjam variant=debug address-model=64 architecture=ia64 threading=multi'
    alias bjamr32='bjamr address-model=32 architecture=x86'
    alias bjamd32='bjamd address-model=32 architecture=x86'
fi

# set the path and setup shared libraries
export CPP_PROJECTS=$project_dir
alias cdcpp="cd $CPP_PROJECTS"

LD_LIBRARY_PATH=$project_dir/bin/release:$project_dir/bin/debug:$LD_LIBRARY_PATH
DYLD_LIBRARY_PATH=$project_dir/bin/release:$project_dir/bin/debug:$DYLD_LIBRARY_PATH
PATH=$PATH:$CPP_PROJECTS/bin/release
