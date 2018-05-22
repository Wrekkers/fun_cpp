#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
void main()
{
clrscr();
char name1[30],name2[30];
cout<<"\t\t\t\t   CROSS 'N KNOTS \n\n\n";
cout<<"\t      RULES\n\n";
cout<<"\tcol1 col2 col3\n";
cout<<"  row1 ____|____|____\n";
cout<<"  row2 ____|____|____\n";
cout<<"  row3     |    |    \n\n\n\n";
int r,c,p;
char ar[3][3];
for(int i=0;i<3;++i){
for(int j=0;j<3;++j)
ar[i][j]=' ';
cout<<"Enter the name of 1st player :";
gets(name1);
cout<<"Enter the name of 2nd player :";
gets(name2);
}
cout<<"   PLAYER 1-X\n";
cout<<"   PLAYER 2-O\n";
for(int t=1;t<=9;++t)
{
if(t%2 !=0)
p=1;
else
p=2;
cout<<"\n Player "<<p<<" enter row :";
cin>>r;r-=1;
cout<<"         enter column :";
cin>>c;c-=1;
if(r>=3||r<=-1||c>=3||c<=-1||ar[r][c]!=' ')
{
cout<<"Place already filled or invalid row or column!!! Enter again....";
t-=1;
goto last;
}
else{
if(p==1)
ar[r][c]='X';
else
ar[r][c]='O';
}
clrscr();
cout<<"\t\t\t\t   CROSS 'N KNOTS \n\n\n";
cout<<"\t      RULES\n\n";
cout<<"\tcol1 col2 col3\n";
cout<<"  row1 ____|____|____\n";
cout<<"  row2 ____|____|____\n";
cout<<"  row3     |    |    \n\n\n\n";
{for(int i=0;i<3;++i)
{cout<<'\t';
for(int j=0;j<3;++j){
cout<<ar[i][j];
if(j<2)
cout<<'|';}
if(i<2)
cout<<"\n\t-----\n";
}}
if(ar[0][0]==ar[0][1] && ar[0][2]==ar[0][1] && ar[0][0]!=' ')
{
if(p==1)
cout<<"\n\n\t PLAYER 1 wins!!!!!!!";
else
cout<<"\n\n\t PLAYER 2 wins!!!!!!!";
getch();
exit(0);
}
if(ar[1][0]==ar[1][1] && ar[1][2]==ar[1][1] && ar[1][0]!=' ')
{
if(p==1)
cout<<"\n\n\t PLAYER 1 wins!!!!!!!";
else
cout<<"\n\n\t PLAYER 2 wins!!!!!!!";
getch();
exit(0);
}if(ar[2][0]==ar[2][1] && ar[2][2]==ar[2][1] && ar[2][0]!=' ')
{
if(p==1)
cout<<"\n\n\t PLAYER 1 wins!!!!!!!";
else
cout<<"\n\n\t PLAYER 2 wins!!!!!!!";
getch();
exit(0);
}if(ar[0][1]==ar[1][1] && ar[2][1]==ar[1][1] && ar[0][1]!=' ')
{
if(p==1)
cout<<"\n\n\t PLAYER 1 wins!!!!!!!";
else
cout<<"\n\n\t PLAYER 2 wins!!!!!!!";
getch();
exit(0);
}if(ar[1][0]==ar[0][0] && ar[2][0]==ar[1][0] && ar[0][0]!=' ')
{
if(p==1)
cout<<"\n\n\t PLAYER 1 wins!!!!!!!";
else
cout<<"\n\n\t PLAYER 2 wins!!!!!!!";
getch();
exit(0);
}if(ar[0][2]==ar[1][2] && ar[2][2]==ar[0][2] && ar[0][2]!=' ')
{
if(p==1)
cout<<"\n\n\t PLAYER 1 wins!!!!!!!";
else
cout<<"\n\n\t PLAYER 2 wins!!!!!!!";
getch();
exit(0);
}if(ar[0][0]==ar[1][1] && ar[2][2]==ar[1][1] && ar[0][0]!=' ')
{
if(p==1)
cout<<"\n\n\t PLAYER 1 wins!!!!!!!";
else
cout<<"\n\n\t PLAYER 2 wins!!!!!!!";
getch();
exit(0);
}if(ar[2][0]==ar[1][1] && ar[0][2]==ar[1][1] && ar[0][2]!=' ')
{
if(p==1)
cout<<"\n\n\t PLAYER 1 wins!!!!!!!";
else
cout<<"\n\n\t PLAYER 2 wins!!!!!!!";
getch();
exit(0);
}
last:
}
cout<<"\n\n\t It was a tie.";
getch();
}