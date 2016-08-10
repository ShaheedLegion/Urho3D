//
// Copyright (c) 2008-2016 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifdef URHO3D_URHO2D

#include "../../Precompiled.h"

#include "../../Graphics/Texture2D.h"
#include "../../Urho2D/Sprite2D.h"
#include "../../Urho2D/SpriteSheet2D.h"
#include "../../LuaScript/LuaScriptUtils.h"

#include <kaguya.hpp>

namespace Urho3D
{

KAGUYA_MEMBER_FUNCTION_OVERLOADS(SpriteSheet2DDefineSprite, SpriteSheet2D, DefineSprite, 2, 4);

void RegisterSpriteSheet2D(kaguya::State& lua)
{
    using namespace kaguya;

    // [Class] SpriteSheet2D : Resource
    lua["SpriteSheet2D"].setClass(UserdataMetatable<SpriteSheet2D, Resource>()
        // [Constructor] SpriteSheet2D()
        .addStaticFunction("new", &CreateObject<SpriteSheet2D>)

        // [Method] void SetTexture(Texture2D* texture)
        .addFunction("SetTexture", &SpriteSheet2D::SetTexture)

        // [Method] void DefineSprite(const String& name, const IntRect& rectangle, const Vector2& hotSpot = Vector2(0.5f, 0.5f),
        .addFunction("DefineSprite", SpriteSheet2DDefineSprite())

        // [Method] Texture2D* GetTexture() const
        .addFunction("GetTexture", &SpriteSheet2D::GetTexture)
        // [Method] Sprite2D* GetSprite(const String& name) const
        .addFunction("GetSprite", &SpriteSheet2D::GetSprite)

        // [Property] Texture2D* texture
        .addProperty("texture", &SpriteSheet2D::GetTexture, &SpriteSheet2D::SetTexture)
    );
}
}

#endif