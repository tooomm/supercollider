#!/bin/bash

# Runs the test suite in testsuite/classlibrary
# Tests in testsuite/classlibrary/server are ignored,
# as are tests for the UnitTesting Quark itself.

# accommodate headless setup on Linux
# copied from testsuite/sclang/launch_test.py
if [[ "$TRAVIS_OS_NAME" == "linux" ]]
then
	export QT_PLATFORM_PLUGIN=offscreen
	export DISPLAY=:99:0
	sh -e /etc/init.d/xvfb start
	/sbin/start-stop-daemon --start --quiet --pidfile /tmp/custom_xvfb_99.pid --make-pidfile --background --exec /usr/bin/Xvfb -- :99 -ac -screen 0 1280x1024x16
fi

if "$SCLANG" "$TRAVIS_BUILD_DIR/.travis/configureTestEnvironment.scd"
then
	"$SCLANG" "$TRAVIS_BUILD_DIR/.travis/runAllUnitTests.scd"
	exit $?
else
	echo "Error while configuring test environment."
	exit 1
fi

