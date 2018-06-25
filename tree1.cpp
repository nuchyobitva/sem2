#include <iostream>
using namespace std;
class tree_t {
	struct node_t {
		node_t * left;
		node_t * right;
		int value;
		~node_t() {
			if (left != nullptr) delete left;
			if (right != nullptr)delete right;
		}
  };
	node_t * root = NULL;
	
public:

	void insert(int value) {
		node_t * add = new node_t;
		add->value = value;
		add->left = NULL;
		add->right = NULL;
		node_t * head = root;
		if (head == NULL) {
			root = add;
		}
		else {
			for (;;) {
				if (value < head->value) {
					if (head->left == NULL) { head->left = add; break; }
					else { head = head->left; }
				}
				else if (value > head->value) {
					if (head->right == NULL) { head->right = add; break;}
					else { head = head->right; }
				}
			}
		}
	}

	bool find(int value) const
	{
		bool a = false;
		if (root == NULL) cout << "Tree is empty" << endl;
		else {
			node_t *search = root;
			for (;;) {
				if (search->value == value) { a = true; break; }
				if (value < search->value) {
					if (search->left == NULL) { break; }
					search = search->left;
				}
				else if (value > search->value) {
					if (search->right == NULL) { break; }
					search = search->right;
				}
			}
		}
		return a;
	}

	void print(ostream & stream, node_t *f, int u) const
	{
		for (int i = 0; i < u; i++) stream << "----";
		stream << f->value << endl;
		}

	void help_print(ostream & stream, node_t * s, int u) {
		if (s == NULL) return;
		else
			{
			    u++;
				help_print(stream, s->right, u);
				print(cout, s, u);
				help_print(stream, s->left, u);
            }
		}

	void help_print(ostream & stream) {
		help_print(stream,root, 0);
	    }
     
 ~tree_t() {		if (root != nullptr) delete root; 	}
	};


int main(){
	char op; int a;
	tree_t tree;
	cin >> op;
	while (op != 'q') {
		switch (op) {
		case '+':
			cin >> a;
			tree.insert(a);
			tree.help_print(cout);
			break;
		case '?':
			cin >> a;
			cout << tree.find(a) << endl;
			break;
		case '=':
			tree.help_print(cout);
		}
		cin >> op;
	}
	return 0;
}
