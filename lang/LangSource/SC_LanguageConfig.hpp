/*
 *  Copyright 2003 Maurizio Umberto Puxeddu <umbpux@tin.it>
 *  Copyright 2011 Jakob Leben
 *
 *  This file is part of SuperCollider.
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 *
 */

#ifndef SC_LANGUAGECONFIG_HPP_INCLUDED
#define SC_LANGUAGECONFIG_HPP_INCLUDED

#include <vector>
#include <string>
#include <boost/filesystem/path.hpp>

class SC_LanguageConfig;
extern SC_LanguageConfig* gLanguageConfig;

class SC_LanguageConfig
{
public:
	typedef boost::filesystem::path Path;
	typedef std::vector<Path>	DirVector;

	SC_LanguageConfig(bool standalone);

	const DirVector& includedDirectories() const { return mIncludedDirectories; }
	const DirVector& excludedDirectories() const { return mExcludedDirectories; }

	void postExcludedDirectories(void) const;

	bool pathIsExcluded         (const Path&) const; // true iff the path is in mExcludedDirectories

	bool addIncludedDirectory   (const Path&); // false iff the path was already in the vector
	bool addExcludedDirectory   (const Path&);

	bool removeIncludedDirectory(const Path&); // false iff there was nothing to remove
	bool removeExcludedDirectory(const Path&);

	bool forEachIncludedDirectory(bool (*)(const Path&, int)) const;

	static bool readLibraryConfigYAML (const Path&, bool standalone);
	static bool writeLibraryConfigYAML(const Path&);
	static void freeLibraryConfig     ();
	static bool defaultLibraryConfig  (bool standalone);
	static bool readLibraryConfig     (bool standalone);

	static const bool getPostInlineWarnings() { return gPostInlineWarnings; }
	static const void setPostInlineWarnings(bool b) { gPostInlineWarnings = b; }
	static const Path& getConfigPath() { return gConfigFile; }
	static const void setConfigPath(const Path& p) { gConfigFile = p; }

	static const std::string& getIdeName() { return gIdeName; }
	static const void setIdeName(const std::string& s) { gIdeName = s; }
	static const bool usingIde() { return !gIdeName.empty(); }

private:
	static const bool findPath(const DirVector&, const Path&);
	static const bool addPath(DirVector&, const Path&);
	static const bool removePath(DirVector&, const Path&);

	DirVector mIncludedDirectories;
	DirVector mExcludedDirectories;
	DirVector mDefaultClassLibraryDirectories;
	static Path gConfigFile;
	static std::string gIdeName;
	static bool gPostInlineWarnings;
};

#endif // SC_LANGUAGECONFIG_HPP_INCLUDED
