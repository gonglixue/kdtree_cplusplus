#pragma once
#include <stdlib.h>
#include <iostream>
#include <stack>

#include "MyMesh.h"

#define Dim 2

using namespace std;

struct TreeNode {
	// �ڵ�Ԫ��ֵ
	Vertex value;
	// ��ֵ���ִ���
	// int times;  
	TreeNode* left_child;
	TreeNode* right_child;
	int split_dimention;

};

class KdTree {
public:
	// ���캯����Ĭ�ϸ�Ϊ�գ��ڵ���Ϊ0
	KdTree() { 
		root = NULL; num_nodes_ = 0; current_dimension_ = -1; 

	}
	// ���ĸ�Ԫ��
	TreeNode* root;
	// ���
	void MakeEmpty(TreeNode* tree);

	TreeNode* Insert(TreeNode* tree, Vertex element);
	int GetNumOfNodes() { return num_nodes_; }
	// ��ӡ
	void PrintKdTree();
	// ����ڵ�
	TreeNode* FindNearest(TreeNode* tree, Vertex vert);
	static bool IsLeaf(TreeNode* node);
private:
	// ���������
	int num_nodes_;
	// ��ǰ���ڱȽϵ�ά��
	int current_dimension_;
	void PrintTreeNodes(TreeNode* node);
	// �߽�
	int min_[Dim];
	int max_[Dim];
	



};