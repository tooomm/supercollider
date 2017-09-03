#!/bin/bash

# Runs the test suite in testsuite/classlibrary
# Tests in testsuite/classlibrary/server are ignored,
# as are tests for the UnitTesting Quark itself.

# accommodate headless setup on Linux
if [[ "$TRAVIS_OS_NAME" == "linux" ]]
then
	export QT_PLATFORM_PLUGIN=offscreen
fi

if "$SCLANG" "$TRAVIS_BUILD_DIR/.travis/configureTestEnvironment.scd"
then
	"$SCLANG" "$TRAVIS_BUILD_DIR/.travis/runAllUnitTests.scd"
	exit $?
else
	echo "Error while configuring test environment."
	exit 1
fi

