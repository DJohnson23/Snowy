#pragma once

#ifdef SN_PLATFORM_WINDOWS
	#ifdef SN_BUILD_DLL
		#define SNOWY_API __declspec(dllexport)
	#else
		#define SNOWY_API __declspec(dllimport)
	#endif
#else
	#error Snowy only supports Windows!
#endif

#define BIT(x) (1 << x)