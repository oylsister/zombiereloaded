/*
 * ============================================================================
 *
 *  Zombie:Reloaded
 *
 *  File:          ztele/cvars.inc
 *  Type:          Module Component
 *  Description:   Console variables for ZTele.
 *
 *  Copyright (C) 2009-2015  Greyscale, Richard Helgeby
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ============================================================================
 */

Handle ZTeleCvar_Zombie;
Handle ZTeleCvar_HumanBefore;
Handle ZTeleCvar_HumanAfter;
Handle ZTeleCvar_DelayZombie;
Handle ZTeleCvar_DelayHuman;
Handle ZTeleCvar_MaxZombie;
Handle ZTeleCvar_MaxHuman;
Handle ZTeleCvar_AutoCancel;
Handle ZTeleCvar_AutoCancelDistance;

void ZTeleOnCvarsCreate()
{
    ZTeleCvar_Zombie                = CreateConVar("zr_ztele_zombie",               "1",    "Allow zombies to use ZTele.");
    ZTeleCvar_HumanBefore           = CreateConVar("zr_ztele_human_before",         "1",    "Allow humans to use ZTele before the mother zombie has spawned.");
    ZTeleCvar_HumanAfter            = CreateConVar("zr_ztele_human_after",          "1",    "Allow humans to use ZTele after the mother zombie has spawned.");
    ZTeleCvar_DelayZombie           = CreateConVar("zr_ztele_delay_zombie",         "3.0",  "Time between using ZTele command and teleportation for zombies. [Dependency: zr_ztele_zombie]");
    ZTeleCvar_DelayHuman            = CreateConVar("zr_ztele_delay_human",          "3.0",  "Time between using ZTele command and teleportation for humans. [Dependency: zr_ztele_human_(before)/(after)]");
    ZTeleCvar_MaxZombie             = CreateConVar("zr_ztele_max_zombie",           "3",    "Max number of times a zombie is allowed to use ZTele per round. [Dependency: zr_ztele_zombie]");
    ZTeleCvar_MaxHuman              = CreateConVar("zr_ztele_max_human",            "1",    "Max number of times a human is allowed to use ZTele per round. [Dependency: zr_ztele_human_(before)/(after)]");
    ZTeleCvar_AutoCancel            = CreateConVar("zr_ztele_autocancel",           "1",    "Automatically cancel ZTele if player moves out of a set boundary. [Dependency: zr_ztele_(zombie)/(human)[_(before)/(after)]]");
    ZTeleCvar_AutoCancelDistance    = CreateConVar("zr_ztele_autocancel_distance",  "20",   "Maximum distance, in feet, player is allowed to travel before teleport is cancelled. [Dependency: zr_ztele_autocancel]");
}

bool ZTeleZombieCanTeleport()
{
    return GetConVarBool(ZTeleCvar_Zombie);
}

bool ZTeleHumanCanTeleportBeforeInfection()
{
    return GetConVarBool(ZTeleCvar_HumanBefore);
}

bool ZTeleHumanCanTeleportAfterInfection()
{
    return GetConVarBool(ZTeleCvar_HumanAfter);
}

int ZTeleGetZombieDelay()
{
    return GetConVarInt(ZTeleCvar_DelayZombie);
}

int ZTeleGetHumanDelay()
{
    return GetConVarInt(ZTeleCvar_DelayHuman);
}

int ZTeleGetZombieLimit()
{
    return GetConVarInt(ZTeleCvar_MaxZombie);
}

int ZTeleGetHumanLimit()
{
    return GetConVarInt(ZTeleCvar_MaxHuman);
}

bool ZTeleIsAutoCancelEnabled()
{
    return GetConVarBool(ZTeleCvar_AutoCancel);
}

float ZTeleGetAutoCancelDistance()
{
    return GetConVarFloat(ZTeleCvar_AutoCancelDistance);
}