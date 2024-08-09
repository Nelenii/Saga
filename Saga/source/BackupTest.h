#pragma once



/*inline int operator | (EventCategory a, EventCategory b)
{
    return static_cast<int>(a) | static_cast<int>(b);
}*/

/*#define ENUM_CLASS_FLAGS(Enum) \
    inline           Enum& operator|=(Enum& Lhs, Enum Rhs) { return Lhs = (Enum)((underlying_type(Enum))Lhs | (underlying_type(Enum))Rhs); } \
    inline           Enum& operator&=(Enum& Lhs, Enum Rhs) { return Lhs = (Enum)((underlying_type(Enum))Lhs & (underlying_type(Enum))Rhs); } \
    inline           Enum& operator^=(Enum& Lhs, Enum Rhs) { return Lhs = (Enum)((underlying_type(Enum))Lhs ^ (underlying_type(Enum))Rhs); } \
    inline constexpr Enum  operator| (Enum  Lhs, Enum Rhs) { return (Enum)((underlying_type(Enum))Lhs | (underlying_type(Enum))Rhs); } \
    inline constexpr Enum  operator& (Enum  Lhs, Enum Rhs) { return (Enum)((underlying_type(Enum))Lhs & (underlying_type(Enum))Rhs); } \
    inline constexpr Enum  operator^ (Enum  Lhs, Enum Rhs) { return (Enum)((underlying_type(Enum))Lhs ^ (underlying_type(Enum))Rhs); } \
    inline constexpr bool  operator! (Enum  E)             { return !(underlying_type(Enum))E; } \
    inline constexpr Enum  operator~ (Enum  E)             { return (Enum)~(underlying_type(Enum))E; }*/
