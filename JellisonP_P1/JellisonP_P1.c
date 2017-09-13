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
void Result(int fail);
void Push(char c);
char Pop();

struct List
{
	char data;
	struct List* next;
};

struct List* top = NULL;
struct List* temp = NULL;

int main()
{
	FILE *file;
	fopen_s(&file, "MathExpressions.txt", "r");
	char mathExp[100];
	char mathStack[100];
	int linesNum = 0;
	if (file == NULL)
	{
		printf("error\n");
		return 0;
	}

	char buff[20];
	fgets(buff, 20, file);
	linesNum = (int)strtol(buff, NULL, 10);
	int fail = 0;
	for (int i = 0; i < linesNum; i++)
	{
		fail = 0;
		fgets(mathExp, 100, file);
		for (int j = 0; j < strlen(mathExp); j++)
		{
			int valid = Validate(mathExp[j]);
			if (valid == 1)
			{
				Push(mathExp[j]);
			}
			else if (valid == 2)
			{
				char c = Pop();
				if (c == '(' && mathExp[j] == ')')
				{
					continue;
				}
				if (c == '{' && mathExp[j] == '}')
				{
					continue;
				}
				if (c == '[' && mathExp[j] == ']')
				{
					continue;
				}
				else
				{
					printf("The string is invalid.\n\n");
					fail = 1;
					break;
				}
			}
		}
		Result(fail);
	}
	fclose(file);
	getchar();
	return 0;
}

void Result(int fail)
{
	if (fail == 1)
	{
		return;
	}
	if(temp == NULL)
	{
		printf("The string is valid\n\n");
	}
}

void Push(char c)
{
	temp = (struct List*)malloc(sizeof(struct List));

	temp->data = c;
	temp->next = top;
	top = temp;
}

char Pop()
{
	temp = top;
	char tempChar = temp->data;
	top = top->next;
	free(temp);
	temp = NULL;
	return tempChar;
}


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