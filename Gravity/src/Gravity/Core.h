#pragma once

#ifdef GVT_PLATFORM_WINDOWS
	#ifdef GVT_BUILD_DLL
		#define GVT_API __declspec(dllexport)
	#else
		#define GVT_API __declspec(dllimport)
	#endif
#endif
