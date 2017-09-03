#!/bin/bash

$TRAVIS_BUILD_DIR/.travis/lint.sh $TRAVIS_BUILD_DIR
if [[ -n "$1" && "$1" == "--qt=true" ]]; then
	source /opt/qt55/bin/qt55-env.sh
	cmake -DSC_EL=OFF -DCMAKE_INSTALL_PREFIX:PATH=$TRAVIS_BUILD_DIR/BUILD/Install -DCMAKE_BUILD_TYPE=Release $TRAVIS_BUILD_DIR --debug-output

	# start xvfb so sclang runs properly.
	# see https://docs.travis-ci.com/user/gui-and-headless-browsers/#Using-xvfb-to-Run-Tests-That-Require-a-GUI
	export QT_PLATFORM_PLUGIN=offscreen
	export DISPLAY=:99:0
	sh -e /etc/init.d/xvfb start
	sleep 3

else
	cmake -DSC_EL=OFF -DSC_QT=OFF -DSC_IDE=OFF -DCMAKE_INSTALL_PREFIX:PATH=$TRAVIS_BUILD_DIR/BUILD/Install -DCMAKE_BUILD_TYPE=Release $TRAVIS_BUILD_DIR --debug-output
fi
