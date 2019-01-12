//mfarazsohail

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE_LENGTH 80

int searchByLength(char text[][MAX_LINE_LENGTH], int n, int wordLen); //prototype for search by length
int searchByWord(char text[][MAX_LINE_LENGTH], int n, char * keyword);//prototype for search by word
int searchByCharacter(char text[][MAX_LINE_LENGTH], int n,char ch); //prototype for search by character
void readText (char text[][MAX_LINE_LENGTH], int n); //prototype for reading text

int main()
{
  int n,A,B,C;
  char text[100][MAX_LINE_LENGTH],keyword[100];
  char c;
  while(1)
{
  printf("Enter number of lines(<10):");
  scanf("%d",&n);
  if(n>10||n<0)
    {printf("Invalid Input\n");
      continue;}
  else
        break;
}
readText(text,n); // func call for getting strings
while(1)
{
  int b;
  printf("\nText Analysis \n ----- \n 1-Search By Character\n 2-Search By Word\n 3-Search By Length\n 0-Quit\n" ); //Menu
  printf("Please enter a selection:");
  scanf("%d",&b);
  if(b==0)
    break;
  else if(b==1)
    {
	    printf("Enter a character to search : " );
	    scanf(" %c", &c);
		A=searchByCharacter(text,n,c);
  		printf("Number of occurence= %d\n",A);
    		break;}
  else if(b==2)
    {
		printf("Enter a keyword(less than 20 characters): ");
		scanf("%s",keyword);
		B=searchByWord(text,n,keyword);
		printf("Number of occurences=%d\n",B);
    break;}
  else if(b==3)
    {
	    int wordLen;
	    printf("Enter search length: ");
	  	scanf("%d",&wordLen);
		C=searchByLength(text,n,wordLen);
		printf("Number of words with length=%d\n",C);
    	break;
	}
  else
    {
		printf("Invalid input");
    	continue;
	}

  }

  return 0;
}

void readText(char text[][MAX_LINE_LENGTH],int n)
{
  for(int i=0;i<=n;i++)
  {
    gets(text[i]);
  }
}

int searchByCharacter(char text[][MAX_LINE_LENGTH], int n,char ch)
{
	int count=0;
	char textc[100]={0},*pch;
	 for(int i=0;i<=n;i++)
				 {
					  strcpy(textc,text[i]);
					  pch=strchr(textc,ch);
					  while(pch!=NULL)
					  {
						   count++;
	                       pch=strchr(pch+1,ch);
					  }
				 }
				 return count;
}

int searchByWord(char text[][MAX_LINE_LENGTH], int n,char * keyword)
{
 	int count=0;
 	char textw[100]={0},*ptra;
 for(int i=0;i<=n;i++)
      {
         strcpy(textw,text[i]);
         ptra=strstr(textw,keyword);
         while(ptra!=NULL)
         {
            count++;
                      ptra=strstr(ptra+1,keyword);
         }
      }
  
  return count;
}

int searchByLength(char text[][MAX_LINE_LENGTH], int n,int wordLen)
{
  
int count=0;
  char text1d[100]={0},*tokenptr, * DelimList=" .,;:$";
  char a[100];
  for(int i=0;i<=n;i++)
  {
    strcpy(text1d,text[i]);
    tokenptr=strtok(text1d, DelimList);
    while(tokenptr!=NULL)
    {
       strcpy(a,tokenptr);
       if(strlen(a)==wordLen)
       count++;
       tokenptr=strtok(NULL, DelimList);
    }
  }
    
    return count;
}
