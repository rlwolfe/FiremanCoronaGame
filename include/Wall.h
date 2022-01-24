#pragma once
//--------------------include Section --------------------
#include "StaticObject.h"

//--------------------Objects Class definition --------------------
class Wall : public StaticObject
{
public:
	using StaticObject::StaticObject;
	Wall();
	~Wall() = default;

private:

};