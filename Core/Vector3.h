#pragma once
#include <cmath>

//-----------------------------------------------------------------------------------
//		Created by @Ander Berriel
//-----------------------------------------------------------------------------------

class Vector3 {

	public:
	
		float x = 0;
		float y = 0;
		float z = 0;

	Vector3(float px = 0, float py = 0, float pz = 0) {
		x = px; y = py; z = pz;
	}

	static Vector3 Zero() {

		Vector3 PosZero;

		PosZero.x = 0.0f;
		PosZero.y = 0.0f;
		PosZero.z = 0.0f;

		return PosZero;
	}

	static float Distance(const Vector3 &Pos1, const Vector3 &Pos2) {

		float X = (Pos1.x - Pos2.x) * (Pos1.x - Pos2.x);
		float Y = (Pos1.y - Pos2.y) * (Pos1.y - Pos2.y);
		float Z = (Pos1.z - Pos2.z) * (Pos1.z - Pos2.z);

		float CurrentDistance = sqrt(X + Y + Z);
		return CurrentDistance;
	}
};