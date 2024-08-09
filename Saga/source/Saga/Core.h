#pragma once

#include <cstdint>



typedef std::int8_t     int8;
typedef std::int16_t    int16;
typedef std::int32_t    int32;
typedef std::int64_t    int64;

typedef std::uint8_t    uint8;
typedef std::uint16_t   uint16;
typedef std::uint32_t   uint32;
typedef std::uint64_t   uint64;

//typedef std::string     string;



#ifdef SAGA_PLATFORM_WINDOWS
	#ifdef SAGA_BUILD_DLL
		#define SAGA_API __declspec(dllexport)
	#else
		#define SAGA_API __declspec(dllimport)
	#endif
#else
	#error Saga only supports Windows.
#endif




#define GENERATE_ENUM_CLASS_FLAGS_OPERATORS(enu) \
	inline constexpr	enu operator ~ (enu e) { return (enu)~(std::underlying_type_t<enu>(e)); } \
	inline constexpr	enu operator | (enu lhs, enu rhs) { return (enu)(std::underlying_type_t<enu>(lhs) | std::underlying_type_t<enu>(rhs)); } \
	inline constexpr	enu operator & (enu lhs, enu rhs) { return (enu)(std::underlying_type_t<enu>(lhs) & std::underlying_type_t<enu>(rhs)); } \
	inline constexpr	enu operator ^ (enu lhs, enu rhs) { return (enu)(std::underlying_type_t<enu>(lhs) ^ std::underlying_type_t<enu>(rhs)); } \
	inline				enu& operator |= (enu& lhs, enu rhs) { return lhs = (enu)(std::underlying_type_t<enu>(lhs) | std::underlying_type_t<enu>(rhs)); } \
	inline				enu& operator &= (enu& lhs, enu rhs) { return lhs = (enu)(std::underlying_type_t<enu>(lhs) & std::underlying_type_t<enu>(rhs)); } \
	inline				enu& operator ^= (enu& lhs, enu rhs) { return lhs = (enu)(std::underlying_type_t<enu>(lhs) ^ std::underlying_type_t<enu>(rhs)); } \
	inline constexpr	bool operator ! (enu e) { return !std::underlying_type_t<enu>(e); }
