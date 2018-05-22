#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
void main()
{
clrscr();
randomize();
int r,life=9,n,l;
char word1[]="the net    ",word2[]="eagle eye  ",word3[]="gamer      ",word4[]="this is it ",word5[]="salt       ",word6[]="hancock    ",word7[]="karate kid ",word8[]="step up    ";
r=random(8);
char word[11];
strcpy(word,NULL);
switch(r){
case(0):l=strlen(word1);
	strcpy(word,word1);
	break;
case(1):l=strlen(word2);
	strcpy(word,word2);
	break;
case(4):l=strlen(word5);
	strcpy(word,word5);
	break;
case(5):l=strlen(word6);
	strcpy(word,word6);
	break;
case(6):l=strlen(word7);
	strcpy(word,word7);
	break;
case(7):l=strlen(word8);
	strcpy(word,word8);
	break;
case(2):l=strlen(word3);
	strcpy(word,word3);
	break;
case(3):l=strlen(word4);
	strcpy(word,word4);
}
char dum[11];
strcpy(dum,NULL);
char tally[9];
strcpy(tally,"         ");
char c;
for(int i=0;i<l;++i)
{
if(word[i]!=' ')
dum[i]='_';
else
dum[i]=' ';
}
cout<<"This is a simple game of HOLLYWOOD the movie guessing game.\n";
cout<<"You wil have 9 lives to guess the name and\n you will enter one letter at a time";
cout<<"\n So lets begin.....\n";
cout<<"\n   Your movie is : ";
puts(dum);
cout<<"\n Incorrect letters entered : \t\t\t Lives left :9";
for(;life>0;)
{
again:
n=0;
cout<<"\n\n Enter a letter :";
cin>>c;
c=tolower(c);
for(int j=0;j<9;++j)
{
if(tally[j]==c){
cout<<"Letter already entered!!! Enter again..";
goto again;
}
}
for(int k=0;k<l;k++)
{
if(word[k]==c)
{
dum[k]=c;n+=1;
}}
if(n==0)
{
cout<<"Oops the letter is not there.";
tally[9-life]=c;
life-=1;
}
clrscr();
cout<<"\n     ";
puts(dum);
cout<<"\n Incorect letters : ";
puts(tally);
cout<<"\t\t\t\t  Lives left : "<<life;
if(strcmp(word,dum)==0)
{
cout<<"\n\n\t Congratulations you won";
getch();
exit(0);
}
}
cout<<"\n Better luck next time.\n The movie was :";
puts(word);
getch();
}