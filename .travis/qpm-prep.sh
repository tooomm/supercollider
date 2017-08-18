#!/bin/bash

# checkout qpm from scztt's repo
cd $TRAVIS_BUILD_DIR/BUILD
sudo pip install git+https://github.com/scztt/qpm.git@qpm-unit

# install CommonTests, CommonTestsGUI
qpm quark checkout CommonTests CommonTestsGUI --location $HOME/Quarks

# move the config file into the build directory
cp ../travis_test_run_proto.json ./travis_test_run.json
