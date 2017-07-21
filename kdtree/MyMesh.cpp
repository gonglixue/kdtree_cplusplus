#include "MyMesh.h"

float Distance(Vertex v1, Vertex v2)
{
	float sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += pow(v1.position[i] - v2.position[i], 2);
	}

	return sqrt(sum);
}