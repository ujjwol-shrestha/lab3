//Checking Validity
//ujjwol shrestha
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define loop for(i=0;i<strlen(exp);i++)

typedef struct
{
	int top;
	int items[MAX];
}stack;



void push (stack*,char);
char pop (stack*);
int validity(char exp[]);
int isMatchingPair(char);


int main()
{
	char exp[100];

	printf ("Enter an expression \n");
	gets(exp);

	printf ("%s \n", exp);

	validity(exp);

	getch();

}


//function for push

void push (stack *s,char x)
{
	if (s->top==(MAX-1))
	{
		printf("Stack Overflow\n");

	}else{
		++(s->top);
		s->items[s->top]=x;
	}
}


//function for pop
char pop (stack *s)
{
	if (s->top==-1)
	{
		printf("Stack Underflow");
		exit(0);
	}else{
	return s->items[s->top--];
}
}

//function to check the validity
int validity(char exp[]){
		stack s;
	s.top=-1;
	int i,valid=1;
	char symb,x,y;
	loop{
	//	printf("%c\a",exp[i]);
		symb = exp[i];

		if (symb == '(' || symb == '[' || symb == '{') {
			push(&s, symb);
		}
		if (symb == ')' || symb == ']' || symb == '}') {
			if (s.top == -1) {
				valid = 0;
			} else if (isMatchingPair!=exp[i] ){

				pop(&s);

           return 0;
		      }
			}
			}
		}


//	loop{
//		printf("%c\a",exp[i]);
//		symb=exp[i];

//		if(symb=='(' || symb=='[' || symb=='{')
//		{
//			push(&s,symb);
//		}
//
//		if(symb==')' || symb==']' || symb=='}')
//			if	(s.top == -1)
//				valid=0;
//			else
//			{
//				if (ismatching_opener(symb)) {
//					valid = 0;
//
//				}
//			}
//	}
	if(s.top != -1){

		valid=0;
	}
	if (valid == 1){
	printf("The Given Expression is Valid\n");
	}else{
	printf("The Given Expression is not Valid\n");
	}
}

int isMatchingPair(char character1, char character2)
{
   if(character1 == '(' && character2 == ')')
     return 1;
   else if(character1 == '{' && character2 == '}')
     return 1;
   else if(character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}

int matching_opener(char symb) {

	stack s;
	int i;
	i = pop(&s);

	return ((symb == ')' && i != '(') || (symb == '}' && i != '{') || (symb == ']' && i != '['));
}






