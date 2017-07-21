#include "kdtree.h"


void KdTree::MakeEmpty(TreeNode* tree)
{
	if (tree != NULL)
	{
		MakeEmpty(tree->left_child);
		MakeEmpty(tree->right_child);
		free(tree);
	}
	return;
}

TreeNode* KdTree::Insert(TreeNode* tree, Vertex element)
{
	if (tree == NULL)
	{
		tree = (TreeNode*)malloc(sizeof(struct TreeNode));
		if (tree == NULL)
		{
			printf("malloc new TreeNode failed.\n");
			return NULL;
		}
		else {
			tree->value = element;
			tree->left_child = tree->right_child = NULL;
			tree->split_dimention = (current_dimension_ + 1) % Dim;
			//current_dimension_ = (current_dimension_ + 1) % Dim;
		}
	}
	else {
		current_dimension_ = tree->split_dimention;
		if (element.position[current_dimension_] < tree->value.position[current_dimension_]) {
			tree->left_child = Insert(tree->left_child, element);
		}
		else if (element.position[current_dimension_] > tree->value.position[current_dimension_])
			tree->right_child = Insert(tree->right_child, element);
	}

	
	num_nodes_++;
	for (int i = 0; i < Dim; i++) {
		if (element.position[i] < min_[i])
			min_[i] = element.position[i];
		else if (element.position[i] > max_[i])
			max_[i] = element.position[i];
	}
	return tree;
}

void KdTree::PrintKdTree()
{
	if (root == NULL)
	{
		printf("This is a empty tree.\n");
	}
	else {
		PrintTreeNodes(root);
	}
}

void KdTree::PrintTreeNodes(TreeNode* node)
{
	if (node == NULL)
		return;

	Vertex v = node->value;
	printf("(%f, %f, %f) \n", v.position[0], v.position[1], v.position[2]);
	PrintTreeNodes(node->left_child);
	PrintTreeNodes(node->right_child);
}

TreeNode* KdTree::FindNearest(TreeNode* tree, Vertex source_vert)
{
	if (tree == NULL) {
		printf("Can not find a nearest point in a empty tree. \n");
		return NULL;
	}
	// 1. Find target node.
	int find_dimension = 0;
	stack<TreeNode*> search_path;
	TreeNode* pSearch = tree;
	TreeNode* nearest_node = tree;
	Vertex nearest_vert;
	float distance;

	while (pSearch != NULL)
	{
		search_path.push(pSearch);
		find_dimension = pSearch->split_dimention;
		if (source_vert.position[find_dimension] <= pSearch->value.position[find_dimension]) {
			pSearch = pSearch->left_child;
		}
		else {
			pSearch = pSearch->right_child;
		}

	}

	// 2. Regard the last leaf node in search_path as the temporal nearest
	nearest_vert = search_path.top()->value;
	search_path.pop();
	distance = Distance(nearest_vert, source_vert);

	// 3. traversal back
	TreeNode* pBack;
	while (search_path.size() != 0) {
		pBack = search_path.top();
		search_path.pop();
		// 如果pBack是叶子节点
		if (this->IsLeaf(pBack)) {
			if (Distance(pBack->value, source_vert) < distance) {
				nearest_vert = pBack->value;
				distance = Distance(pBack->value, source_vert);
				nearest_node = pBack;
			}
		}
		else {
			find_dimension = pBack->split_dimention;

			if (abs(pBack->value.position[find_dimension]  
				- source_vert.position[find_dimension]) < distance) {  // ??
				if (Distance(pBack->value, source_vert) < distance) {
					nearest_vert = pBack->value;
					distance = Distance(pBack->value, source_vert);
					nearest_node = pBack;
				}

				if (source_vert.position[find_dimension] <= pBack->value.position[find_dimension])
				{
					pSearch = pBack->right_child;
				}
				else
					pSearch = pBack->left_child;

				if (pSearch != NULL)
					search_path.push(pSearch);
			}
		}
	}

	printf("Nearest vertex is: (%f,%f,%f)\n", nearest_vert.position[0], nearest_vert.position[1], nearest_vert.position[2]);
	printf("Nearest distance is: %f", distance);
	return nearest_node;
}

bool KdTree::IsLeaf(TreeNode* node)
{
	if (node->left_child == NULL && node->right_child == NULL)
		return true;
	return false;
}
