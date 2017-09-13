/*******************************
*Name: Payton Jellison
Date: 9/12/17
Assignment: Project 1 - Sequence and Order validation

WRITE DESCRIPTION OF PROGRAM HERE
	HERE
	HERE
Description:
Input:
Output:
Precondition:
Postcondition:
*/

#include <stdio.h>
#include <stdlib.h>
main();
void Result(char mathExp, char mathStack);
void Push(char mathStack, int top, char c);
void Pop(char mathStack, int top);
int main()
{
	FILE *file;
	fopen_s(&file, "MathExpressions.txt", "r");
	char mathExp[100];
	char mathStack[100];
	int linesNum = 0;
	int top = 0;
	fscanf_s(file, "%d", &linesNum);
	for (int i = 0; i <= linesNum; i++)
	{
		fscanf_s(file, "%s", mathExp);
		for (int j = 0; j < strlen(mathExp); j++)
		{
			if (Validate(mathExp[j]) == 1)
			{
				Push(mathStack, top, mathExp[j]);
			}
			else if (Validate(mathExp[j]) == 2)
			{
				Pop(mathStack, top);
			}
			else
			{
				printf("Invalid character.");
			}
		}
	}
	fclose(file);
	Result(mathExp, mathStack);
}

void Result(char mathExp, char mathStack)
{
	if (strlen(mathExp) == strlen(mathStack))
	{
		printf("The string is valid");
	}
	else
	{
		printf("The string is invalid");
	}
}

void Push(char mathStack, int top, char c)
{
	top++;
	mathStack[&top] == c;
}

void Pop(char mathStack, int top)
{
	int temp = top;
	top--;
	mathStack[&temp] = '\0';
}

//void Peek(char mathExp[], int top)
//{
//	return mathExp[top];
//}
int Validate(char c)
{
	if (c == '(' || c == '{' || c == '[')
	{
		return 1;
	}
	else if (c == ')' || c == '}' || c == ']')
	{
		return 2;
	}
	else
	{
		return 3;
	}
}