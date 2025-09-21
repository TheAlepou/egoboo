///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Idlib: A C++ utility library
// Copyright (C) 2017-2018 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

/// @file idlib.hpp
/// @brief Master include file for idlib.
/// @author Michael Heilmann

#pragma once

#define IDLIB_PRIVATE 1

// CRTP.
#include "crtp.hpp"

// singleton.
#include "singleton.hpp"

// Text utilities.
#include "text.hpp"

// Define __ID_CURRENT_FILE__, __ID_CURRENT_LINE__ and __ID_CURRENT_FUNCTION__.
// Those constants will either be properly defined or not at all.
#include "CurrentFunction.inline"

// Debug library.
#include "debug.hpp"

// event library.
#include "event.hpp"

// utility library.
#include "utility.hpp"

// iterator range library.
#include "iterator_range.hpp"

// iterator library.
#include "iterator.hpp"

#undef IDLIB_PRIVATE
