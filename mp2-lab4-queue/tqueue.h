#pragma once
#include <iostream>

template <class T>
class TQueue
{
	int MaxSize;
	int head;
	int tail;
	int DataCount;
	T* pMem;
public:
	TQueue(int s = 10);
	TQueue(const TQueue<T>& q);
	~TQueue();
	TQueue& operator=(const TQueue& q);

	bool operator==(const TQueue& q) const; 
	bool operator!=(const TQueue& q) const;

	T front();
	T back();

	void SetDataCount(int newDC);
	int GetMaxSize();
	int GetSize();
	int GetHead();
	bool empty();
	bool full();
	void push(T elem);
	T pop();
};

template <class T>
TQueue<T>::TQueue(int s)
{
	if (s < 0)
		throw s;
	head = 0;
	tail = -1;
	DataCount = 0;
	MaxSize = s;
	pMem = new T[MaxSize];

}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& q)
{
	int i = q.head;
	MaxSize = q.MaxSize;
	head = q.head;
	tail = q.tail;
	DataCount = q.DataCount;
	pMem = new T[MaxSize];

	while (i != tail && tail != -1)
	{
		pMem[i] = q.pMem[i];
		i = (i + 1) % MaxSize;
	}
	pMem[i] = q.pMem[i];
}

template <class T>
TQueue<T>::~TQueue()
{
	if (pMem)
	{
		delete[] pMem;
		pMem = 0;
	}
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue& q)
{
	int i = q.head;
	if (MaxSize != q.MaxSize)
	{
		delete[] pMem;
		MaxSize = q.MaxSize;
		pMem = new T[MaxSize];
	}
	DataCount = q.DataCount;
	head = q.head;
	tail = q.tail;
	while (i != tail && tail != -1)
	{
		pMem[i] = q.pMem[i];
		i = (i + 1) % MaxSize;
	}
	pMem[i] = q.pMem[i];
	return *this;
}

template <class T>
bool TQueue<T>::operator==(const TQueue& q) const
{
	if (MaxSize != q.MaxSize || DataCount != q.DataCount)
		return 0;
	int i = head;
	while (i != tail && tail != -1)
	{
		if (pMem[i] != q.pMem[i])
			return 0;
		i = (i + 1) % MaxSize;
	}
	if (pMem[i] != q.pMem[i])
		return 0;
	return 1;
}

template <class T>
bool TQueue<T>::operator!=(const TQueue& q) const
{
	return !(*this == q);
}

template <class T>
T TQueue<T>::front()
{
	if (!empty()) return pMem[head];

}

template <class T>
T TQueue<T>::back() 
{ 
	if (!empty()) return pMem[tail];
}

template <class T>
void TQueue<T>::push(T elem)
{
	if (full())
	{
		throw - 1;
	}
	DataCount++;
	tail = (tail + 1) % MaxSize;
	pMem[tail] = elem;
}

template <class T>
T TQueue<T>::pop()
{
	if (empty())
	{
		throw - 1;
	}
	T res = pMem[head];
	DataCount--;
	head = (head + 1) % MaxSize;
	return res;
}

template <class T>
void TQueue<T>::SetDataCount(int newDC)
{
	DataCount = newDC;
}

template <class T>
int TQueue<T>::GetMaxSize()
{
	return MaxSize;
}

template <class T>
int TQueue<T>::GetSize()
{
	return DataCount;
}

template <class T>
int TQueue<T>::GetHead()
{
	return head;
}

template <class T>
bool TQueue<T>::empty() 
{ 
	return DataCount == 0;
}

template <class T>
bool TQueue<T>::full() 
{ 
	return DataCount == MaxSize;
}
