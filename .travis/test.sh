#!/bin/bash

# get the location of the sclang executable
if [[ $TRAVIS_OS_NAME == linux ]]; then
	export SCLANG=$TRAVIS_BUILD_DIR/BUILD/Install/bin/sclang
else
	export SCLANG=$TRAVIS_BUILD_DIR/BUILD/Install/SuperCollider/SuperCollider.app/Contents/MacOS/sclang
fi

# steps needed to make non-Qt builds work
if [[ $QT != true ]]; then $TRAVIS_BUILD_DIR/.travis/fix-non-Qt.sh; fi

# test that sclang at least boots and interprets
$TRAVIS_BUILD_DIR/testsuite/sclang/launch_test.py $SCLANG

# launch the test suite through qpm
if [[ $QT == true ]]; then $TRAVIS_BUILD_DIR/.travis/qpm-test.sh; fi
