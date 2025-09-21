///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Idlib: Game Engine
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

/// @file idlib/game-engine/video/viewport.cpp
/// @brief Abstract base class of all viewports.
/// @author Michael Heilmdefane IDLIB_TEMP_STUB_TYPES 1
#if IDLIB_TEMP_STUB_TYPES
#inn

#<cstdint>
namespace idlib {
    using single = float;
    struct color_3s {
        std::uint8_t r, g, b;
        static color_3s black() { return {0,0,0}; }
    };
    struct color_4s {
        std::uint8_t r, g, b, a;
        color_4s() : r(0), g(0), b(0), a(0) {}
        color_4s(const color_3s& c, std::uint8_t alpha) : r(c.r), g(c.g), b(c.b), a(alpha) {}
        color_4s(const color_3s& c, single alpha) : r(c.r), g(c.g), b(c.b), a(static_cast<std::uint8_t>(alpha * 255.0f)) {}
    };
    struct vec2s { single x, y; };
    struct rectangle_2s {
        vec2s min;
        vec2s max;
    };
}
#endif // IDLIB_TEMP_STUB_TYPES

#ifdef __cplusplus

#include "viewport.hpp"

namespace idlib {


viewport::viewport() :
    m_clear_color(color_3s::black(), 0.0f),
    m_color_clear_enabled(true),
    m_clear_depth(1.0f),
    m_depth_clear_enabled(true),
    m_relative_rectangle({0, 0}, {1, 1})
{}

viewport::~viewport()
{}


const color_4s& viewport::clear_color() const
{ return m_clear_color; }

void viewport::clear_color(const color_4s& clear_color)
{ m_clear_color = clear_color; }

bool viewport::color_clear_enabled() const
{ return m_color_clear_enabled; }

void viewport::color_clear_enabled(bool color_clear_enabled)
{ m_color_clear_enabled = color_clear_enabled; }


single viewport::clear_depth() const
{ return m_clear_depth; }

void viewport::clear_depth(single clear_depth)
{ m_clear_depth = clear_depth; }

bool viewport::depth_clear_enabled() const
{ return m_depth_clear_enabled; }

void viewport::depth_clear_enabled(bool depth_clear_enabled)
{ m_depth_clear_enabled = depth_clear_enabled; }


const rectangle_2s& viewport::relative_rectangle() const
{ return m_relative_rectangle; }

void viewport::relative_rectangle(const rectangle_2s& relative_rectangle)
{ m_relative_rectangle = relative_rectangle; }


} // namespace idlib
#endif
