/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2StringHelp.hpp
*
* 版本		:	1.0 (2011/01/29)
*
* 作者		：	more
*
*/

#ifndef PX2STRINGHELP_HPP
#define PX2STRINGHELP_HPP

#include "PX2CorePre.hpp"
#include "PX2Ascii.hpp"

namespace PX2
{

	class StringHelp
	{
	public:
		static bool Initlize();

		// 将文件路径标准化（将"\\"换成'/'）, 如果末尾没有'/',添加'/'
		static std::string StandardisePath (const std::string &path);

		/// 将文件路径拆成文件夹名和文件名
		/**
		* 例如"E:\\Phoenix\\Data\\Tdtf\\Normal.tdtf"拆成的结果为
		* outPath = "E:/Phoenix/Data//Tdtf/"
		* outBaseFileName = "Normal.tdtf"
		*/
		static void SplitFilename (const std::string &fullName,
			std::string &outPath, std::string &outBaseFileName);

		/// 将文件名拆成文件名称和扩展名
		/**
		* 例如"Normal.tdtf"拆成的结果为
		* outBaseName = "Normal"
		* outExtention = "tdtf"
		*/
		static void SplitBaseFilename (const std::string &baseFileName,
			std::string &outBaseName, std::string &outExtention);

		/// 将文件路径拆成文件夹名，文件名称和扩展名称
		static void SplitFullFilename (const std::string &fullName,
			std::string &outPath, std::string &outBaseName, 
			std::string &outExtention);

		static int UnicodeToAnsi (char *dest, int maxChar, const wchar_t *src,
			int numSrcChar=-1);
		static int AnsiToUnicode (wchar_t *dest, int maxChar, const char *src, 
			int numSrcChar=-1);
		static int UnicodeToUTF8 (char *destBuf, int maxChar, const wchar_t *src, 
			int numSrcChar=-1);
		static int UTF8ToUnicode (wchar_t *destBuf, int maxChar, const char *src, 
			int numSrcChar=-1);

		static const char *UnicodeToAnsi (const wchar_t *src, int numSrcChar=-1);
		static wchar_t *AnsiToUnicode (const char *src, int numSrcChar=-1);
		static const char *UnicodeToUTF8( const wchar_t *src, int numSrcChar=-1);
		static const wchar_t *UTF8ToUnicode( const char *src, int numSrcChar=-1);

		static std::string IntToString (int val);
		static std::string FloatToString (float val);

		// Hash
		static unsigned int Hash(const std::string &str, unsigned int type);
		static unsigned int Hash(const char *str, unsigned int type,
			int length=-1); //< 如果length<0,表示传入的字符串是已\0结尾
	};

	//----------------------------------------------------------------------------
	template <class S>
	S ToUpper(const S& str)
	{
		typename S::const_iterator it  = str.begin();
		typename S::const_iterator end = str.end();

		S result;
		result.reserve(str.size());
		while (it != end) result += Ascii::ToUpper(*it++);
		return result;
	}
	//----------------------------------------------------------------------------
	template <class S>
	S& ToUpperInPlace(S& str)
	{
		typename S::iterator it  = str.begin();
		typename S::iterator end = str.end();

		while (it != end) { *it = Ascii::ToUpper(*it); ++it; }
		return str;
	}
	//----------------------------------------------------------------------------
	template <class S>
	S ToLower(const S& str)
	{
		typename S::const_iterator it  = str.begin();
		typename S::const_iterator end = str.end();

		S result;
		result.reserve(str.size());
		while (it != end) result += Ascii::ToLower(*it++);
		return result;
	}
	//----------------------------------------------------------------------------
	template <class S>
	S& ToLowerInPlace(S& str)
	{
		typename S::iterator it  = str.begin();
		typename S::iterator end = str.end();

		while (it != end) { *it = Ascii::ToLower(*it); ++it; }
		return str;
	}
	//----------------------------------------------------------------------------

}

#endif