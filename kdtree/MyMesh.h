#pragma once
#define ACCURANCY 0.000001

#include <cmath>
struct Vertex
{
	float position[3];
	float normal[3];
	float texcoord[2];
	int id;

	void InitPosition(float* in_pos) {
		for (int i = 0; i < 3; i++) {
			position[i] = in_pos[i];
		}
	}

	void InitPosition(float x, float y, float z=0)
	{
		position[0] = x;
		position[1] = y;
		position[2] = z;
	}


	// ÔËËã·ûÖØÔØ
	bool operator==(Vertex another_vert) {
		bool flag = true;
		for (int i = 0; i < 3; i++)
		{
			if (abs(another_vert.position[0] - this->position[0]) > ACCURANCY)
			{
				flag = false;
				break;
			}
		}

		return flag;
	}
};

float Distance(Vertex v1, Vertex v2);