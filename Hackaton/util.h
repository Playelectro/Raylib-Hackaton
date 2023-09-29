#pragma once

#include <raylib.h>

inline Vector3 addVectors(Vector3 v1, Vector3 v2) {
	Vector3 rez;

	rez.x = v1.x + v2.x;
	rez.y = v1.y + v2.y;
	rez.z = v1.z + v2.z;

	return rez;
}
