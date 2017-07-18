#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

template<typename T>
struct TreeNode {
	T value;
	TreeNode* left_child;
	TreeNode* right_child;
};

template <typename T>
class KdTree {
	TreeNode<T>* root;
};