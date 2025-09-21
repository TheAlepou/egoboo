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

/// @file idlib/game-engine/video/video.hpp
/// @brief Idlib: Game Engine - video master include file.

#pragma once

#include "blit.hpp"
#include "buffer.hpp"
#include "buffer_scoped_lock.hpp"
#include "camera.hpp"
#include "compare_function.hpp"
#include "color_blend/color_blend_equation.hpp"
#include "color_blend/color_blend_parameter.hpp"
#include "color_depth/rgb_depth.hpp"
#include "color_depth/rgba_depth.hpp"
#include "culling_mode.hpp"
#include "fill.hpp"
#include "get_pixel.hpp"
#include "image.hpp"
#include "index_buffer.hpp"
#include "index_descriptor.hpp"
#include "index_format.hpp"
#include "index_syntactics.hpp"
#include "pad.hpp"
#include "pixel_component_descriptor.hpp"
#include "pixel_format.hpp"
#include "power_of_two.hpp"
#include "primitive_type.hpp"
#include "rasterization_mode.hpp"
#include "set_pixel.hpp"
#include "texture_address_mode.hpp"
#include "texture_filter.hpp"
#include "texture_sampler.hpp"
#include "texture_type.hpp"
#include "vertex_buffer.hpp"
#include "vertex_component_descriptor.hpp"
#include "vertex_component_semantics.hpp"
#include "vertex_component_syntactics.hpp"
#include "vertex_descriptor.hpp"
#include "vertex_format.hpp"
#include "video_buffer_manager.hpp"
#include "viewport.hpp"
#include "winding_mode.hpp"
#include "window.hpp"
