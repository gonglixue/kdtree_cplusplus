#include "kdtree.h"

void main()
{
	KdTree kd_tree;
	
	float data[12] = { 30,40,5,25,10,12,70,70,50,30,35,45 };

	for (int i = 0; i < 6; i++) {
		Vertex t;
		t.InitPosition(data[2 * i], data[2 * i + 1], 0);
		kd_tree.root = kd_tree.Insert(kd_tree.root, t);
	}

	kd_tree.PrintKdTree();
	Vertex t;
	t.InitPosition(50, 30);
	Vertex t2;
	t2.InitPosition(37, 45);
	//kd_tree.FindNearest(kd_tree.root, t);
	kd_tree.FindNearest(kd_tree.root, t2);
	printf("hello world");
}