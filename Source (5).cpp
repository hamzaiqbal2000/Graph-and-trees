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
	node* Isearch(node* t, int key);
	node* Rsearch(node* t, int key);
	node* Delete(node* t, int key);
	int Height(node* p);
	void inorder(node* t);
	node* InPre(node* p);
	node* InSuc(node* p);
	node* root;
private:
	void insert(node* leaf, int key);
};

btree::btree(){}

node* btree::Isearch(node* t, int key) {
	while (t != NULL) {
		if (key == t->key_value) {
			return t;
		}
		else if (key < t->key_value) {
			t = t->left;
		}
		else {
			t = t->right;
		}
	}
}

node* btree::Rsearch(node* t, int key) {
	if (t == NULL) {
		return NULL;
	}
	else if (t->key_value == key) {
		return t;
	}
	else if (key < t->key_value) {
		return Rsearch(t->left, key);
	}
	else if (key > t->key_value) {
		return Rsearch(t->right, key);
	}
}

int btree::Height(node* p)
{
	int x, y;
	if (p == NULL)return 0;
	x = Height(p->left);
	y = Height(p->right);
	return x > y ? x + 1 : y + 1;
}

node* btree::InPre(node* p)
{
	while (p && p->right != NULL)
		p = p->right;
	return p;
}

node* btree::InSuc(node* p) {
	while (p && p->left != NULL) {
		p = p->left;
	}
	return p;
}

node* btree::Delete(node* p, int key) {

	node* q= root;
	if (p == NULL)
		return NULL;
	if (p->left == NULL && p->right == NULL)
	{
		if (p == root)
			root = NULL;
		free(p);
		return NULL;
	}
	if (key < p->key_value)
		p->left = Delete(p->left, key);
	else if (key > p->key_value)
		p->right = Delete(p->right, key);
	else
	{
		if (Height(p->left) > Height(p->right))
		{
			q = InPre(p->left);
			p->key_value = q->key_value;
			p->left = Delete(p->left, q->key_value);
		}
		else
		{
			q = InSuc(p->right);
			p->key_value = q->key_value;
			p->right = Delete(p->right, q->key_value);
		}
	}
	return p;
}


void btree::insert(node* leaf, int key) {
	if (key < leaf->key_value) {
		if (leaf->left != NULL) {
			insert(leaf->left, key);
		}

		else {
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}

	else if ( key >= leaf->key_value) {
		if (leaf->right != -NULL) {
			insert(leaf->right, key);
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
		insert(root, key);
	}
	else {
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void btree::inorder(node* t) {
	if (t != NULL) {
		inorder(t->left);
		cout << t->key_value << " ";
		inorder(t->right);
	}
}

int main() {
	btree* bt = new btree();
	bt->insert(10);
	bt->insert(8);
	bt->insert(9);
	bt->insert(11);
	bt->insert(1);
	bt->insert(15);
	bt->insert(12);
	bt->inorder(bt->root);
	bt->Delete(bt->root,10);
	cout << endl;
	bt->inorder(bt->root);

}