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

/// @file egolib/Log/_Include.hpp
/// @details Basic logging system

#pragma once

#pragma once

#define GAME_ENTITIES_PRIVATE 1
#include "Enchant.hpp"
#include "Particle.hpp"
#include "ParticleHandler.hpp"
#include "Object.hpp"
#include "ObjectHandler.hpp"
#undef GAME_ENTITIES_PRIVATE


#define EGOLIB_PROFILES_PRIVATE 1
#include "EnchantProfile.hpp"
#include "EnchantProfileWriter.hpp"
#include "GenderProfile.hpp"
#include "ParticleProfile.hpp"
#include "ParticleProfileWriter.hpp"
#include "RandomName.hpp"
#include "ModuleProfile.hpp"
#include "ObjectProfile.hpp"
#include "ProfileSystem.hpp"
#undef EGOLIB_PROFILES_PRIVATE

#define EGOLIB_MATH_PRIVATE 1

//
#include "Math.hpp"
#include "Random.hpp"
#include "Standard.hpp"
#include "VectorProjection.hpp"
#include "VectorRejection.hpp"

#undef EGOLIB_MATH_PRIVATE


#define EGOLIB_LOG_PRIVATE 1
#include "Entry.hpp"
#include "Target.hpp"
#include "Level.hpp"

namespace Log {

	/**
	 * @brief
	 *  Initialize the logging system.
	 * @param filename
	 *  the file name
	 * @param level
	 *  the level
	 * @return
	 *  Returns if the logging system is already initialized.
	 * @throw std::runtime_error
	 *  if initialization fails
	 */
	void initialize(const std::string& filename, Level level);

	/**
	 * @brief
	 *  Uninitialize the logging system
	 * @remark
	 *  Returns if the logging system is not initialized.
	 */
	void uninitialize();

	/**
	 * @brief
	 *  Get the default target.
	 * @return
	 *  the default target
	 * @throw std::logic_error
	 *  if the logging system is not initialized
	 */
	Target& get();

} // namespace Log
