#define MAXFILA 300

struct TpProc{
	char nomearq[50],tipoproc[50];
	int inicio,fim,tempoexe,proc;
	int Fila[MAXFILA];
};

struct TpRanking{
	char nomeP[50][100];
	int fim;
	int qtd[10];
	int tempo[10];
};

void Inicializar(TpProc &F){
	F.inicio = 0;
	F.fim = -1;
}

int Cheia(TpProc F){
	return F.fim - F.inicio +1 == MAXFILA;
}

int Vazia(TpProc F){
	return F.fim - F.inicio +1 == 0;
}

void Inserir(TpProc &F, int tempo){
	if (F.inicio != 0 && F.fim+1 == MAXFILA)
	{
		int qtd = F.inicio;
		for (int j=0; j < F.fim; j++)
		{
			F.Fila[F.inicio-qtd+j] = F.Fila[F.inicio+j];
		}
		F.inicio = F.inicio - qtd;
		F.fim = F.fim - qtd;
	}
	F.Fila[++F.fim] = tempo;
}

int Retirar (TpProc &F){
	return F.Fila[F.inicio++];
}

void Exibir(TpProc F){
	while(!Vazia(F))
	{
		printf ("%d",F.Fila[F.inicio]);
		
		F.Fila[F.inicio];
		Retirar(F);
	}
	//printf("P = %d\n",a);

}

//               RANKING

void InicializarR(TpRanking &r){
	r.fim=0;
	for(int i=0; i<= 10; i++)
	{
		r.qtd[i]=0;
		r.tempo[i]=0;
	}
}

int Buscae(TpRanking &r, char n[50], int t){
	int iae=0,i=0;
	while(i <= r.fim || strcmp(n,r.nomeP[i]) == 0)
	{
		if(strcmp(n,r.nomeP[i]) == 0)
		{
			iae=1;
			r.qtd[i]++;
			r.tempo[i] = r.tempo[i] + t;
		}
		i++;
	}
	return iae;
}

void InserirR(TpRanking &r, char n[50],int tp){
	int re;
	re = Buscae(r,n,tp);
	if(re == 0)
	{
		r.qtd[r.fim]++;
		r.tempo[r.fim] = tp;
		strcpy(r.nomeP[r.fim],n);
		r.fim++;
	}	
}

void Ordenar(TpRanking &r){
	int aux;
	for(int i=0; i < r.fim; i++)
	{
		for(int j=i+1; j <= r.fim; j++)
		{
			if(r.qtd[i] < r.qtd[j])
			{
				aux = r.qtd[i];
				r.qtd[i] = r.qtd[j];
				r.qtd[j] = aux;
			}
		}
	}
}

void ExibirR(TpRanking r){
	int tot=0;
	double media[5];
	double tempo,qtd;
	
	
	
	/*media[0] = (double)r.tempo[0] / r.qtd[0];
	media[1] = (double)r.tempo[1] / r.qtd[1];
	media[2] = (double)r.tempo[2] / r.qtd[2];
	media[3] = (double)r.tempo[3] / r.qtd[3];
	media[4] = (double)r.tempo[4] / r.qtd[4];
	printf ("Tempo médio: %lf\n",media[0]);
	printf ("Tempo médio: %lf\n",media[1]);
	printf ("Tempo médio: %lf\n",media[2]);
	printf ("Tempo médio: %lf\n",media[3]);
	printf ("Tempo médio: %lf\n",media[4]);*/
	
	for(int i=0; i < r.fim; i++)
	{
			gotoxy(4,50+i);printf ("Tipo de processo: %s |Qtd: %d |Tempo médio: %.2lf",r.nomeP[i],r.qtd[i], (double)r.tempo[i]/r.qtd[i]);
		tot+=r.qtd[i];
	}
		gotoxy(5,56);printf("Total de processes executados: %d",tot);
}






