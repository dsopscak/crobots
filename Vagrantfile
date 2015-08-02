# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure(2) do |config|
  config.vm.box = "centos66-x86_64"
  config.vm.box_url = "https://github.com/dsopscak/vagrant-centos/releases/download/v6.6.1/centos66-x86_64-20141207.box"

  config.vm.hostname = 'crobots'

  config.vm.provision "shell",
      path: "./vagrant/bootstrap.sh",
      privileged: false

end


