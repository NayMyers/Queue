#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
	T value;
	Node* pNext = nullptr;
	Node* pPrevious = nullptr;
};

template<typename T>
class Queue
{
private:
	int count = 0;
	Node<T> *pTop = nullptr;
	Node<T> *pFront = nullptr;
	void push(T value);
	virtual Node<T>* nodeDequeue();
public:
	Queue(void);
	~Queue(void);
	virtual void enqueue(T value);
	virtual T dequeue(void);
	int size(void);
};
template<typename T>
Queue<T>::Queue()
{
	pFront = pTop = nullptr;
}
template<typename T>
Queue<T>::~Queue()
{
	while (pTop != nullptr){ delete nodeDequeue(); }
}
template<typename T>
void Queue<T>::push(T value)
{
	Node<T>* pTmp = new Node<T>;
	pTmp->value = value;
	pTmp->pNext = pTop;
	pTop = pTmp;
	count++;
}
template<typename T>
Node<T>* Queue<T>::nodeDequeue(void)
{
	Node<T> *pTmp = pFront;
	if (pFront != nullptr)
	{
		pFront = pFront->pPrevious;
		if (pFront != nullptr) pFront->pNext = nullptr;
		else pTop = pFront; //last node has been removed
	}

	return pTmp;
}
template<typename T>
T Queue<T>::dequeue(void)
{
	if (count == 0) throw "Queue Empty!";

	Node<T> *pTmp = nodeDequeue();
	T ret;

	if (pTmp != nullptr)
	{
		ret = pTmp->value;
	}
	else
	{
		throw "Error!";
	}
	delete pTmp;
	count--;
	return ret;
}
template<typename T>
void Queue<T>::enqueue(T value)
{
	this->push(value);

	if (pFront == nullptr) pFront = pTop;
	else(pTop->pNext)->pPrevious = pTop;
}
template<typename T>
int Queue<T>::size()
{
	return count;
}
int main(void)
{
	Queue<int>* MyQueue = new Queue<int>;

	for (int count = 0; count < 10; count++)
	{
		MyQueue->enqueue(count);
	}
	try
	{
		while (true)
		{
			cout << MyQueue->dequeue() << " ";
		}
	}
	catch (char* message)
	{
		cout << message << endl;
	}

	delete MyQueue;
	return 0;
}