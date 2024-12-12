#include <memory>

template<typename T>
struct Node {
	T value;
	Node* parent;
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> right;

	Node(const T& value, Node* parent_node = nullptr) :
		value(value), parent(parent_node), left(nullptr), right(nullptr) {}
};


template <typename T> 
class BST {

private:
	std::unique_ptr<Node<T>> root;

	void insert_recursive(std::unique_ptr<Node<T>>& node, const T& value, Node<T>* parent)
	{
		if (!node)
			node = std::make_unique<Node<T>>(value, parent);

		else if (value < node->value)
			insert_recursive(node->left, value, node.get());

		else if (value > node->value)
			insert_recursive(node->right, value, node.get());
	}

	void print_recursive(const Node<T>* node) const
	{
		if (!node) return;

		print_recursive(node->left.get());
		std::cout << node->value << " ";
		print_recursive(node->right.get());
	}

public:
	BST() : root(nullptr) {};

	void insert(const T& value)
	{
		insert_recursive(root, value, nullptr);
	}

	void print_in_order() const
	{
		print_recursive(root.get());
		std::cout << "\n";
	}
};
