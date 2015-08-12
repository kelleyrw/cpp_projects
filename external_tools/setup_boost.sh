#!/bin/bash

echo '********************************************************************'
echo '*                         BOOST Setup                              *'
echo '********************************************************************'

install_path=${1:-/usr/local}
boost_version=${2:-1.58.0}
boost_dest=${install_path}/boost/${boost_version}
boost_version_name=boost_$(echo $boost_version | sed s/\\./_/g)
 
echo installing boost $boost_version to $boost_dest
if [ -e $boost_dest ]; then
    echo BOOST $boost_version already exists!!  Skipping!
else
    if [ ! -d ${boost_dest} ]; then
        echo creating ${install_path}/boost
        mkdir -p ${install_path}/boost
    fi
    wget http://sourceforge.net/projects/boost/files/boost/${boost_version}/${boost_version_name}.tar.gz/download \
        -O ${boost_version_name}.tar.gz
    tar -xzf ${boost_version_name}.tar.gz
    mv ${boost_version_name} $boost_dest
    pushd $boost_dest
    ./bootstrap.sh
    ./b2 -j 20 
    popd
    rm ${boost_version_name}.tar.gz
fi

