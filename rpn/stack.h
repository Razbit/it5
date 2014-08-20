/* Razbit's C++ implementation of the stack data structure
 * 
 * Copyright 2014 Eetu Pesonen
 * Licensed under the terms of the GNU GPLv3
 */

#include <stdlib.h>
#include <iostream>

template<class T> class Stack
{
public:
    Stack()
		{
			pTop = NULL;
			pBottom = NULL;
			m_nSize = 0;
		}
	
    virtual ~Stack(){};

	T pop() //remove & return the topmost element
		{
			T ret = *(pTop->pElement);
			ElementContainer* pTemp = pTop->pPrev;
			delete pTop->pElement;
			delete pTop;
			pTop = pTemp;

			if(!pTop) //we popped the last item in the stack
				pBottom = NULL;

			m_nSize--;
			
			return ret;
		}
	
	void push(T element) //add to the top of the stack
		{
			ElementContainer* pTemp = new ElementContainer;
			T* tempElem = new T;
			*tempElem = element;
			
			pTemp->pElement = tempElem;
			
			pTemp->pPrev = pTop;
			pTop = pTemp;
			
			if (!pBottom) //no prev items, so this is the first
				pBottom = pTemp;

			m_nSize++;
		}
	
	bool empty() //ret true if stack is empty
		{
			if (!pBottom)
				return true;
			return false;
		}

	void copy(Stack<T>* stack)
		{
			Stack<T>* tempStack = new Stack<T>;

			ElementContainer* pCur = pTop;
			int i = 0;
			
			while (!empty())
			{
				tempStack->push(this->pop());
				i++;
			}
			
			T temp;
			
			for (;i > 0; i--)
			{
				temp = tempStack->pop();

				stack->push(temp);
				this->push(temp);
			}

			delete tempStack;
		}

	int size()
		{
			return m_nSize;
		}
	
private:
	struct ElementContainer
	{
		T* pElement;
		ElementContainer* pPrev;
	};

	ElementContainer* pTop;
	ElementContainer* pBottom;

	int m_nSize;
};
