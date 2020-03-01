#include <iostream>
#include <stack>
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
private:
	void insert(int key, node* leaf);
};

btree::btree(){
	root = NULL;
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
		root->left = NULL;
		root->right = NULL;
	}
}

void btree::preorder(node* t) {
	stack<node*> st;
	while (t != NULL || !st.empty()) {
		if (t != NULL) {
			cout << t->key_value << " ";
			st.push(t);
			t = t->left;
		}
		else {
			t = st.top();
			st.pop();
			t = t->right;
		}
	}
}

int main() {
	btree* bt = new btree();
	for (int i = 0; i < 10; i++) {
		bt->insert(i);
	}
	bt->preorder(bt->root);
}