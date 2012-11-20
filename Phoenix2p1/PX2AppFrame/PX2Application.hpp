/*
* Phoenix 3D ��Ϸ���� Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* �ļ�����	��	PX2WindowApplication.hpp
*
* �汾		:	1.0 (2011/02/02)
*
* ����		��	more
*
*/

#ifndef PX2WINDOWAPPLICATION_HPP
#define PX2WINDOWAPPLICATION_HPP

#include "PX2ApplicationBase.hpp"

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#ifdef PX2_USE_DX9
#include "PX2Dx9RendererInput.hpp"
#include "PX2Dx9RendererData.hpp"
#endif

#ifdef PX2_USE_OPENGLES2
#include "PX2OpenGLES2RendererInput.hpp"
#include "PX2OpenGLES2RendererData.hpp"
#endif

namespace PX2
{

#define PX2_DECLARE_APPLICATION(classname) \
	\
	static bool AppInitialize (); \
	static bool AppTerminate ();

#define PX2_REGISTER_APPLICATION(classname) \
	static bool gsAppInitializeRegistered_##classname = \
	classname::AppInitialize (); \
	static bool gsAppTerminnateRegistered_##classname = \
	classname::AppTerminate ();

#define PX2_IMPLEMENT_APPLICATION(classname) \
	\
	bool classname::AppInitialize () \
	{ \
		ApplicationBase::msAppInitlizeFun = &classname::AppInitialize; \
		ApplicationBase::msAppTernamateFun = &classname::AppTerminate; \
		ApplicationBase::msEntry = &Application::Entry; \
		msApplication = new classname(); \
		return true; \
	} \
	\
	bool classname::AppTerminate () \
	{ \
		delete (msApplication); \
		return true; \
	}
	//----------------------------------------------------------------------------

	class Application : public ApplicationBase
	{
	public:
		Application ();
		virtual ~Application ();

		static int Entry (int numArguments, char** arguments);

		virtual int Main (int numArguments, char** arguments);

		virtual bool OnInitlize ();
		virtual bool OnTernamate ();

	protected:
		// ���ڲ���
		std::string mWindowTitle;
		int mXPosition, mYPosition, mWidth, mHeight;
		bool mAllowResize;

#if defined(_WIN32) || defined(WIN32)
		// ����
		HWND mhWnd;
#endif

		RendererInput mInput;
	};

}

#endif