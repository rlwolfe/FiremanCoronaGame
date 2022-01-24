#pragma once
//--------------------include Section --------------------
#include "StaticObject.h"

//--------------------Objects Class definition --------------------
class WoodWall : public StaticObject
{
public:
	using StaticObject::StaticObject;
	WoodWall();
	~WoodWall() = default;

private:
};