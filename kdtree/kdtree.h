#pragma once
#include <stdlib.h>
#include <iostream>
#include <stack>

#include "MyMesh.h"

#define Dim 2

using namespace std;

struct TreeNode {
	// 节点元素值
	Vertex value;
	// 该值出现次数
	// int times;  
	TreeNode* left_child;
	TreeNode* right_child;
	int split_dimention;

};

class KdTree {
public:
	// 构造函数，默认根为空，节点数为0
	KdTree() { 
		root = NULL; num_nodes_ = 0; current_dimension_ = -1; 

	}
	// 树的根元素
	TreeNode* root;
	// 清空
	void MakeEmpty(TreeNode* tree);

	TreeNode* Insert(TreeNode* tree, Vertex element);
	int GetNumOfNodes() { return num_nodes_; }
	// 打印
	void PrintKdTree();
	// 最近邻点
	TreeNode* FindNearest(TreeNode* tree, Vertex vert);
	static bool IsLeaf(TreeNode* node);
private:
	// 树结点数量
	int num_nodes_;
	// 当前用于比较的维度
	int current_dimension_;
	void PrintTreeNodes(TreeNode* node);
	// 边界
	int min_[Dim];
	int max_[Dim];
	



};