/* This file is part of HSPlasma.
 *
 * HSPlasma is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HSPlasma is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HSPlasma.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PLACTIVATORCONDITIONALOBJECT_H
#define _PLACTIVATORCONDITIONALOBJECT_H

#include "plConditionalObject.h"

class PLASMA_DLL plActivatorConditionalObject : public virtual plConditionalObject {
    CREATABLE(plActivatorConditionalObject, kActivatorConditionalObject,
              plConditionalObject)

protected:
    std::vector<plKey> fActivators;

public:
    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    const std::vector<plKey>& getActivators() const { return fActivators; }
    std::vector<plKey>& getActivators() { return fActivators; }
    void addActivator(plKey activator) { fActivators.push_back(activator); }
    void delActivator(size_t idx) { fActivators.erase(fActivators.begin() + idx); }
    void clearActivators() { fActivators.clear(); }
};


class PLASMA_DLL plActivatorActivatorConditionalObject : public virtual plActivatorConditionalObject {
    CREATABLE(plActivatorActivatorConditionalObject,
              kActivatorActivatorConditionalObject,
              plActivatorConditionalObject)
};


class PLASMA_DLL plVolActivatorConditionalObject : public virtual plActivatorConditionalObject {
    CREATABLE(plVolActivatorConditionalObject,
              kVolActivatorConditionalObject,
              plActivatorConditionalObject)
};

#endif
