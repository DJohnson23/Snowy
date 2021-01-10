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

#ifdef SN_DEBUG
	#define SN_ENABLE_ASSERTS
#endif

#ifdef SN_ENABLED_ASSERTS
	#define SN_ASSERT(x, ...) { if(!(x)) { SN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SN_CORE_ASSERT(x, ...) { if(!(x)) { SN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SN_ASSERT(x, ...)
	#define SN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)