#!/bin/bash
#
# bootstrap.sh
#

git clone https://github.com/dsopscak/basic_env.git
./basic_env/useit.sh -f
. ~/.bashrc

mkdir provision
cd provision
rsync -r /vagrant/* --exclude vagrant --exclude Vagrantfile .
git clone https://github.com/dsopscak/provision-helper.git
ln -s provision-helper/vagrant_helper.sh helper.sh
ppath $(pwd)/provision-helper

./setup.sh
