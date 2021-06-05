/*
**********  9th task on  Algorithm course                                    ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date           28.05.2021                                        ****
**********  Modified date  30.05.2021                                        ****
*/

//

//+- Описать очередь с приоритетным исключением  in progress
//DONE● Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.




#include <stdio.h>
#include <stdbool.h>

//*************************************
//***** очередь и функции для нее
#define SZ 10

typedef struct 
   {
    int pr;
    int dat;
    
    }Node; 
Node* arr[SZ];
int head;
int tail;
int items;

void init()
    {
     for (int i=0;i<SZ;++i)
        {
         arr[i]=NULL;
         }
      head=0;
      tail=0;
      items=0;
    }
void ins(int pr, int dat)
{
   Node *node =(Node*) malloc (sizeof(Node));
   node->dat=dat;
   node->pr=pr;
   if(items==0)
      {
       arr[tail] = node;
       items++;
       //return;
       }
   else
      {
       if(items==SZ)
            {
              printf("%s \n", "Queue is full");
              return;
             }
       else
            {
              arr[++tail]=node;
              items ++;

            }

      }
}

Node* rem()
 {
  int flag=head;
  int i=0;
  int idx=0;
  if(items==0)
     {
      printf ("queue is empty");
     return NULL;
     }
  else
     {
      printf ("Head->Tail search");


      printf("\nSearching flag value\n");

      for(i=head; i<tail-1;++i)
        {

          idx=i%SZ;
           if(arr[flag]->pr<arr[idx+1]->pr)
             {

              //printf("[%d,%d]",arr[flag]->pr,arr[flag]->dat);
              //printf(":::VERSUS:::");
              //printf("[%d,%d]",arr[idx+1]->pr,arr[idx+1]->dat);
              flag=idx+1;
              //printf("\nFlag: %d",flag);
              //printf("\nIndex: %d\n",idx);
           }
            else
              {
               //printf("[%d,%d]",arr[flag]->pr,arr[flag]->dat);
               //printf(":::VERSUS:::");
               //printf("[%d,%d]",arr[idx+1]->pr,arr[idx+1]->dat);
               //printf("flag stays same\n");
              }
          }
         //printf("\nHead: %d tail:%d items%d\n",head, tail, items);
         printf("Removing item [%d,%d]\n",arr[flag]->pr,arr[flag]->dat);

      }

  Node *tmp=arr[flag];

  i=flag;

  while(i<=tail)
     {
      idx=i%SZ;
      arr[idx]=arr[idx+1];
      i++;
      }
  arr[tail]=NULL;
  items--;
  tail--;
  if(tail<0) tail=0;

  return tmp;
}

void printQueue()
 {
  printf("[");
  for(int i=0;i<SZ;++i)
     {
       if(arr[i]==NULL)
          {
           printf("[*,*]");
          }
       else
         {
          printf("[%d,%d]",arr[i]->pr,arr[i]->dat);
         }
       }
    printf("]\n");
 }
//***** очередь и функции для нее
//*************************************


//*************************************
//***** стек и функции для него
#define T int //char
#define SIZE 1000
#define true 1==1
#define false 1!=1

typedef int boolean;
int cursor=-1;

T Stack[SIZE];
boolean push(T data)
   {
     if(cursor<SIZE)
      {
        Stack[++cursor]=data;
        return true;
      }
     else
      {
        printf("%s \n","Stack overflow");
        return false;
      }
   }

T pop()
   {
    if(cursor !=-1)
       {
        return Stack[cursor--];
       }
    else
      {
        printf("%s \n", "stack is empty");
        return -1;
       }
   }

//***** стек и функции для него
//*************************************


int main()
{
//*************************************
//***** очередь и функции для нее
  init();
  ins(1,11);
  ins(3,22);
  ins(4,33);
  ins(2,44);
  ins(3,55);
  ins(4,66);
  ins(5,77);
  ins(1,100);
  ins(5,115);
  ins(5,77);
  printf("\nHead: %d tail:%d items%d\n",head, tail, items);
  printQueue();
  for(int i=0;i<5;++i)
     {
      Node* n=rem();
      printf("pr=%d,dat=%d \n",n->pr,n->dat );
      printf("\nHead: %d tail:%d items%d\n",head, tail, items);
      printQueue();
     }
  ins(4,66);
  ins(5,77);
  ins(1,100);
  printf("\nHead: %d tail:%d items%d\n",head, tail, items);
  printQueue();


//***** очередь и функции для нее
//*************************************

//*************************************
//***** стек и функции для него
//push('a');
//push('b');
//push('c');
//push('d');
//push('e');
//push('f');
//push('g');
int x=0;
printf("Please enter you digit (positive int): ");
scanf("%d",&x);

if(x==0)
  {
   printf("\nSo nothing to modify.... 0 is 0\n");
   }
else
  {
    while (x > 0)
       {
         push(x%2);
         x /= 2;
        }
    printf("Your modified digit after function dec into binary will be: ");
    while (cursor!=-1)
       {
        printf("%d" , pop());
       }
}

printf("\n");


//***** стек и функции для него
//*************************************



  return 0;
}
