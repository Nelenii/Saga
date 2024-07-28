#pragma once



#ifdef SAGA_PLATFORM_WINDOWS
	#ifdef SAGA_BUILD_DLL
		#define SAGA_API __declspec(dllexport)
	#else
		#define SAGA_API __declspec(dllimport)
	#endif
#else
	#error Saga only supports Windows.
#endif
