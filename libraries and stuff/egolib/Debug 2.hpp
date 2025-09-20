//********************************************************************************************
//*
//*    This file is part of Egoboo.
//*
//*    Egoboo is free software: you can redistribute it and/or modify it
//*    under the terms of the GNU General Public License as published by
//*    the Free Software Foundation, either version 3 of the License, or
//*    (at your option) any later version.
//*
//*    Egoboo is distributed in the hope that it will be useful, but
//*    WITHOUT ANY WARRANTY; without even the implied warranty of
//*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*    General Public License for more details.
//*
//*    You should have received a copy of the GNU General Public License
//*    along with Egoboo.  If not, see <http://www.gnu.org/licenses/>.
//*
//********************************************************************************************

/// @file egolib/Debug.hpp
/// @brief Miscellaneous Debug Utilities

#pragma once

#ifdef __cplusplus

#include "platform.hpp"
// Try to include <type_traits>; provide a tiny fallback if it's unavailable.
#if defined(__has_include)
  #if __has_include(<type_traits>)
    #include <type_traits>
  #else
    // Minimal fallback for remove_const and remove_reference
    namespace std {
        template <class T> struct remove_const { using type = T; };
        template <class T> struct remove_const<const T> { using type = T; };
        template <class T> struct remove_reference { using type = T; };
        template <class T> struct remove_reference<T&> { using type = T; };
        template <class T> struct remove_reference<T&&> { using type = T; };
    }
  #endif
#else
  // Older compilers without __has_include: try the include and hope for the best.
  #include <type_traits>
#endif

namespace Ego {
namespace Debug {
#ifdef _DEBUG

/**
 * @remark
 *	Validation functionality via template specialization.
 *  See the specialization for Ego::Math::Vector for an example.
 * @brief
 *	Assert that an object is valid.
 * @param object
 *	the object
 * @post
 *	If the object is not valid, an error is logged.
 */
template <typename ... T>
struct Validate;

template <typename T>
using MakeValidate = Validate<typename std::remove_const<typename std::remove_reference<T>::type>::type>;

#endif
#ifdef _DEBUG
    #define EGO_DEBUG_VALIDATE(_object_) { \
        Ego::Debug::MakeValidate<decltype(_object_)> validate; \
        validate(__FILE__, __LINE__, _object_); \
    }
#else
    #define EGO_DEBUG_VALIDATE(_object_)
#endif
    }
}

#else
// If included from non-C++ (e.g., compiled as C/Obj-C), provide a harmless no-op macro.
#ifndef EGO_DEBUG_VALIDATE
  #define EGO_DEBUG_VALIDATE(_object_)
#endif
#endif // __cplusplus
