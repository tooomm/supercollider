#!/bin/bash

# Runs the test suite in testsuite/classlibrary
# Tests in testsuite/classlibrary/server are ignored,
# as are tests for the UnitTesting Quark itself.

if "$SCLANG" -i none "$TRAVIS_BUILD_DIR/.travis/configureTestEnvironment.scd"
then
	echo "Configuration complete. Attempting to run unit tests now."
	sleep 3
	echo "Path: $TRAVIS_BUILD_DIR/.travis/runAllUnitTests.scd"
	"$SCLANG" -i none "$TRAVIS_BUILD_DIR/.travis/runAllUnitTests.scd"
	exit $?
else
	echo "Error while configuring test environment."
	exit 1
fi

