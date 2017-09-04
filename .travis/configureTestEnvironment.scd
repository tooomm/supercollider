/*
 * configureTestEnvironment.scd
 *
 * Grabs the UnitTesting Quark and configures the right
 * include/exclude paths to use for testing.
 *
 * Brian Heim, 2017-09-02
 */

try {
	~travisBuildDir = "TRAVIS_BUILD_DIR".getenv;
	Quarks.install("UnitTesting");
	LanguageConfig.addIncludePath(~travisBuildDir +/+ "testsuite/classlibrary");
	LanguageConfig.addExcludePath(~travisBuildDir +/+ "testsuite/classlibrary/server");
	LanguageConfig.addExcludePath(Quarks.folder +/+ "UnitTesting/tests");
	LanguageConfig.store(~travisBuildDir +/+ ".travis/sclang_conf.yaml");

	// wait 2 seconds to exit; this avoids a race condition of unknown cause that
	// sometimes causes sclang to abort with "terminate called without an active exception"
	r {
		2.wait;
		0.exit;
	}.play;
} { |e|
	e.reportError;
	1.exit;
};
