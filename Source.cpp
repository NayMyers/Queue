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
void Queue<T>::push(T value)
{

}
int main(void)
{

	return 0;
}