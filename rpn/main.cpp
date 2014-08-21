#include "stack.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void clearWhitespace(char* str);
void getStackContents(char* str, Stack<char>* pStack);

int main()
{
	printf("Please type a math expression in infix notation: ");

	char szStr[512];
	fgets(szStr, sizeof(szStr), stdin);
	
	char* szRet = new char[strlen(szStr)+1];

	Stack<char> stack;
	char stackContents[512];
	
	for (int i = 0; i < 512; i++)
		stackContents[i] = '\0';
	
	clearWhitespace(szStr);

	int j = 0;

	printf("%-8.8s|%-16.16s|Output\n", "Input", "Stack");
	
	for (int i = 0; i < strlen(szStr); i++)
	{
		if (i % 5 == 0) //clearer output
			printf("\n");

		if (isdigit(szStr[i]))
		{
			szRet[j] = szStr[i];
			
			getStackContents(stackContents, &stack);
			printf("%-8.8c|%-16.16s|%c\n", szStr[i], stackContents, szRet[j++]);

			continue;
		}
		
		if (szStr[i] == ')')
		{
			// We pop things from  the stack until we have popped a ')'
			// which means that the current expression is done
			char temp;
				
			while (true)
			{
				temp = stack.pop();
				if (temp == '(')
					break;
				szRet[j] = temp;
				
				getStackContents(stackContents, &stack);
				printf("%-8.8c|%-16.16s|%c\n", szStr[i], stackContents, szRet[j++]);
			}
			
			continue;
		}
		
		stack.push(szStr[i]);
		
		if (szStr[i] != '(') //add a space between operands..
			szRet[j++] = ' ';
		
		getStackContents(stackContents, &stack);
		printf("%-8.8c|%-16.16s|\n", szStr[i], stackContents);

	}

	int i = 0;
	//now we're almost done, we just need to pop everything left on the stack
	while (!stack.empty())
	{
		if (i++ % 5 == 0)
			printf("\n"); //cleaner output..
		
		szRet[j] = stack.pop();
		
		getStackContents(stackContents, &stack);
		printf("%-8.8c|%-16.16s|%c\n", ' ', stackContents, szRet[j++]);
	}

	szRet[j] = '\0'; //null termination
	
	printf("\n%s -> %s\n", szStr, szRet);
	
	return 0;
}

void clearWhitespace(char* str)
{
	//removes all whitespace
	
	char* temp = new char[strlen(str)+1];
	strcpy(temp, str);

	int i = 0, j = 0;
	
	for (; i < strlen(str); i++)
	{
		if (isspace(temp[i]))
			continue;
		str[j] = temp[i];
		j++;
	}

	str[j] = '\0'; //null termination
}

void getStackContents(char* str, Stack<char>* pStack)
{
	Stack<char>* tempStack = new Stack<char>;
	pStack->copy(tempStack);
	
	int i;
	
	for (i = 0; i < pStack->size(); i++)
	{
		str[i] = tempStack->pop();
	}

	str[++i] = '\0'; //add null termination

	delete tempStack;
}
