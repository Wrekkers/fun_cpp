#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<iostream.h>
#include<conio.h>
#include<process.h>
struct player
{
	int atk,def,hp;
	char sp;
}p[2];
int p_turn,a;
void win()
{
	if(p[0].hp<=0)
		{
		cout<<"\n Player 2 wins";
		getch();
		exit(0);
		}
	else if(p[1].hp<=0)
		{
		cout<<"\n Player 1 wins";
		getch();
		exit(0);
		}
}
void attack()
{
randomize();
if(p_turn==1)
		p[1].hp-=(p[0].atk-random(7)+5)-(p[1].def-random(7)+5);
else
		p[0].hp-=(p[1].atk-random(7)+5)-(p[0].def-random(7)+5);
}
void special()
{
randomize();
if(p_turn==1)
{
	switch(p[0].sp)
	{
		case 'k':if((random(100)+1)%2==0)
			{
				p[1].hp-=0.5*(p[1].hp);
				cout<<"Critical hit press any key to continue";
				getch();
			}
			break;
		case 'd':if((random(100)+1)%4==0)
			{
				p_turn=2;
				cout<<"Miss a turn press any key to continue";
				getch();
			}	
			break;
		case 'f':if((random(100)+1)%4==0)
			{
				p[1].hp=0;
				cout<<"Fatal Attack press any key to continue";
				getch();
			}
			break;
		case 'w':if((random(100)+1)%2==0)
			{
				
				if(p[1].hp<=25)
					p[0].hp+=0.5*(p[0].hp);
				else if(p[0].hp>=25)
					p[0].hp=50;
				cout<<"It healed your hp press any key to continue";
				getch();
			}
			break;
		case 'a':if((random(100)+1)%2==0)
				a=1;
			break;
		case 'e':if((random(100)+1)%2==0)
			{
				p[0].def+=10;
				cout<<"Defence increased press any key to continue";
				getch();
			}
			break;
		case 'n':if((random(100)+1)%4==0)
			{
				p[1].hp=0;
				cout<<"Fatal attack press any key to continue";
				getch();
			}
			break;
		case 'c':if((random(100)+1)%2==0)
			{
				p[1].hp-=20;
				cout<<"Critical hit press any key to continue";
				getch();
			}
			else
			{
				p[1].hp-=10;
				cout<<"Minor hit press any key to continue";
				getch();
			}
			break;
		case 's':if((random(100)+1)%4==0)
			{
				p[1].hp-=30;
				cout<<"Critical hit press any key to continue";
				getch();
			}
			else if((random(100)+1)%2==0)
			{
				p[1].hp-=10;
				cout<<"Minor hit press any key to continue";
				getch();
			}
			else
			{
				cout<<"No hit";
				getch();
			}
			break;
		case 'b':if((random(100)+1)%2==0)
			{
				p[1].hp-=25;
				cout<<"Critical hit press any key to continue";
				getch();
			}
			else
			{
				p[1].hp-=15;
				cout<<"Minor hit press any key to continue";
				getch();
			}
	}
}
else
{
	switch(p[1].sp)
	{
		case 'k':if((random(100)+1)%2==0)
			{
				p[0].hp-=0.5*(p[0].hp);
				cout<<"Critical hit press any key to continue";
				getch();
			}
			break;
		case 'd':if((random(100)+1)%4==0)
			{
				p_turn=1;
				cout<<"Miss a turn press any key to continue";
				getch();
			}	
			break;
		case 'f':if((random(100)+1)%4==0)
			{
				p[0].hp=0;
				cout<<"Fatal Attack press any key to continue";
				getch();
			}
			break;
		case 'w':if((random(100)+1)%2==0)
			{
				if(p[1].hp<=25)
					p[1].hp+=0.5*(p[1].hp);
				else if(p[1].hp>=25)
					p[1].hp=50;
				cout<<"It healed your hp press any key to continue";
				getch();
			}
			break;
		case 'a':if((random(100)+1)%2==0)
				a=1;
			break;
		case 'e':if((random(100)+1)%2==0)
			{
				p[1].def+=10;
				cout<<"Defence increased press any key to continue";
				getch();
			}
			break;
		case 'n':if((random(100)+1)%4==0)
			{
				p[0].hp=0;
				cout<<"Fatal attack press any key to continue";
				getch();
			}
			break;
		case 'c':if((random(100)+1)%2==0)
			{
				p[0].hp-=20;
				cout<<"Critical hit press any key to continue";
				getch();
			}
			else
			{
				p[0].hp-=10;
				cout<<"Minor hit press any key to continue";
				getch();
			}
			break;
		case 's':if((random(100)+1)%4==0)
			{
				p[0].hp-=30;
				cout<<"Critical hit press any key to continue";
				getch();
			}
			else if((random(100)+1)%2==0)
			{
				p[0].hp-=10;
				cout<<"Minor hit press any key to continue";
				getch();
			}
			else
			{
				cout<<"No hit";
				getch();
			}
			break;
		case 'b':if((random(100)+1)%2==0)
			{
				p[0].hp-=25;
				cout<<"Critical hit press any key to continue";
				getch();
			}
			else
			{
				p[0].hp-=15;
				cout<<"Minor hit press any key to continue";
				getch();
			}
	}
}
}
void play()
{
	char move;
	for(;;)
	{
	ag:
	clrscr();
	cout<<"PLAYER 1\t\t\t\t\tPLAYER 2";
	cout<<"\n\n HP : "<<p[0].hp<<"                                         HP : "<<p[1].hp;
	cout<<"\n Attack : "<<p[0].atk<<"\t\t\t\t         Attack : "<<p[1].atk;
	cout<<"\n Defence :"<<p[0].def<<"\t\t\t\t         Defence :"<<p[1].def;
	win();
	cout<<"\n\n PLAYER "<<p_turn<<" Your move enter a for attack or s to use special abality :";
	cin>>move;
	if(move=='a')
	{
		if(a==1)
		{	
			p[p_turn-1].hp-=(p[p_turn-1].atk-random(7)+5)-(p[p_turn-1].def-random(7)+5);
			cout<<"Your attack was deflected on you press any key to continue";
			getch();
			a=0;
		}
		else
			attack();
	}
	else if(move=='s')
		special();
	else
	{
		cout<<"Wrong move press any key to enter again";
		getch();
		goto ag;
	}
	if(p_turn==1)
		p_turn=2;
	else
		p_turn=1;
	}
}
void selection()
{	char sim;
	for(int i=0;i<2;i++)
	{
		again:
		clrscr();
		cout<<"\t\t PLAYER "<<i+1<<" character selection";
		cout<<"\n\n===============================================================================\n";
		cout<<"|  Character        | Attack | Defence |        Special Ability        | HP   |\n";
		cout<<"===============================================================================\n";
		cout<<"|  KNIGHTS                                                                    |\n";
		cout<<"===============================================================================\n";
		cout<<"|  Knight           |  15+   |   6+    |   Has 50% chance of reducing  | 70   |\n";
		cout<<"|                   |        |         |    1/2 of the remaing HP      |      |\n";
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"|  Swordsman        |  10+   |   10+   |   Has 20% chance of knocking  | 50   |\n";
		cout<<"|                   |        |         |   out the enemy(miss a turn)  |      |\n";
		cout<<"===============================================================================\n";
		cout<<"|  MAGES                                                                      |\n";
		cout<<"===============================================================================\n";
		cout<<"|  Fire             |  20+   |   1+    |   Has 20% chance of giving    | 50   |\n";
		cout<<"|                   |        |         |        fatal attack           |      |\n";
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"|  Water            |  17+   |   1+    |    Has 50% chance of healing  | 50   |\n";
		cout<<"|                   |        |         |     1/2 of the remaining HP   |      |\n";
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"|  Air              |  17+   |   1+    | Has 50% chance of deflecting  | 50   |\n";
		cout<<"|                   |        |         |  damage done in next turn     |      |\n";
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"|  Earth            |  16+   |   2+    |  Has 50% chance of increasing | 50   |\n";
		cout<<"|                   |        |         |          defence by 10        |      |\n";
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"|  Nacromancer      |  20+   |   0+    |    Has 34% chance of giving   | 50   |\n";
		cout<<"|                   |        |         |        fatal attack           |      |\n";
		cout<<"===============================================================================\n";
		cout<<"|  RANGERS                                                                    |\n";
		cout<<"===============================================================================\n";
		cout<<"|  Cavelry Archer   |   8+   |   4+    | Has 50% chance of inflicting  | 70   |\n";
		cout<<"|                   |        |         |        20 or 10 damage        |      |\n";
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"|  Skimisher        |   7+   |   8+    |   Has 25% or 50% chance of    | 50   |\n";
		cout<<"|                   |        |         | inflicting 30 or 10 damage    |      |\n";
		cout<<"-------------------------------------------------------------------------------\n";
		cout<<"|  Bowman           |   6+   |   7+    | Has 50% chance of inflicting  | 50   |\n";
		cout<<"|                   |        |         |        25 or 15 damage        |      |\n";
		cout<<"===============================================================================\n";
		cout<<"\n\nEnter k to select from Knights m from mages or r from rangers :";
		cin>>sim;
		sim=tolower(sim);
		switch(sim)
		{
		case 'k':cout<<"Enter k to select knight or s to select swordsman :";
			cin>>sim;
			sim=tolower(sim);
			switch(sim)
			{
			case 'k':p[i].atk=15;p[i].def=6;p[i].hp=70;p[i].sp='k';
				break;
			case 's':p[i].atk=10;p[i].def=10;p[i].hp=50;p[i].sp='d';
				break;
			default:cout<<"Wrong selection press any key to select again";
			       getch();
			       goto again;
			}
			break;
		case 'm':cout<<"Enter f to select fire w to select water a to select air e select earth\n or n to select nacromancer :";
			cin>>sim;
			sim=tolower(sim);
			switch(sim)
			{
			case 'f':p[i].atk=20;p[i].def=1;p[i].hp=50;p[i].sp='f';
				break;
			case 'w':p[i].atk=17;p[i].def=1;p[i].hp=50;p[i].sp='w';
				break;
			case 'a':p[i].atk=17;p[i].def=1;p[i].hp=50;p[i].sp='a';
				break;
			case 'e':p[i].atk=16;p[i].def=2;p[i].hp=50;p[i].sp='e';
				break;
			case 'n':p[i].atk=20;p[i].def=0;p[i].hp=50;p[i].sp='n';
			break;
			default:cout<<"Wrong selection press any key to select again";
			       getch();
			       goto again;
			}
			break;
		case 'r':cout<<"Enter c to select cavelry archer s to select skimisher or b to select Bowman :";
			cin>>sim;
			sim=tolower(sim);
			switch(sim)
			{
			case 'c':p[i].atk=8;p[i].def=4;p[i].hp=70;p[i].sp='c';
				break;
			case 's':p[i].atk=7;p[i].def=8;p[i].hp=50;p[i].sp='s';
				break;
			case 'b':p[i].atk=6;p[i].def=7;p[i].hp=50;p[i].sp='b';
				break;
			default:cout<<"Wrong selection press any key to select again";
			       getch();
			       goto again;
			}
			break;
		default:cout<<"Wrong selection press any key to select again";
		       getch();
		       goto again;
		}
	}
}
void main()
{
clrscr();
selection();
turn:
clrscr();
cout<<"Who goes first ? :";
cin>>p_turn;
if(p_turn != 1)
{
	if(p_turn != 2)
	{
	cout<<"Press any key to enter again :";
	getch();
	goto turn;
	}
}
play();
}