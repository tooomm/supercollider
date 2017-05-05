/**
 *  \file SC_Codecvt.hpp
 *
 *  \brief Conversion between UTF-8 and native filesystem encoding.
 *
 *  The purpose of this file is to make it transparent to pass UTF-16
 *  strings to the Windows NT filesystem and hide all the #ifdefing
 *  from normal use. Because strings in sclang are represented as type
 *  char*, we have to convert twice on Windows: once to std::wstring, then
 *  again to std::string. At least, the author could not find a simpler way.
 *  Another option would be to bring in boost.locale's "between" conversion func.
 *
 *  On non-Windows platforms, this simply performs identity conversion.
 *
 *  \version 1.0
 *
 *  \date 2017-05-03
 *
 *  \author Brian Heim <brianlheim@gmail.com>
 */
/*
	Copyright (C) 2017 Brian Heim.

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <boost/filesystem/path.hpp> // path
#include <string> // string

namespace SC_Codecvt {

    /// Converts from path (native encoding) to UTF-8 string
    boost::filesystem::path to_path(const std::string& s);

    /// Converts from UTF-8 string to path (native encoding)
    std::string from_path(const boost::filesystem::path& p);

    /// Converts from UTF-8 string to string in filesystem's native encoding
    std::string to_filesys_encoding(const std::string& s);

    /// Converts from string in filesystem's native encoding to UTF-8 string
    std::string from_filesys_encoding(const std::string& s);

} // SC_Codecvt
