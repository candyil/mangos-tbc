/*
* This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "Spells/Scripts/SpellScript.h"
#include "Spells/SpellAuras.h"

struct EarthShield : public AuraScript
{
    int32 OnAuraValueCalculate(AuraCalcData& data, int32 value) const override
    {
        Unit* target = data.target;
        if (Unit* caster = data.caster)
        {
            value = caster->SpellHealingBonusDone(target, data.spellProto, value, SPELL_DIRECT_DAMAGE);
            value = target->SpellHealingBonusTaken(caster, data.spellProto, value, SPELL_DIRECT_DAMAGE);
        }
        return value;
    }
};

void LoadShamanScripts()
{
    RegisterSpellScript<EarthShield>("spell_earth_shield");
}