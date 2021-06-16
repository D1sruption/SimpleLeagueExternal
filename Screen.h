#pragma once

#include <Windows.h>
#include "Vector.h"
#include "Matrix.h"
#include "Offsets.h"
#include "main.h"

namespace Screen
{
	Vector2 WorldToScreen(Vector3 position);
}
