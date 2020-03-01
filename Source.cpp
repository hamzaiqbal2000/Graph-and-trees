#include <iostream>
using namespace std;


struct node {
	int key_value;
	node* left;
	node* right;
};

class btree {
public:
	node* root;
	btree();
	void insert(int key);
	void preorder(node* t);
	void postorder(node* t);
	void inorder(node* t);
private:
	void insert(int key, node* leaf);
};

btree::btree() {

}

void btree::insert(int key, node* leaf) {
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
		root->left = root->right = NULL;
	}
}

void btree::preorder(node* t) {
	if (t != NULL) {
		cout << t->key_value << " ";
		preorder(t->left);
		preorder(t->right);
	}
}

void btree::inorder(node* t) {
	if (t != NULL) {
		inorder(t->left);
		cout << t->key_value << " ";
		inorder(t->right);
	}
}

void btree::postorder(node* t) {
	if (t != NULL) {
		postorder(t->left);
		postorder(t->right);
		cout << t->key_value << " ";
	}
}

int main() {
	btree* bt = new btree();
	for (int i = 0; i < 10; i++) {
		bt->insert(i);
	}
	bt->postorder(bt->root);
}