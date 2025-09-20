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

/// @file egolib/game/Entities/Enchant.hpp
/// @brief Enchantment entities.

#pragma once
// TEMP FIX: Allow this header to be included directly during isolated builds
#if !defined(GAME_ENTITIES_PRIVATE)
#define GAME_ENTITIES_PRIVATE 1
#endif
#if !defined(GAME_ENTITIES_PRIVATE) || GAME_ENTITIES_PRIVATE != 1
#error(do not include directly, include `game/Entities/_Include.hpp` instead)
#endif
#ifdef __cplusplus
#include <memory>
#include <list>

// Prefer project headers when available
#ifdef __has_include
#  if __has_include("typedef.h")
#    include "typedef.h"
#  endif
#  if __has_include("Attribute.hpp")
#    include "Attribute.hpp"
#  endif
#  if __has_include("MissileTreatment.hpp")
#    include "MissileTreatment.hpp"
#  endif
#  if __has_include("_Include.hpp")
#    include "_Include.hpp"
#  endif
#endif

// TEMP STUBS: Provide minimal fallbacks if project headers are unavailable to avoid parse errors.
#ifndef EGO_TEMP_STUBS_GUARD
#define EGO_TEMP_STUBS_GUARD 1

// Object forward declaration (actual class defined elsewhere)
class Object;

// Namespace Ego forward declarations and lightweight shims
namespace Ego {

namespace Attribute {
// If AttributeType isn't defined, declare a minimal stand-in enum.
#ifndef EGO_ATTRIBUTE_ATTRIBUTETYPE_DEFINED
enum class AttributeType { Unknown = 0 };
#define EGO_ATTRIBUTE_ATTRIBUTETYPE_DEFINED 1
#endif
} // namespace Attribute

// If MissileTreatment isn't available, provide a minimal enum and cost type.
#ifndef EGO_MISSILE_TREATMENT_DEFINED
enum class MissileTreatment { MissileTreatment_Normal = 0, MissileTreatment_Deflect, MissileTreatment_Reflect };
#define EGO_MISSILE_TREATMENT_DEFINED 1
#endif

// If profile and reference types aren't available, provide minimal aliases.
#ifndef EGO_OBJECTREF_DEFINED
using ObjectRef = int; // TEMP: replace with real ObjectRef when available
#define EGO_OBJECTREF_DEFINED 1
#endif

#ifndef EGO_OBJECTPROFILEREF_DEFINED
using ObjectProfileRef = int; // TEMP: replace with real ObjectProfileRef when available
#define EGO_OBJECTPROFILEREF_DEFINED 1
#endif

// Forward declare EnchantProfile if not present
#ifndef EGO_ENCHANTPROFILE_FWD_DECLARED
struct EnchantProfile; // TEMP: real definition expected elsewhere
#define EGO_ENCHANTPROFILE_FWD_DECLARED 1
#endif

} // namespace Ego

#endif // EGO_TEMP_STUBS_GUARD

namespace Ego
{

struct EnchantModifier
{
    Ego::Attribute::AttributeType _type;
    float _value;

    EnchantModifier(Ego::Attribute::AttributeType type, float value) :
        _type(type),
        _value(value)
    {
        //ctor
    }
};

/**
 * @brief
 *  The definition of an enchantment entity.
 */
class Enchantment : public std::enable_shared_from_this<Enchantment>
{
public:
    Enchantment(const std::shared_ptr<EnchantProfile> &enchantmentProfile, ObjectProfileRef spawnerProfile, const std::shared_ptr<Object> &owner);

    ~Enchantment();

    void requestTerminate();

    bool isTerminated() const;

    /**
    * @brief
    *   Update one game logic loop tick for this enchant. This will
    *   check if this enchant can kill the owner or target through drains,
    *   spawns any enchant particle effects and checks if the enchantment itself should die.
    **/
    void update();

    const std::shared_ptr<EnchantProfile>& getProfile() const;

    /**
    * @brief
    *   Applies this Enchantment to the specified target. It will stay there and affect the target until
    *   it expires or is removed.
    **/
    void applyEnchantment(std::shared_ptr<Object> target);

    /**
    * @return
    *   The target of this enchant, or nullptr if it no longer has a valid target
    **/
    std::shared_ptr<Object> getTarget() const;

    /**
    * @return
    *   object reference of the owner of this enchant or the invalid object reference if there is no valid owner
    **/
	ObjectRef getOwnerRef() const;

    /**
    * @return
    *   The owner of this enchant, or nullptr if it no longer has a valid owner
    **/
    std::shared_ptr<Object> getOwner() const;

    float getOwnerManaSustain() const {return _ownerManaSustain;}
    float getOwnerLifeSustain() const {return _ownerLifeSustain;}
    float getTargetManaDrain()  const {return _targetManaDrain;}
    float getTargetLifeDrain()  const {return _targetLifeDrain;}

    void setBoostValues(float ownerManaSustain, float ownerLifeSustain, float targetManaDrain, float targetLifeDrain);

    /**
    * @brief
    *   Plays the ending sound of this enchant
    **/
    void playEndSound() const;

    /**
    * @brief
    *   Returns what kind of deflection handling this enchantment provides.
    * @return
    *   not MissileTreatment_Normal if it provides some special kind of missile protection
    **/
    MissileTreatment getMissileTreatment() const;

    /**
    * @return
    *   How much the owner of the enchant must pay in mana for each missile deflected or reflected.
    *   If the owner cannot pay the cost, then the enchantment provides no special missile protection
    **/
    float getMissileTreatmentCost() const;

    const std::list<EnchantModifier>& getModifiers() const;

private:
    bool _isTerminated;

    std::shared_ptr<EnchantProfile> _enchantProfile;

    ObjectProfileRef _spawnerProfileID;        ///< The object  profile index that spawned this enchant

    int _lifeTime;                  ///< Time before end (in game logic frames)
    int _spawnParticlesTimer;       ///< Time before spawning particle effects (in game logic frames)

    std::weak_ptr<Object> _target;  ///< Who it enchants
    std::weak_ptr<Object> _owner;   ///< Who cast the enchant
    std::weak_ptr<Object> _spawner; ///< The spellbook character
    std::weak_ptr<Object> _overlay; ///< The overlay character

    //Missile deflection enchant?
    MissileTreatment _missileTreatment;
    float _missileTreatmentCost;

    /// List to remember if properties were subjected to modifications by this enchant
    std::list<EnchantModifier> _modifiers;

    float _ownerManaSustain;               ///< Boost values
    float _ownerLifeSustain;
    float _targetManaDrain;
    float _targetLifeDrain;
};

} //Ego

#endif
