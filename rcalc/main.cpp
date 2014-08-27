/* Razbit's RPN calculator
 */

#include "stack.h"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <float.h>

void do_plus(Stack<double>*);
void do_minus(Stack<double>*);
void do_mult(Stack<double>*);
void do_div(Stack<double>*);
void print(double);

int main()
{
	char instr[256];
	Stack<double>* pdStack = new Stack<double>;
	double temp;

	printf("Type q to quit\n");
	printf("Input a mathematical expression in RPN, each operand and operation on its own line.\n");
	
	while (1)
	{
		//get input
		fgets(instr, sizeof(instr), stdin);

		if (instr[0] == 'q')
			break;
		
		if (isdigit(instr[0])) //its a number of some sort (presumably)
		{
			sscanf(instr, "%lf", &temp);
			pdStack->push(temp);
		}
		else
		{
			switch (instr[0])
			{
			case '+':
				do_plus(pdStack);
				break;
			case '-':
				do_minus(pdStack);
				break;
			case '*':
				do_mult(pdStack);
				break;
			case '/':
				do_div(pdStack);
				break;
			default:
				printf("Input error %c\n", instr[0]);
			}
		}
	}

	delete pdStack;
	return 0;
}

void do_plus(Stack<double>* pStack)
{
	if (pStack->size() < 2)
	{
		printf("Stack error\n");
		return;
	}
			
    double temp = pStack->pop() + pStack->pop();
	print(temp);
	pStack->push(temp);
}

void do_minus(Stack<double>* pStack)
{
	if (pStack->size() < 2)
	{
		printf("Stack error\n");
		return;
	}
	
    double temp = pStack->pop() - pStack->pop();
	print(temp);
	pStack->push(temp);
}

void do_mult(Stack<double>* pStack)
{
	if (pStack->size() < 2)
	{
		printf("Stack error\n");
		return;
	}
	
    double temp = pStack->pop() * pStack->pop();
	print(temp);
	pStack->push(temp);
}

void do_div(Stack<double>* pStack)
{
	if (pStack->size() < 2)
	{
		printf("Stack error\n");
		return;
	}
	
	double divisor = pStack->pop();
    double temp = pStack->pop() / divisor;
	
	print(temp);
	pStack->push(temp);
}

void print(double num) //removes trailing zeros and prints
{
	char buf[32];
	snprintf(buf, sizeof(buf), "%g", num);

	char* ptr = &buf[0];
	ptr += 31;

	while (*ptr == '0')
		ptr--;

	ptr++;
	*ptr = '\0';

	printf("%s\n", buf);
}