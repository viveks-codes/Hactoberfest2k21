#include<iostream>

using namespace std;

template<typename T> struct Node{
	T data;
	Node *left = NULL;
	Node *right = NULL;
	Node(T item){
		data = item;
	};
};

template<typename T> class Tree{
	private:
		Node<T> *root = NULL;
		int node_count;
		Node<T>* insertInBST(Node<T> *node, T item){
			if(node == NULL){
				return new Node<T>(item);
			}
			if(item < node->data){
				node->left = insertInBST(node->left, item);
			} else {
				node->right = insertInBST(node->right, item);
			}
			return node;
		}
		Node<T>* inorder(Node<T>* node){
			if(node == NULL)
				return node;
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
			return node;
		}
		Node<T>* inorderSuccessor(Node<T>* node){
			Node<T> *temp = node;
			while(temp && temp->left != NULL){
				temp = temp->left;
			}
			return temp;
		}
		Node<T>* deleteInBST(Node<T> *node, T key){
			if(node == NULL){
				return node;
			}
			if(key < node->data){
				node->left = deleteInBST(node->left, key);
			}
			else if(key > node->data){
				node->right = deleteInBST(node->right, key);
			}
			else{
				if(node->left == NULL and node->right == NULL){
					return NULL;
				}
				else if(node->left == NULL){
					Node<T> *temp = node->right;
					delete node;
					return temp;
				}
				else if(root->right == NULL){
					Node<T> *temp = node->left;
					delete node;
					return temp;
				}
				Node<T>* temp = inorderSuccessor(node->right);
				node->data = temp->data;
				node->right = deleteInBST(node->right, temp->data);
			}
			return node;
		}
		Node<T>* searchNode(Node<T> *node, T key){
			if(node == NULL){
				return node;
			}
			if(key < node->data)
				searchNode(node->left, key);
			else if(key > node->data)
				searchNode(node->right, key);
			else
				return node;
		}
		int get_maximum(Node<T>* node){
			if(node == NULL){
				return INT_MIN;
			}
			int res = node->data;
			int lres = get_maximum(node->left);
			int rres = get_maximum(node->right);
			if (lres > res)
				res = lres;
			if (rres > res)
				res = rres;
			return res;
		}
		int maxDepth(Node<T> *node){
			if(node == NULL)
				return 0;
			else{
				int leftDepth = maxDepth(node->left);
				int rightDepth = maxDepth(node->right);
				return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1; 
			}
		}
		void deleteTree(Node<T>* node){
			if(node==NULL)
				return;
			deleteTree(node->left);
			deleteTree(node->right);
			delete node;
		}
	public:
		void insert(T item){
			if(root == NULL){
				root = insertInBST(root, item);
			} else{
				insertInBST(root, item);
			}
			node_count++;
		}
		int get_node_count(){
			return node_count;
		}
		void print_values(){
			inorder(root);
			cout << endl;
		}
		void deleteNode(T item){
			deleteInBST(root, item);
			node_count--;
		}
		bool is_in_tree(T item){
			return searchNode(root,item) != NULL;
		}
		int get_height(){
			return maxDepth(root);	
		}
		int get_min(){
			return inorderSuccessor(root)->data;
		}
		int get_max(){
			int x =  get_maximum(root);
			return x;
		}
		void deleteTree(){
			deleteTree(root);
		}
		T get_successor(T item){
			Node<T>* node = searchNode(root, item);
			Node<T>* successorNode = inorderSuccessor(node);
			return successorNode->right->data;
		}
};

// Driver Code
int main(){
	Tree<int> tree;
	tree.insert(8);
	tree.insert(3);
	tree.insert(9);
	tree.insert(4);
	tree.insert(1);
	tree.insert(6);
	/*
	Tree:
				8
			  /  \
			3	  9
		  / \	
		 1   4
			  \
			   6
	*/
	tree.print_values();
	cout << tree.get_height() << endl;
	cout << tree.get_min() << endl;
	cout << tree.get_max() << endl;
	tree.print_values();
	/*
	Tree:
				8
			  /  \
			3	  9
		  / \	
		 1   4
			  \
			   6
	*/
	cout << tree.get_successor(4) << endl;
	return 0;
}
