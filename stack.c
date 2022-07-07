#include<stdio.h>
#include<string.h>
#include "mystack.h"


int main()
{
    char str[20], pstr[20],ch;
    int i, k=0;

    printf("Enter");
    gets(str);

    initstack();
    for(i=0; str[i]!='\0'; i++)
    {
        if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            pstr[k++]=str[i];
        else
            switch(str[i])
            {
                case '(': case '+': case '-': case '*': case '/': 
                     push(str[i]);
                     break;

                case ')': ch=pop();
                          while(ch != '(')
                          {
                              pstr[k++]=ch;
                              ch=pop();
                          } //end of while
                          break;
            }    //end of switch
            
    }  //end of for
    pstr[k]='\0';
    printf("\nPostfix expression= %s", pstr);

}   //end of main