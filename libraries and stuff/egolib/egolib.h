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

/// @file  egolib/egolib.h
/// @brief All-in-one header file.

#pragma once

#include "App.hpp"

#include "Audio/AudioSystem.hpp"

//--------------------------------------------------------------------------------------------

#include "Core/StringUtilities.hpp"
#include "Core/System.hpp"
#include "Core/QuadTree.hpp"

//--------------------------------------------------------------------------------------------

#include "Logic/Attribute.hpp"
#include "Logic/PerkHandler.hpp"
#include "Logic/ObjectSlot.hpp"

//--------------------------------------------------------------------------------------------

#include "bbox.h"
#include "Clock.hpp"
#include "egoboo_setup.h"
#include "endian.h"
#include "file_common.h"
#include "fileutil.h"
#include "font_bmp.h"
#include "frustum.h"
#include "map_functions.h"
#include "platform.h"
#include "egoboo_setup.h"
#include "strutil.h"
#include "Time/Time.hpp"
#include "typedef.h"

//--------------------------------------------------------------------------------------------

#include "InputControl/InputSystem.hpp"

//--------------------------------------------------------------------------------------------

#include "Image/ImageManager.hpp"

//--------------------------------------------------------------------------------------------

#include "vfs.h"
#include "VFS/FsPath.hpp"
#include "VFS/VfsPath.hpp"

//--------------------------------------------------------------------------------------------

#include "_math.h"
#include "Math/_Include.hpp"

//--------------------------------------------------------------------------------------------

#include "AI/AStar.hpp"
#include "AI/LineOfSight.hpp"

//--------------------------------------------------------------------------------------------

#include "Time/LocalTime.hpp"
#include "Time/SlidingWindow.hpp"
#include "Time/Stopwatch.hpp"

//--------------------------------------------------------------------------------------------

#include "Graphics/FontManager.hpp"
#include "Graphics/Font.hpp"
#include "Graphics/TextureManager.hpp"
#include "Graphics/PixelFormat.hpp"
#include "Graphics/ModelDescriptor.hpp"
#include "Graphics/FontManager.hpp"
#include "Graphics/GraphicsWindow.hpp"
#include "Graphics/GraphicsSystem.hpp"
#include "Graphics/GraphicsSystemNew.hpp"
#include "Graphics/Display.hpp"
#include "Graphics/DisplayMode.hpp"

#include "Image/ImageManager.hpp"

//--------------------------------------------------------------------------------------------

#include "Renderer/Renderer.hpp"
#include "Renderer/DeferredTexture.hpp"

//--------------------------------------------------------------------------------------------

#include "Log/_Include.hpp"

//--------------------------------------------------------------------------------------------

#include "Profiles/_Include.hpp"

//--------------------------------------------------------------------------------------------

#include "FileFormats/id_md2.h"
#include "FileFormats/map_file.h"
#include "FileFormats/map_tile_dictionary.h"
#include "FileFormats/SpawnFile/spawn_file.h"
#include "FileFormats/template.h"
#include "FileFormats/wawalite_file.h"

//--------------------------------------------------------------------------------------------

#include "Console/Console.hpp"
