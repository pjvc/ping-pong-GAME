#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

void cuadro(int x1, int y1, int  x2, int  y2);
void gotoxy(int x, int y)
{
	HANDLE hcon; 
 	hcon = GetStdHandle(STD_OUTPUT_HANDLE); 
 	COORD dwPos; 
 	dwPos.X = x; 
 	dwPos.Y= y; 
 	SetConsoleCursorPosition(hcon, dwPos); 
}
int a_1,h_2=0,ra=6;
void jugadores();
void linea(int x, int  y);
void pelota(int x,int y);
void borrarpelota(int x, int y);
int corx = 0,cory = 0 ,corx2,cory2;
void menu(char a);
int p1=0, p2=0;
int main() 
	{
	
	
	while(h_2 != 5){
	cuadro(1,0,99,24);
	menu( a_1);
	cuadro(1,0,99,24);
	gotoxy(46,26);
	cout<<"Puntos";
	gotoxy(5,0);
	cout<<"Jugador 1 se mueve con w,a,s,d";
	gotoxy(56,24);
	cout<<"Jugador 2 se mueve con las direccionles";
	jugadores();
	
	}
	return 0;
	}

void cuadro(int x1, int  y1, int x2, int y2)
{
	int x,y;
	for(x=x1;x<x2;x++)
	{
		gotoxy(x, y1);
		cout<<"-";
		gotoxy(x,y2);
		cout<<"-";
	}
	for(y=y1;y<y2;y++)
	{
		gotoxy(x1,y);
		cout<<"|";	
		gotoxy(x2,y);
		cout<<"|";
	}
	gotoxy(x1,y1);
	cout<<"+";
	gotoxy(x1,y2);
	cout<<"+";
	gotoxy(x2,y1);
	cout<<"+";
	gotoxy(x2,y2);
	cout<<"+";
	
	
}


void linea(int x,int y)
{
	gotoxy(x,y);
	printf("%c",219);
	gotoxy(x,y+1);
	printf("%c",219);
	gotoxy(x,y+2);
	printf("%c",219);
	corx= x;
	cory= y;
	
}
void linea2(int x,int y)
{
	gotoxy(x,y);
	printf("%c",219);
	gotoxy(x,y+1);
	printf("%c",219);
	gotoxy(x,y+2);
	printf("%c",219);
	corx2= x;
	cory2= y;
	
}



void vacio(int x,int y)
{
		gotoxy(x,y);
		cout<<" ";
		gotoxy(x,y+1);
		cout<<" ";
		gotoxy(x,y+2);
		cout<<" ";
		
		
}


void jugadores()
{
	int m=20,n=10,dm=1,dn=1,cont=0;
	p1= 0;
	p2= 0;
	pelota(m,n);
	int p=97,o=5;
	int dato,x=3,y=5;
	char opcion;
	linea(x,y);
	linea2(p,o);
	while(p1 !=5 && p2!=5)
	{
	
		for(int l=1;l<24;l++)
	{
		gotoxy(48,l);
		cout<<"|";
	}
		if(kbhit())
		{
			vacio(x,y);
			vacio(p,o);
			opcion= getch();
			switch(opcion)
			{
				case 'w': 
						if(y>1)
						y--;
						break;
				case 's': 
						if(y<21)
						y++;
						break;
				case 72:
						if(o>1)
						o--;
						break;
				case 80:
						if(o<21)
						o++;
						break;
			}
			linea2(p,o);
			linea(x,y);
			
		}
		Sleep(10);
		if (!cont++){
			borrarpelota(m,n);
			m+=dm;
			n+=dn;
			pelota(m,n);
			if(m==2||m==98)
			{
				borrarpelota(m,n);
				m=48;n=12;
				Sleep(500);
				dm=-dm;
				if(ra==2)
				{
					ra==7;	
				}	
				for(int l=1;l<24;l++)
				{
					gotoxy(48,l);
					cout<<" ";
				}
				
				gotoxy(45,12);
				cout<<"GOOOOOOOOOOL";
				Sleep(500);
				gotoxy(45,12);
				cout<<"            ";
				for(int l=1;l<24;l++)
				{
					gotoxy(48,l);
					cout<<"|";
				}
				
			}
			if(m==97)
			{
			  p1++;
			}
			if(m==3)
			{
				p2++;
			}
			
			if(n==1||n==23)
			{
				dn=-dn;
				
			}
			if ( (m+dm==corx) && (n==cory || n==cory+1 || n==cory+2))
			{
				dm=-dm;
				
			}
			if((m+dm==corx2) && (n==cory2 || n==cory2+1 || n==cory2+2))
			{
				dm=-dm;
			}
		}
		if(cont>ra)
		{
			cont=0;
		}
		
		gotoxy(1,26);
		cout<<"J1: "<<p1;
		gotoxy(80,26);
		cout<<"J2: "<<p2;
		gotoxy(36,28);
		cout<<"**El que meta 5 puntos gana**";
		if( p1==5)
		{
			system("cls");
			cuadro(1,0,99,24);
			gotoxy(45,12);
			cout<<"JUGADOR 1 WIN";
			Sleep(1000);
			gotoxy(30,17);
			cout<<"Presione cualquier tecla para regresar al menu";
			getch();
			system("cls");
			
		}
		if( p2==5 )
		{
			int b_2;
			system("cls");
			cuadro(1,0,99,24);
			gotoxy(45,12);
			cout<<"JUGADOR 2 WIN";
			Sleep(1000);
			gotoxy(30,17);
			cout<<"Presione cualquier tecla para regresar al menu";
			getch();
			system("cls");
			
		}
	}
}

void pelota(int x,int y)
{
	gotoxy(x,y);
	cout<<"*";
}

void borrarpelota(int x, int y)
{
	gotoxy(x,y);
	cout<<" ";
}

void escoger(int x, int y)
{
	gotoxy(x,y);
	cout<<">";
}	

void borrarmenu(int x, int y)
{
	gotoxy(x,y);
	cout<<" ";
	
		
		


}
void menu(char a)
{
	int num = 1;
	int x=37,y=14; 
	int m_1=0;
	char opcion;
	gotoxy(47,12);
	cout<<"PING PONG";
	gotoxy(38,14);
	cout<<"Jugar de 2";
	gotoxy(38,15);
	cout<<"Jugar contra la maquina";
	gotoxy(38,16);
	cout<<"Dificutad <"<<num <<">"; 
	escoger(x, y);
	while(m_1 != 5)
	{
		if (kbhit)
		{
			opcion = getch();
			borrarmenu(x, y);
			switch (opcion)
			{
				case 'w':
					if(y>14)
					{
						y--;
					}
					break;
				case 's':
					if(y<16)
					{
						y++;
					}
					break;
				case 'd':
					if(num<5)
					{
						num++;
						ra--;
					}
					break;
				case 'a':
					if(num>1)
					{
						num--;
						ra++;
					}
					break;
				case 13:
					m_1 = 5;
					break;
			}
			escoger(x, y);
			gotoxy(49,16);
			cout<<num;
		}
		
	}
	system("cls");
}

