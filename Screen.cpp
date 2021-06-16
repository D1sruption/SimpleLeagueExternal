#pragma once
#include "Screen.h"

namespace Screen
{
	Vector2 WorldToScreen(Vector3 position)
	{
		Vector2 screen = NULLVECTOR2;

		Matrix viewMatrix;
		ReadProcessMemory(handle, (LPCVOID)(baseAddress + oViewMatrix), (PBYTE)&viewMatrix, sizeof(viewMatrix), 0);
		//printf("viewMatrix: 0x%X\n", g_baseModule.vaBase + oViewMatrix);
		Matrix projectionMatrix;
		ReadProcessMemory(handle, (LPCVOID)(baseAddress + oViewMatrix + 0x40), (PBYTE)&projectionMatrix, sizeof(projectionMatrix), 0);
		//printf("projectionMatrix: 0x%X\n", g_baseModule.vaBase + oViewMatrix + 0x40);
		Matrix viewProjectionMatrix = viewMatrix * projectionMatrix;

		Vector4 out = NULLVECTOR4;
		out.X = (viewProjectionMatrix.a1 * position.X) + (viewProjectionMatrix.b1 * position.Y) + (viewProjectionMatrix.c1 * position.Z) + viewProjectionMatrix.d1;
		out.Y = (viewProjectionMatrix.a2 * position.X) + (viewProjectionMatrix.b2 * position.Y) + (viewProjectionMatrix.c2 * position.Z) + viewProjectionMatrix.d2;
		out.Z = (viewProjectionMatrix.a3 * position.X) + (viewProjectionMatrix.b3 * position.Y) + (viewProjectionMatrix.c3 * position.Z) + viewProjectionMatrix.d3;
		out.W = (viewProjectionMatrix.a4 * position.X) + (viewProjectionMatrix.b4 * position.Y) + (viewProjectionMatrix.c4 * position.Z) + viewProjectionMatrix.d4;

		if (out.Z < 0.1f) return screen;

		Vector3 M;
		M.X = out.X / out.W;
		M.Y = out.Y / out.W;
		M.Z = out.Z / out.W;

		screen.X = (1920 / 2 * M.X) + (M.X + 1920 / 2);
		screen.Y = -(1080 / 2 * M.Y) + (M.Y + 1080 / 2);

		return screen;
	}
}