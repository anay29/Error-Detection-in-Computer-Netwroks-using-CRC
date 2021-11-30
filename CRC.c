#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *Receiver(char dividend[],char divisor[])
{
 int i,j,k,l,count=0;
 for(i=0;dividend[i]!='\0';)
 {
   for(j=0;j<strlen(divisor);j++)
    {
      if(dividend[i]==divisor[j])
       dividend[i]='0';
      else
       dividend[i]='1';
       i++;
    }
   k=0;
   while(dividend[k]!='1')
 {
   k++;
 }
  count=0;
  for(l=k;dividend[l]!='\0';l++)
  count++;
  if(strlen(divisor)>count)
  break;
  else
  i=k;
 }
 printf("Remainder is %s\n",dividend);
}
char *Sender(char dividend[],char divisor[])
{
 int i,j,k,l,count=0,bit,choice;
 char temp[100]={};
 char rem[100]={};
 char back_up_dividend[100]={};
 strcat(back_up_dividend,dividend);
 for(i=0;dividend[i]!='\0';)
 {
   for(j=0;j<strlen(divisor);j++)
    {
      if(dividend[i]==divisor[j])
       dividend[i]='0';
      else
       dividend[i]='1';
       i++;
    }
   k=0;
   while(dividend[k]!='1')
 {
   k++;
 }
  count=0;
  for(l=k;dividend[l]!='\0';l++)
  count++;
  if(strlen(divisor)>count)
  break;
  else
  i=k;
 }
 printf("Remainder is %s\n",dividend);
 j=strlen(dividend)-1;
 for(i=0;i<strlen(divisor)-1;i++)
 {
  temp[i]=dividend[j];
  j--;
 }
 j=0;
 for(i=strlen(temp)-1;i>=0;i--)
 {
   rem[j]=temp[i];
   j++;
 }
 printf("Remainder to be appended to the dividend is %s\n",rem);
 j=strlen(back_up_dividend)-1;
 for(i=strlen(rem)-1;i>=0;i--)
 {
    back_up_dividend[j]=rem[i];
    j--;
 }
 printf("Data sent to the receiver is %s\n",back_up_dividend);
 while(1)
 {
  printf("Enter 1 to introduce error and 0 for no error\n");
  scanf("%d",&choice);
 if(choice==0)
 {
  Receiver(back_up_dividend,divisor);
  break;
 }
 else if(choice==1)
  {
    printf("Enter the bit to introduce error\n");
    scanf("%d",&bit);
    if(back_up_dividend[bit]=='0')
    back_up_dividend[bit]='1';
    else
    back_up_dividend[bit]='0';
    Receiver(back_up_dividend,divisor);
    break;
  }
 else
 {
   printf("Please enter valid choice\n");
 }
 }
}
int main()
{
 char dividend[100]={};
 char divisor[100]={};
 char string[100]={};
 int i;
 printf("Enter the dividend\n");
 scanf("%s",dividend);
 printf("Enter the divisor\n");
 scanf("%s",divisor);
 for(i=0;i<strlen(divisor)-1;i++)
  {
    string[i]='0';
  }
 strcat(dividend,string);
 Sender(dividend,divisor);
}
