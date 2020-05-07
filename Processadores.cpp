#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include<windows.h>
#include "Processadores.h"


//Processador,Nome do Arquivo,TipoProcesso,TempoExec
void DesenhaMoldura(int lini,int linf,int coli,int colf,int cort,int corf){

	textcolor(cort);textbackground(corf);
	
	gotoxy(coli,lini); printf("%c",201);
	
	for(int a=coli+1; a<colf ;a++){
		gotoxy(a,lini);printf("%c",205);
	}
	gotoxy(colf,lini);printf("%c",187);
	for(int a=lini+1; a<linf ;a++){
		gotoxy(colf,a);printf("%c",186);
	}
	gotoxy(colf,linf);printf("%c",188);
	for(int a=colf-1;a>coli;a--){
		gotoxy(a,linf);printf("%c",205);
	}
	gotoxy(coli,linf);printf("%c",200);
	for(int a=linf-1; a>lini ;a--){
		gotoxy(coli,a);printf("%c",186);
	}
}
int main(){
	
	system ("mode 80,180");
	DesenhaMoldura(1,61,1,80,8,0);//caixa maior
	DesenhaMoldura(3,5,5,75,8,0);//caixa com o TITULO	
	DesenhaMoldura(6,35,5,75,8,0);//caixa com o menu
	DesenhaMoldura(7,20,7,39,8,0);//caixa com os processos escolhidos
	DesenhaMoldura(21,34,7,39,8,0);//caixa com os processos escolhidos
	DesenhaMoldura(21,34,40,73,8,0);//caixa com os processos escolhidos
	DesenhaMoldura(7,20,40,73,8,0);//caixa com os processos escolhido
	DesenhaMoldura(36,60,3,78,8,0);//caixa em baixo de tudo
	setlocale(LC_ALL,"portuguese");
	
	TpProc p,p1,p2,p3,p4;
	TpRanking R;
	
	int cont[4];
	
	cont[0]=0,cont[1]=0,cont[2]=0,cont[3]=0;
	int ut=1,tempo,utControle;
	char auxtipo[50];
	int temp,aux=0;
	
	FILE *PtrArq = fopen("Processadores.txt","r");
	gotoxy(6,4);printf ("-----------------------PROCESSOS EM ATENDIMENTO----------------------");
	if (PtrArq == NULL)
	{
		printf ("Erro!");
	}
	else
	{
		Inicializar(p1);Inicializar(p2);Inicializar(p3);Inicializar(p4);
		InicializarR(R);

		do
		{
			ut++;			
			if(ut%2 == 0)
			{
				fscanf(PtrArq,"%d,%[^,],%[^,],%d\n",&p.proc,&p.nomearq,&p.tipoproc,&p.tempoexe);
				
/*------------------------------------------- PROCESSADOR 1 -------------------------------------------*/

				if(p.proc == 1)
				{
					tempo = p.tempoexe;
					Inserir(p1,tempo);
					
					strcpy(auxtipo,p.tipoproc);
					tempo = p.tempoexe;					
					InserirR(R,auxtipo,tempo);
					cont[0]++;
					//printf("%d,%s,%s,%d\n",p.proc,p.nomearq,p.tipoproc,p.tempoexe);	
				}
				
				if(!Vazia(p1))
				{
					//printf ("%d\n",p1.Fila[p1.inicio]);
					p1.Fila[p1.inicio]--;
					//printf ("%d\n",p1.Fila[p1.inicio]);
					if(p1.Fila[p1.inicio] == 0)
					{
						Retirar(p1);
					}
				}
				gotoxy(19,14);printf ("P: %d",cont[0]);Sleep(10);//Exibir(p1);
				gotoxy(16,13);printf("Processador 1");
/*------------------------------------------- PROCESSADOR 2 -------------------------------------------*/
	
				if(p.proc == 2)
				{
					tempo = p.tempoexe;
					Inserir(p2,tempo);
					
					strcpy(auxtipo,p.tipoproc);
					tempo = p.tempoexe;	
					InserirR(R,auxtipo,tempo);
					cont[1]++;
					//printf("%d,%s,%s,%d\n",p.proc,p.nomearq,p.tipoproc,p.tempoexe);
				}
				
				if(!Vazia(p2))
				{
					p2.Fila[p2.inicio]--;
					if(p2.Fila[p2.inicio] == 0)
					{
						Retirar(p2);
					}
				}
				gotoxy(54,14);printf ("P: %d",cont[1]);Sleep(10);//Exibir(p2);
				gotoxy(51,13);printf("Processador 2");
/*------------------------------------------- PROCESSADOR 3 -------------------------------------------*/

				if(p.proc == 3)
				{
					tempo = p.tempoexe;
					Inserir(p3,tempo);
					
					strcpy(auxtipo,p.tipoproc);
					tempo = p.tempoexe;	
					InserirR(R,auxtipo,tempo);
					cont[2]++;
					//printf("%d,%s,%s,%d\n",p.proc,p.nomearq,p.tipoproc,p.tempoexe);
				}
				
				if(!Vazia(p3))
				{
					p3.Fila[p3.inicio]--;
					if(p3.Fila[p3.inicio] == 0)
					{
						Retirar(p3);
					}
				}
				gotoxy(20,28);printf ("P: %d",cont[2]);Sleep(10);//Exibir(p3);
				gotoxy(17,27);printf("Processador 3");
/*------------------------------------------- PROCESSADOR 4 -------------------------------------------*/

				if(p.proc == 4)
				{
					tempo = p.tempoexe;
					Inserir(p4,tempo);
					
					strcpy(auxtipo,p.tipoproc);
					tempo = p.tempoexe;	
					InserirR(R,auxtipo,tempo);
					cont[3]++;
					//printf("%d,%s,%s,%d\n",p.proc,p.nomearq,p.tipoproc,p.tempoexe);
				}
				
				if(!Vazia(p4))
				{
					p4.Fila[p4.inicio]--;
					if(p4.Fila[p4.inicio] == 0)
					{
						Retirar(p4);
					}
				}
				gotoxy(54,28);printf ("P: %d",cont[3]);Sleep(10);//Exibir(p4);
				gotoxy(51,27);printf("Processador 3");
/*-----------------------------------------------------------------------------------------------------*/
			}			
		}while(!feof(PtrArq));
	}
	fclose(PtrArq);
	//system("cls");
	gotoxy(4,37);printf ("-------------------------RANKING DE PROCESSADORES-------------------------");
		gotoxy(5,39);printf ("Processador%d: %d",1,cont[0]);
		gotoxy(5,40);printf ("Processador%d: %d",2,cont[1]);
		gotoxy(5,41);printf ("Processador%d: %d",3,cont[2]);
		gotoxy(5,42);printf ("Processador%d: %d",4,cont[3]);
		gotoxy(5,46);printf ("[%d] foi o processador mais ocioso. Com apenas [%d] processos atendidos",4,cont[3]);
		gotoxy(5,47);printf ("[%d] foi o processador mais usado. Com [%d] processos atentidos",3,cont[2]);

		gotoxy(5,49);printf ("--------------------------PROCESSOS EXECUTADOS--------------------------");
	//Exibir(p1);
	Ordenar(R);
	ExibirR(R);
		gotoxy(5,58);printf ("------------------------------------------------------------------------");
	
	
		/*for(int i=0; i < 3; i++)
	{
		for(int j=i+1; j <= 3; j++)
		{
			if(cont[i] < cont[j])
			{
				aux = cont[i];
				cont[i] = cont[j];
				cont[j] = aux;
			}
		}
	}*/
	getch();
}
