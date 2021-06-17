#include <stdexcept>
#include <cstring>
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <iomanip>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Node
{
public:
	Node(int value)
	{
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	
	Node(int value, Node* left, Node* right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}

	int getValue() const
	{
		return value;
	}

	Node* getLeft() const
	{
		return left;
	}

	Node* getRight() const
	{
		return right;
	}

	void setLeft(Node * lNode)
	{
		this->left = lNode;	
	}

	void setRight(Node * rNode)
	{
		this->right = rNode;
	}

private:
	int value;
	Node* left;
	Node* right;
};

class TreeTraversals {
public:
	static void inOrder(Node *root) {
		if (root == NULL) {
			return;
		}
		inOrder(root->getLeft());
		cout << setw(4) << root->getValue() ;
		inOrder(root->getRight());
	}

	static void preOrder(Node *root) {
		if (root == NULL) {
			return;
		}
		cout << setw(4) << root->getValue();
		preOrder(root->getLeft());
		preOrder(root->getRight());
	}

	static void postOrder(Node *root) {
		if (root == NULL) {
			return;
		}
		postOrder(root->getLeft());
		postOrder(root->getRight());
		cout << setw(4) << root->getValue();

	}

	static void inorderItr(Node *root) {
	
		std::stack<Node*, std::deque<Node*> > stack;

				
		//	Deque<Node> stack = new LinkedList<Node>();
		Node *node = root;
		while (true) {
			if (node != NULL) {
				stack.push(node);
				node = node->getLeft();
			}
			else {
				if (stack.empty()) {
					break;
				}
				node = stack.top();
				stack.pop();
				cout << setw(4) << node->getValue();

				node = node->getRight();
			}
		}
	}


	static void preorderItr(Node *root) {
	
		std::stack<Node*, std::deque<Node*> > st;

		Node *n = root;
	
		while (1)
		{
			while (n != nullptr)
			{
				cout << setw(4) << n->getValue();
				st.push(n);
				n = n->getLeft();
			}

			if (st.empty())
				return;

			n = st.top();
			st.pop();
			n = n->getRight();
			
		}
		
	}


	static void postorderItr(Node *root) {
	
		std::stack<Node*, std::deque<Node*> > st;

		Node *n = root;
	
		while (1)
		{
			while (n != nullptr)
			{
				st.push(n);
				n = n->getLeft();
			}

			if (st.empty())
				return;

			n = st.top();			

			n = n->getRight();
			
			if (n == nullptr && !st.empty())
			{
				cout << setw(4) << n->getValue();
				st.pop();
				n = n->getRight();

			}
			
		}
		
	}
};



class BinarySearchTree
{
public:
	static bool contains(const Node& root, int value)
	{
		if (&root == NULL) {
			return false;
		}

		if (root.getValue() == value) {
			return true;
		}
		else if (root.getValue() < value) {
			return contains(*root.getRight(), value);
		}
		else {
			return contains(*root.getLeft(), value);
		}
	}


	static Node * makeBSTfromArray(std::vector<int> const &a)
	{

		Node * root = makeBSTfromArray(a, 0, a.size() - 1);

		return root;

	}

	static Node * makeBSTfromArray(std::vector<int> const &a, int min, int max) {


		if (min>max) return NULL;

		int midIdx = (min + max) / 2;
		cout << " a[" << midIdx << "]: " << a[midIdx] << endl  ;

		Node *nodePtr = new Node(a[midIdx]);
		nodePtr->setLeft(makeBSTfromArray(a, min, midIdx - 1));
		nodePtr->setRight(makeBSTfromArray(a, midIdx + 1, max));

		return nodePtr;

	}


};

class IsBST {
public:
	static bool isBST(Node *root) {
		return isBST(root, LONG_MIN, LONG_MAX);
	}

private:
	static bool isBST(Node *root, int min, int max) {
		if (root == NULL) {
			return true;
		}
		if (root->getValue() <= min || root->getValue() > max) {
			return false;
		}
		return isBST(root->getLeft(), min, root->getValue()) && isBST(root->getRight(), root->getValue(), max);
	}
};


class TreeTraversalLevelByLevel {
public:

	static void levelByLevelOneQueueUsingCount(Node *root) {
		if (root == NULL) {
			return;
		}

		std::queue<Node *, std::deque<Node *>> q;

		int levelCount = 1;
		int currentCount = 0;
		q.push(root);

		while (!q.empty()) {
			while (levelCount > 0) {
				root = q.front();
				q.pop();
				cout << setw(4) << root->getValue();

				if (root->getLeft() != NULL) {
					currentCount++;
					q.push(root->getLeft());
				}
				if (root->getRight() != NULL) {
					currentCount++;
					q.push(root->getRight());
				}
				levelCount--;
			}
			cout << endl;
			levelCount = currentCount;
			currentCount = 0;
		}
	}

	static void bfsBinaryTree(Node * root)
	{

		unordered_map<Node *, int> level;
		unordered_map<Node *, Node *> parent;
		

		//level.emplace(root, 0);

//		parent.emplace(root, NULL);

		level[root] = 0;
		parent[root] =  NULL;

		unordered_set<Node *> frontier; // nodes at level i - 1
		unordered_set<Node *> next; // nodes at level i


		int i = 1;  // level 1 (nodes reachable in i=1 moves)

		frontier.insert(root); // i at 1 so put in nodes at level 0 - rootNode

		while (!frontier.empty())
		{

			next.clear() ; //reset next to empty

			for (Node* u : frontier)
			{
				if (u->getLeft() != NULL)
				{
					
					std::unordered_map<Node*,int>::const_iterator findIter = level.find(u->getLeft());
					
					if (level.end() == findIter)
					{
						//level.emplace(u->getLeft(), i);
						level[u->getLeft()] = i;
						//parent.emplace(u->getLeft(), u);
						parent[u->getLeft()] = u;
						next.emplace(u->getLeft());

					}
				}

				if (u->getRight() != NULL)
				{

					std::unordered_map<Node*, int>::const_iterator findIter = level.find(u->getRight());

					if (level.end() == findIter)
					{
						//level.emplace(u->getRight(), i);
						level[u->getRight()] = i;
						//parent.emplace(u->getRight(), u);
						parent[u->getRight()] = u;
						next.emplace(u->getRight());

					}
				}

				cout << setw(4) << u->getValue(); 
			}

			frontier = next;
			i++;
		}

		//System.out.println(level);
		//System.out.println(parent);


	}

	static void bfsBinaryTreeQ(Node * root)
	{
		if (root == NULL) {
			return;
		}
		std::queue<Node *, std::deque<Node *>> q;
		q.push(root);

		cout << endl;
		
		std::list<Node*> visited;      // nodes at level i

		while (!q.empty()) {
			root = q.front();
			q.pop();
			visited.push_back(root);

			cout << setw(4) << root->getValue();

			if (root->getLeft() != NULL) {

				std::list<Node *>::iterator findIter = std::find(visited.begin(), visited.end(), root->getLeft());
				if (visited.end() == findIter)
					q.push(root->getLeft());
			}
			

			if (root->getRight() != NULL) {
				std::list<Node *>::iterator findIter = std::find(visited.begin(), visited.end(), root->getRight());
				if (visited.end() == findIter)
					q.push(root->getRight());

			}
		}
	}
};

#ifndef RunTests
int main()
{

	//Input Array = {3,4,5,6,7,8,9,10,12,13}
	//Expected Output = { 7,4,3,5,6,10,8,9,12,13 }
	//list.push_back(1);
	//list.push_back(3);
	//list.push_back(5);
	//list.push_back(7);
	//list.push_back(9);
	//list.push_back(11);
	//list.push_back(13);
	//list.push_back(16);
	//list.push_back(21);
	//list.push_back(23);
	//list.push_back(26);
	//list.push_back(33);
	//list.push_back(36);
	//list.push_back(42);
	//list.push_back(44);
	//list.push_back(59);

//	std::vector<int> list = { 3,4,5,6,7,8,9,10,12,13 };
//	std::vector<int> list = { 1, 2, 3, 4, 5 };
//	Node * root = BinarySearchTree().makeBSTfromArray(list);

	Node * root = new Node(1);
	Node * two = new Node(2);
	Node * three = new Node(3);
	Node * four = new Node(4);
	Node * five = new Node(5);
	
	two->setLeft(four);
	two->setRight(five);

	root->setLeft(two);
	root->setRight(three);

//	bool isbst = IsBST().isBST(root);/
//	cout << isbst << endl;

	TreeTraversals().preOrder(root);
	cout << endl; 
	TreeTraversals().inOrder(root);
	cout << endl;
	TreeTraversals().postOrder(root);
	cout << endl;


	TreeTraversals().preorderItr(root);
	cout << endl;

	TreeTraversals().inorderItr(root);
	cout << endl;


	TreeTraversalLevelByLevel().levelByLevelOneQueueUsingCount(root);
	cout << endl;
	cout << endl;

	TreeTraversalLevelByLevel().bfsBinaryTreeQ(root);
	cout << endl;
	cout << endl;

	TreeTraversalLevelByLevel().bfsBinaryTree(root);
		
		
	//Input Array = {3,4,5,6,7,8,9,10,12,13}
	//Expected Output = { 7,4,3,5,6,10,8,9,12,13 }

	//Node n1(1, NULL, NULL);
	//Node n3(3, NULL, NULL);
	//Node n2(2, &n1, &n3);

	//std::cout << BinarySearchTree::contains(n2, 3);
}
#endif