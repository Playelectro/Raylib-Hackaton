#pragma once

#include <raylib.h>
#include <cmath>
#include <raymath.h>

inline Vector3 addVectors(Vector3 v1, Vector3 v2) {
	Vector3 rez;

	rez.x = v1.x + v2.x;
	rez.y = v1.y + v2.y;
	rez.z = v1.z + v2.z;

	return rez;
}

inline Vector3 subtractVectors(Vector3 v1, Vector3 v2) {
	Vector3 rez;

	rez.x = v1.x - v2.x;
	rez.y = v1.y - v2.y;
	rez.z = v1.z - v2.z;

	return rez;
}

inline double distanceVectors(Vector3 v1, Vector3 v2) {
	return std::sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y) + (v1.z - v2.z) * (v1.z - v2.z));
}

inline Vector3 toScalarVector(Vector3 v, double s) {
	Vector3 rez;

	rez.x = v.x * s;
	rez.y = v.y * s;
	rez.z = v.z * s;

	return rez;
}

inline void addActor() {

}

static void CameraYaw(Camera* camera, float angle, bool rotateAroundTarget)
{
	Vector3 up = { 0, 1, 0 };

	Vector3 targetPosition = Vector3Subtract(camera->target, camera->position);

	targetPosition = Vector3RotateByAxisAngle(targetPosition, up, angle);

	if (rotateAroundTarget)
	{
		camera->position = Vector3Subtract(camera->target, targetPosition);
	}
	else 
	{
		camera->target = Vector3Add(camera->position, targetPosition);
	}
}
