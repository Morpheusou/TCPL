template<typename T>
class Tree {
	using value_type = T;  // member alias
	enum Policy { rb, splay, treeps}; // memeber enum

	class Node {
		Node* right;
		Node* left;
		value_type value;
		public:
		void f(Tree<T>*);
	};
	Node* top;
	public:
	void g(const T&);
	// ...
};

template<typename T>
void Tree<T>::Node::f(Tree* p)
{
	//top = right; // error: no object of type Tree specified
	p->top = right; // OK
	value_type v = left->vale; // OK value_type is not associate with an object
}

template<typename T>
void Tree<T>::g(Tree<T>::Node* p)
{
	//value_type val = right->value; // error: no object of type Tree::Node
	//value_type v = p->right->value; // error: Node::right is private
	p->f(this);  // OK
}
