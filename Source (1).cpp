#include <iostream>
using namespace std;


struct node {
	int key_value;
	node* left;
	node* right;
};
class btree {
public:
	btree();
	void insert(int key);
	node* root;
private:
	void insert(int key, node* leaf);
};

btree::btree() {
}

void btree::insert(int key, node* leaf){
	if (key < leaf->key_value) {
		if (leaf->left != NULL) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}

	else if (key >= leaf->key_value) {
		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}

		else {
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}


void btree::insert(int key) {
	if (root != NULL) {
		insert(key, root);
	}
	else {
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

int main() {
	btree* ptr = new btree();
	ptr->insert(9);
}