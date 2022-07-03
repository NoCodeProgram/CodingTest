#include <iostream>

struct QueueNode
{
	int val=0;
	QueueNode * left = nullptr;
	QueueNode * right = nullptr;

	QueueNode():val(0){}
	QueueNode(int x):val(x){}
};

class Queue
{
private:
	QueueNode mHead;
	QueueNode mTail;

public:
	Queue()
	{
		mHead.right = &mTail;
		mTail.left = &mHead;
	}
	void enqueue(int x)
	{
		QueueNode * newNode = new QueueNode(x);
		QueueNode * lastNode = mTail.left;

		lastNode->right = newNode;
		newNode->left = lastNode;
		
		mTail.left = newNode;
		newNode->right = &mTail;

	}
	int dequeue()
	{
		QueueNode * firstNode = mHead.right;
		if (firstNode == &mTail)
		{
			throw std::runtime_error("no Node");
		}

		const int value = firstNode->val;
		QueueNode * secondNode = firstNode->right;
		mHead.right = secondNode;
		secondNode->left = &mHead;

		delete firstNode;
		return value;
	}
};

int main()
{
	Queue queue;
	queue.enqueue(1);
	queue.enqueue(3);
	queue.enqueue(5);
	queue.enqueue(7);
	queue.enqueue(9);

	std::cout << queue.dequeue() << "\n";
	std::cout << queue.dequeue() << "\n";
	std::cout << queue.dequeue() << "\n";
	std::cout << queue.dequeue() << "\n";
	std::cout << queue.dequeue() << "\n";
	std::cout << queue.dequeue() << "\n";
}