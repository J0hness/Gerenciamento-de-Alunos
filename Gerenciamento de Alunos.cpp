#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

#define TFA 20
#define TFD 10
#define TFN 50

struct TpAluno{
	char RA[13], Nome[30];
};

struct TpDisc{
	int Cod;
	char Descr[40];
};

struct TpNota{
	char NotaRA[13];
	int CodDisc;
	float Nota;
};

void Moldura(int CI, int LI, int CF, int LF, int corTXT, int corFundo){ //moldura----------------->
	int i;
	textcolor(corTXT);
	textbackground(corFundo);
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
		Sleep(5);
	}
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
		Sleep(5);
	}
	textcolor(7);
	textbackground(0);
}

void Clear(void){ //Limpar tela---------------------->
	int i, j;
	for(i=2;i<80;i++)
		for(j=2;j<25;j++)
		{
			gotoxy(i,j);
			printf(" "); 
		}
}

void Inicializacao(TpAluno A[TFA], TpDisc D[TFD], TpNota N[TFN], int &TA, int &TD, int &TN){
	strcpy(A[0].RA, "262228343");
	strcpy(A[0].Nome, "Joao Gabriel Moreno");
	strcpy(A[1].RA, "262227380");
	strcpy(A[1].Nome, "Joao Gabriel da Silva");
	strcpy(A[2].RA, "262228084");
	strcpy(A[2].Nome, "Jean Marcelo");
	strcpy(A[3].RA, "262227614");
	strcpy(A[3].Nome, "Victor Hugo");	
	TA=4;
	
	D[0].Cod = 1;
	strcpy(D[0].Descr, "ATP II");
	D[1].Cod = 2;
	strcpy(D[1].Descr, "Arquitetura de Computadores");
	D[2].Cod = 3;
	strcpy(D[2].Descr, "Ciencia de Dados");
	D[3].Cod = 4;
	strcpy(D[3].Descr, "Gestao Financeira");
	TD=4;
	
	N[TN].CodDisc = 1;
	N[TN].Nota = 9.5;
	strcpy(N[TN].NotaRA, "262228084");
	TN++;
	N[TN].CodDisc = 2;
	N[TN].Nota = 10;
	strcpy(N[TN].NotaRA, "262228084");
	TN++;
	N[TN].CodDisc = 3;
	N[TN].Nota = 5;
	strcpy(N[TN].NotaRA, "262228084");
	TN++;
	N[TN].CodDisc = 4;
	N[TN].Nota = 9;
	strcpy(N[TN].NotaRA, "262228084");
	TN++;
	N[TN].CodDisc = 1;
	N[TN].Nota = 8;
	strcpy(N[TN].NotaRA, "262227380");
	TN++;
	N[TN].CodDisc = 2;
	N[TN].Nota = 4;
	strcpy(N[TN].NotaRA, "262227380");
	TN++;
	N[TN].CodDisc = 3;
	N[TN].Nota = 10;
	strcpy(N[TN].NotaRA, "262227380");
	TN++;
	N[TN].CodDisc = 4;
	N[TN].Nota = 6;
	strcpy(N[TN].NotaRA, "262227380");
	TN++;
	N[TN].CodDisc = 1;
	N[TN].Nota = 6;
	strcpy(N[TN].NotaRA, "262228343");
	TN++;
	N[TN].CodDisc = 2;
	N[TN].Nota = 8;
	strcpy(N[TN].NotaRA, "262228343");
	TN++;
	N[TN].CodDisc = 3;
	N[TN].Nota = 2;
	strcpy(N[TN].NotaRA, "262228343");
	TN++;
	N[TN].CodDisc = 4;
	N[TN].Nota = 10;
	strcpy(N[TN].NotaRA, "262228343");
	TN++;
	N[TN].CodDisc = 1;
	N[TN].Nota = 10;
	strcpy(N[TN].NotaRA, "262227614");
	TN++;
	N[TN].CodDisc = 2;
	N[TN].Nota = 3;
	strcpy(N[TN].NotaRA, "262227614");
	TN++;
	N[TN].CodDisc = 3;
	N[TN].Nota = 9;
	strcpy(N[TN].NotaRA, "262227614");
	TN++;
	N[TN].CodDisc = 4;
	N[TN].Nota = 8;
	strcpy(N[TN].NotaRA, "262227614");
	TN++;
}

int BuscaAlu(TpAluno A[TFA], int qtde, char RA[13]){//Busca de Alunos ------------>
	int i=0;
	while(i<qtde && strcmp(RA, A[i].RA)!=0)
		i++;
	if(i<qtde)
		return i;
	else
		return -1;
}

void CadAlunos(TpAluno TabAlu[TFA], int &TLA){//Cadastro de Alunos ------------>
	char auxRA[13];
	int pos;
	Clear();
	gotoxy(28, 12);
	printf("***Cadastro de Alunos***");
	gotoxy(28,14);
	printf("RA: ");
	fflush(stdin);
	gets(auxRA);
	while(TLA<TFA && strcmp(auxRA,"\0")!=0){
		Clear();
		pos=BuscaAlu(TabAlu,TLA,auxRA);
		if(pos==-1){
			gotoxy(28,12);
			printf("R.A nao CADASTRADO!\n");
			strcpy(TabAlu[TLA].RA, auxRA);
			gotoxy(28,14);
			printf("Nome: ");
			fflush(stdin);
			gets(TabAlu[TLA].Nome);
			TLA++;
		}
		else{
			gotoxy(28,12);
			printf("R.A ja CADASTRADO!\n");
			getch();
		}
		Clear();
		gotoxy(28,12);
		printf("***Cadastro de Alunos***\n");
		gotoxy(28,14);
		printf("RA: ");
		fflush(stdin);
		gets(auxRA);
	}
}

void ConsAluno(TpAluno TabAlu[TFA], int TL){//Consulta de Alunos ------------>
	char auxRA[13];
	int P;
	Clear();
	gotoxy(28,12);
	printf("*** Consulta de Alunos ***\n");
	gotoxy(28,14);
	printf("Digite o R.A: ");
	fflush(stdin);
	gets(auxRA);
	while(strcmp(auxRA,"\0")!=0){
		Clear();
		P=BuscaAlu(TabAlu,TL,auxRA);
		if(P==-1){
			gotoxy(28,12);
			printf("R.A nao Cadastrado!\n");
		}
		else{
			gotoxy(28,12);
			printf("*** Dados do Aluno ***\n");
			gotoxy(28,14);
			printf("R.A: %s\n", TabAlu[P].RA);
			gotoxy(28,15);
			printf("Nome: %s\n", TabAlu[P].Nome);
		}
		getch();
		Clear();
		gotoxy(28,12);
		printf("Digite o R.A: ");
		fflush(stdin);
		gets(auxRA);
	}
}

void RelAluno(TpAluno Tab[TFA], int TL){//Relatorio de Alunos ------------>
	int i,y=14;
	Clear();
	gotoxy(28,4);
	printf("*** Relatorio de Alunos ***");
	if(TL==0){
		gotoxy(29,6);
		printf("Nao ha dados!\n");
	}
	else{
		gotoxy(15,8);
		printf("---------------------------------------------------------");
		gotoxy(23,10);
		printf("R.A \t\t\t Nome");
		gotoxy(15,12);
		printf("---------------------------------------------------------");
		for(i=0; i<TL; i++){
			gotoxy(20,y);
			printf("%s\t\t\t%s", Tab[i].RA, Tab[i].Nome);
			y+=2;
		}
	}
	getch();
}

void OrdAluno(TpAluno Tab[TFA], int TL){//Ordenar de Alunos ------------>
	int a, b;
	TpAluno RegAlu;
	gotoxy(28,20);
	if(TL==0){
		gotoxy(28,12);
		printf("\nNao ha Dados!\n");
	}
	else{
		for(a=0; a<TL; a++)
			for(b=a+1; b<TL; b++)
				if(stricmp(Tab[a].Nome, Tab[b].Nome)>0){
					RegAlu = Tab[a];
					Tab[a] = Tab[b];
					Tab[b] = RegAlu;
				}
		gotoxy(28,22);
		printf("Tabela de Alunos Ordenada!\n");
	}
	getch();
}

void AltAluno(TpAluno TabAlu[TFA], int TL){//Alterar Alunos ------------>
	char AuxRA[13],op;
	int P;
	Clear();
	gotoxy(28,12);
	printf("**Alteracao de aluno**");
	gotoxy(28,14);
	printf("Digite o RA: ");
	fflush(stdin);
	gets(AuxRA);
	while(strcmp(AuxRA,"\0")!=0)
	{
		P=BuscaAlu(TabAlu,TL,AuxRA);
		if(P==-1){
			Clear();
			gotoxy(28,12);
			printf("RA nao encontrado!");
		}
		else
		{
			Clear();
			gotoxy(28,6);
			printf("**Dados do aluno**\n");
			gotoxy(28,8);
			printf("RA: %s",TabAlu[P].RA);
			gotoxy(28,10);
			printf("Nome: %s",TabAlu[P].Nome);
			gotoxy(28,12);
			printf("Alterar(S/N)?");
			fflush(stdin);
			gotoxy(28,14);
			if(toupper(getche())=='S')
			{
				gotoxy(28,16);
				printf("Novo nome: ");
				fflush(stdin);
				gets(TabAlu[P].Nome);
				gotoxy(28,18);
				printf("Registro alterado!");
			}
		}
		gotoxy(28,20);
		printf("Digite o RA: ");
		fflush(stdin);
		gets(AuxRA);
	}
}

void ExcAluno(TpAluno Tab[TFA], int &TLA){//Excluir Alunos ------------>
	int pos, i;
	char auxRA[13];
	Clear();
	gotoxy(28,8);
	printf("*** Exclusao de Alunos ***");
	gotoxy(17,10);
	printf("Digite o R.A do Aluno que deseja excluir: ");
	fflush(stdin);
	gets(auxRA);
	pos = BuscaAlu(Tab, TLA, auxRA);
	if(pos==-1){
		gotoxy(28,12);
		printf("Aluno nao Cadastrado!");
	}
	else{
		for(i=pos; i<TLA-1; i++)
			Tab[i] = Tab[i+1];
		TLA--;
		gotoxy(33,14);
		printf("Aluno excluido!");
	}
}

int BuscaCod(TpDisc D[TFD], int qtde, int auxCod){//Busca de Codigo das Disciplinas ------------>
	int i=0;
	while(i<qtde && auxCod!=D[i].Cod)
		i++;
	if(i<qtde)
		return i;
	else
		return -1;
}

void CadDis(TpDisc Disciplinas[TFD], int &TD){//Cadastro Disciplinas ------------>
	char auxDescr[40];
	int pos, pos2, auxCod;
	Clear();
	gotoxy(28, 12);
	printf("***Cadastro de Disciplina(s)***");
	gotoxy(28, 14);
	printf("CODIGO: ");
	scanf("%d", &auxCod);
	while(TD<TFD && auxCod!=0){
		Clear();
		pos=BuscaCod(Disciplinas,TD,auxCod);
		if(pos==-1){
			gotoxy(28, 12);
			printf("Disciplina nao CADASTRADA!");
			Disciplinas[TD].Cod = auxCod;
			gotoxy(28, 14);
			printf("Nome da Disciplina: ");
			fflush(stdin);
			gets(Disciplinas[TD].Descr);
			TD++;
		}
		else{
			Clear();
			gotoxy(28, 12);
			printf("CODIGO ja CADASTRADO!");
		}
		getch();
		Clear();
		gotoxy(28, 12);
		printf("***Cadastro de Disciplina(s)***");
		gotoxy(28, 14);
		printf("CODIGO: ");
		scanf("%d", &auxCod);
	}
}

void ConsDisc(TpDisc TabDisc[TFD], int TD){//Consulta de Disciplinas ------------>
	int auxCod;
	int P;
	Clear();
	gotoxy(28,12);
	printf("*** Consulta de Disciplinas ***");
	gotoxy(28,14);
	printf("Digite o CODIGO: ");
	scanf("%d", &auxCod);
	while(auxCod!=0){
		Clear();
		P=BuscaCod(TabDisc,TD,auxCod);
		if(P==-1){
			gotoxy(28,12);
			printf("Disciplina nao Cadastrada!");
		}
		else{
			gotoxy(28,12);
			printf("*** Dados da Disciplina ***");
			gotoxy(15,14);
			printf("Cod: %d", TabDisc[P].Cod);
			gotoxy(15,15);
			printf("Nome da Disciplina: %s", TabDisc[P].Descr);
		}
		getch();
		Clear();
		gotoxy(28,12);
		printf("Digite o CODIGO: ");
		scanf("%d", &auxCod);
	}
}

void RelDisc(TpDisc TabDisc[TFD], int TD){//Relatorio de Disciplinas ------------>
	int i,y=14;
	Clear();
	gotoxy(28,4);
	printf("*** Relatorio de Disciplinas ***");
	if(TD==0){
		gotoxy(28,6);
		printf("Nao ha dados!");
	}
	else{
		gotoxy(15,8);
		printf("---------------------------------------------------------");
		gotoxy(23,10);
		printf("CODIGO \t\tNome da Disciplina");
		gotoxy(15,12);
		printf("---------------------------------------------------------");
		for(i=0; i<TD; i++){
			gotoxy(20,y);
			printf("%d\t\t\t%s\n", TabDisc[i].Cod, TabDisc[i].Descr);
			y+=2;
		}
	}
	getch();
}

void AltDisc(TpDisc TabDisc[TFD], int TD){//Alterar Disciplinas ------------>
	int auxCod,P;
	Clear();
	gotoxy(28, 12);
	printf("**Alteracao de Disciplinas**");
	gotoxy(28,14);
	printf("Digite o CODIGO: ");
	scanf("%d", &auxCod);
	while(auxCod!=0)
	{
		P=BuscaCod(TabDisc,TD,auxCod);
		printf("%d", P);
		if(P==-1){
			Clear();
			gotoxy(28,12);
			printf("\nCODIGO nao encontrado\n!");
		}
		else
		{
			Clear();
			gotoxy(28,6);
			printf("**Dados da Disciplina**");
			gotoxy(15,8);
			printf("Cod: %d\n",TabDisc[P].Cod);
			gotoxy(15,10);
			printf("Nome da Disciplina: %s",TabDisc[P].Descr);
			gotoxy(15,12);
			printf("Alterar Disciplina(S/N)?");
			fflush(stdin);
			if(toupper(getch())=='S')
			{
				gotoxy(15,14);
				printf("Novo nome: ");
				fflush(stdin);
				gets(TabDisc[P].Descr);
				gotoxy(15,16);
				printf("Registro alterado!");
			}
		}
		gotoxy(15,18);
		printf("Digite o CODIGO: ");
		scanf("%d", &auxCod);
	}
}

void ExcDisc(TpDisc TabDisc[TFD], int &TD){//Excluir Disciplinas ------------>
	int pos, i, auxCod;
	Clear();
	gotoxy(28,12);
	printf("***Exclusao de Disciplinas***");
	gotoxy(15,14);
	printf("Digite o CODIGO da Disciplina que deseja excluir: ");
	scanf("%d", &auxCod);
	pos=BuscaCod(TabDisc, TD, auxCod);
	if(pos==-1){
		gotoxy(28,12);
		printf("Disciplina nao Cadastrada!");
		getch();
	}
	else{
		for(i=pos; i<TD-1; i++)
			TabDisc[i] = TabDisc[i+1];
		TD--;
		gotoxy(33,16);
		printf("Disciplina excluida!");
		getch();
	}
}

int BuscaNota(TpNota N[TFN], int TL, int auxCod, char auxRA[13]){//Busca de Codigo da tabela de Notas ------------>
	int pos=0, cont=0;
	while(pos<TL && cont==0)
		if(stricmp(auxRA, N[pos].NotaRA)==0 && auxCod == N[pos].CodDisc)
			cont++;
		else
			pos++;
	if(pos<TL)
		return pos;
	else
		return -1;
}

void CadNota(TpNota TabNota[TFN], TpAluno TabAlu[TFA], TpDisc TabDisc[TFD], int &TN, int TA, int TD){//Cadastro de Notas ------------>
	char auxRA[13];
	int pos, pos2, auxCod;
	float auxNota;
	Clear();
	gotoxy(28,12);
	printf("***Cadastro de Notas***");
	gotoxy(28,14);
	printf("RA: ");
	fflush(stdin);
	gets(auxRA);
	while(TN<TFN && strcmp(auxRA,"\0")!=0){
		Clear();
		pos=BuscaAlu(TabAlu,TA,auxRA);
		if(pos==-1){
			gotoxy(28,12);
			printf("R.A nao CADASTRADO!");
			getch();
		}
		else{
			gotoxy(28,12);
			printf("CODIGO: ");
			scanf("%d", &auxCod);
			while(auxCod!=0){
				Clear();
				pos2=BuscaCod(TabDisc, TD, auxCod);
				if(pos2==-1){
					gotoxy(28,12);
					printf("Disciplina nao Cadastrada!");
					getch();
				}
				else{
					gotoxy(28,12);
					printf("Digite a nota do aluno: ");
					scanf("%f", &auxNota);
					strcpy(TabNota[TN].NotaRA, auxRA);
					TabNota[TN].CodDisc = auxCod;
					TabNota[TN].Nota = auxNota;
					TN++;
				}
				gotoxy(28,14);
				printf("CODIGO: ");
				scanf("%d", &auxCod);
			}
		}
		Clear();
		gotoxy(28,12);
		printf("***Cadastro de Notas***");
		gotoxy(28,14);
		printf("RA: ");
		fflush(stdin);
		gets(auxRA);
	}
}

void AltNota(TpNota TabNota[TFN], TpAluno TabAlu[TFA], TpDisc TabDisc[TFD], int &TN, int TA, int TD){//Alterar Notas ------------>
	char auxRA[13],op;
	int pos, P2, auxCod, P;
	float auxNota;
	Clear();
	gotoxy(28,6);
	printf("**Alteracao de Notas**");
	gotoxy(28,8);
	printf("Digite o RA: ");
	fflush(stdin);
	gets(auxRA);
	gotoxy(28,10);
	printf("CODIGO: ");
	scanf("%d", &auxCod);
	while(stricmp(auxRA,"\0")!=0 && auxCod!=0)
	{
		P=BuscaNota(TabNota,TN,auxCod,auxRA);
		if(P==-1){
			Clear();
			gotoxy(28,12);
			printf("Conteudo nao encontrado!");
			getch();
		}
		else{
			Clear();
			gotoxy(28,6);
			printf("**Dados do aluno**");
			gotoxy(28,8);
			printf("RA: %s",TabNota[P].NotaRA);
			gotoxy(28,10);
			printf("CODIGO: %d",TabNota[P].CodDisc);
			gotoxy(28,12);
			printf("Nota: %.2f",TabNota[P].Nota);
			gotoxy(28,14);
			printf("Alterar(S/N)?");
			if(toupper(getche())=='S'){
				gotoxy(28,16);
				printf("Nova Nota: ");
				scanf("%f", &TabNota[P].Nota);
				gotoxy(28,18);
				printf("Nota alterada!");
			}
		}
		Clear();
		gotoxy(28,12);
		printf("**Alteracao de Notas**");
		gotoxy(28,14);
		printf("Digite o RA: ");
		fflush(stdin);
		gets(auxRA);
		gotoxy(28,16);
		printf("CODIGO: ");
		scanf("%d", &auxCod);
	}
}

void ExcNota(TpNota Nota[TFN], int &TN){//Excluir Alunos ------------>
	int pos, i, auxCod;
	char auxRA[13];
	Clear();
	gotoxy(28,12);
	printf("*** Exclusao de Nota(s) ***");
	gotoxy(28,14);
	printf("Digite o R.A: ");
	fflush(stdin);
	gets(auxRA);
	gotoxy(28,16);
	printf("Digite o codigo: ");
	scanf("%d",&auxCod);
	pos = BuscaNota(Nota,TN,auxCod,auxRA);
	if(pos==-1){
		Clear();
		gotoxy(28,12);
		printf("Conteudo nao encontrado!!");
		getch();
	}
	else{
		Clear();
		for(i=pos; i<TN-1; i++)
			Nota[i] = Nota[i+1];
		TN--;
		gotoxy(28,12);
		printf("Nota excluida!");
		getch();
	}
}

void RelNota(TpNota TabNota[TFN], int TN){//Relatorio de Notas ------------>
	int i,y=12;
	Clear();
	gotoxy(28,2);
	printf("*** Relatorio de Notas ***");
	if(TN==0){
		Clear();
		gotoxy(28,4);
		printf("Nao ha dados!");
	}
	else{
		gotoxy(3,6);
		printf("----------------------------------------------------------------------------");
		gotoxy(3,8);
		printf("R.A \t\t\t CODIGO da Disciplina\t\t\tNota");
		gotoxy(3,10);
		printf("----------------------------------------------------------------------------");
		for(i=0; i<TN; i++){
			gotoxy(3,y);
			printf("%s\t\t\t%d\t\t\t\t%.2f", TabNota[i].NotaRA, TabNota[i].CodDisc, TabNota[i].Nota);
			y+=2;
			if(y >= 22){
            	gotoxy(28,y+1);
            	printf("Aperte espaco para continuar");
            	while(getch() != 32){
                	gotoxy(28,y+1);
               		printf("Aperte espaco para continuar");
            	}
            	y = 2;
            	Clear();
            	gotoxy(5,y);
            	printf("RA");
            	gotoxy(23,y);
           	 	printf("CodDisc");
            	gotoxy(35,y);
            	printf("Nota");
        	}

		}
	}
	getch();
}

 void Reprovados(TpAluno TabAlu[TFA], TpNota TabNotas[TFN], int TA, int TN){//Alunos Reprovados ------------>
	int i, j, x=8, y=10, contRA;
	Clear();
	gotoxy(15,6);
	printf("***Alunos reprovados em duas ou mais disciplinas***");
	for(i=0;i<TA;i++){
		contRA=0;
		for(j=0;j<TN;j++){
			if(strcmp(TabAlu[i].RA,TabNotas[j].NotaRA)==0){
				if(TabNotas[j].Nota < 6)
					contRA++;
			}
		}
		if(contRA>=2){
			gotoxy(22,x);
			printf("R.A: %s",TabAlu[i].RA);
			gotoxy(22,y);
			printf("Nome: %s",TabAlu[i].Nome);
			x+=4;
			y+=4;
		}
	}
	getch();
}

void MediaGeral(TpDisc TabDisc[TFD], TpNota TabNotas[TFN], int TD, int TN){//Media geral da disciplina ------------>
	int i,j,cont,x=7,y=9;
	float soma;
	Clear();
	gotoxy(22,5);
	printf("***Disciplinas com media abaixo de 6***");
	for(i=0;i<TD;i++){
		soma=0;
		cont=0;
		for(j=0;j<TN;j++){
			if(TabDisc[i].Cod == TabNotas[j].CodDisc){
				soma+=TabNotas[j].Nota;
				cont++;
			}
		}
		if((soma/cont)<6){
			gotoxy(15,x);
			printf("Codigo: %d", TabDisc[i].Cod);
			gotoxy(15,y);
			printf("Disciplina: %s", TabDisc[i].Descr);
			x+=4;
			y+=4;
		}	
	}
	getch();
}

void BuscaLetra(TpAluno TabAlu[TFA], int TA, char auxLetra){//Buscar Alunos pela primeira letra ------------>
	int i, x=6, y=8;
	Clear();
	for(i=0;i<TA;i++)
		if(toupper(TabAlu[i].Nome[0]) == toupper(auxLetra)){
			gotoxy(15,x);
			printf("R.A: %s", TabAlu[i].RA);
			gotoxy(15,y);
			printf("Nome: %s", TabAlu[i].Nome);
			x+=4;
			y+=4;
		}
	getch();
}

void RelGeral(TpAluno TabAlu[TFA], TpDisc TabDisc[TFD], TpNota TabNota[TFN], int TA, int TD, int TN){//Relatorio Geral ------------>
	int i, j, pos, x;
	Clear();
	gotoxy(28,12);
	printf("***Relatorio Geral***");
	getch();
	for(i=0;i<TA;i++){
		Clear();
		x=11;
		gotoxy(3,x);
		printf("R.A: %s", TabAlu[i].RA);
		gotoxy(20,x);
		printf("Aluno: %s", TabAlu[i].Nome);
		for(j=0;j<TN;j++){
			if(strcmp(TabAlu[i].RA, TabNota[j].NotaRA)==0){
				x++;
				pos=BuscaCod(TabDisc,TD,TabNota[j].CodDisc);
				gotoxy(3,x);
				printf("Disciplina: %d - %s", TabDisc[pos].Cod, TabDisc[pos].Descr);
				gotoxy(48,x);
				printf("Nota: %.2f", TabNota[j].Nota);
				if(TabNota[j].Nota < 6){
					gotoxy(60,x);
					printf("Situacao: Reprovado");
				}
				else{
					gotoxy(60,x);
					printf("Situacao: Aprovado");
				}
			}
		}
		getch();
	}		
}

char Menu(void){//Menu Principal ------------>
	Clear();
	gotoxy(28,8);
	printf("-------- Menu --------");
	gotoxy(28,10);
	printf("[A] Aluno(s)");
	gotoxy(28,12);
	printf("[B] Disciplina(s)");
	gotoxy(28,14);
	printf("[C] Nota(s)");
	gotoxy(28,16);
	printf("[D] Extras");
	
	return toupper(getch());
}

char MenuAlu(void){//Menu de Alunos ------------>
	Clear();
	gotoxy(28,8);
	printf("-------- Menu Alunos --------");
	gotoxy(28,10);
	printf("[A] Cadastrar Aluno(s)");
	gotoxy(28,12);
	printf("[B] Consultar Aluno(s)");
	gotoxy(28,14);
	printf("[C] Alterar Aluno(s)");
	gotoxy(28,16);
	printf("[D] Excluir Aluno(s)");
	gotoxy(28,18);
	printf("[E] Relatorio de Aluno(s)");
	
	return toupper(getch());
}

char MenuDisc(void){//Menu de Disciplinas ------------>
	Clear();
	gotoxy(28,8);
	printf("-------- Menu Disciplinas --------");
	gotoxy(28,10);
	printf("[A] Cadastrar Disciplina(s)");
	gotoxy(28,12);
	printf("[B] Consultar Disciplina(s)");
	gotoxy(28,14);
	printf("[C] Alterar Disciplina(s)");
	gotoxy(28,16);
	printf("[D] Excluir Disciplina(s)");
	gotoxy(28,18);
	printf("[E] Relatorio de Disciplinas(s)");
	
	return toupper(getch());
}

char MenuNota(void){//Menu de Notas ------------>
	Clear();
	gotoxy(28,8);
	printf("-------- Menu Notas --------");
	gotoxy(28,10);
	printf("[A] Cadastrar Nota(s)");
	gotoxy(28,12);
	printf("[B] Alterar Nota(s)");
	gotoxy(28,14);
	printf("[C] Excluir Nota(s)");
	gotoxy(28,16);
	printf("[D] Relatorio Nota(s)");
	
	return toupper(getch());
}
char MenuExtra(void){//Menu de opções Extras------------>
	Clear();
	gotoxy(26,8);
	printf("-------- Menu Extra --------");
	gotoxy(16,10);
	printf("[A] Alunos reprovados em 2 ou mais disciplinas");
	gotoxy(16,12);
	printf("[B] Procurar alunos por letra");
	gotoxy(16,14);
	printf("[C] Disciplinas com media geral abaixo de 6");
	gotoxy(16,16);
	printf("[D] Relatorio geral");
	
	return toupper(getch());
}
int main(void){
	TpAluno Alunos[TFA];
	TpDisc Disciplinas[TFD];
	TpNota Notas[TFN];
	int TA=0, TD=0, TN=0;
	char op1, opAlu, opDisc, opNota, opExtra, auxLetra; 
	
	Moldura(1, 1, 80, 25, 3, 0);
	Inicializacao(Alunos, Disciplinas, Notas, TA, TD, TN);
	op1=Menu();//Menu principal ------------>
	do{
		switch(op1){
			case 'A':
				opAlu=MenuAlu();//Menu Alunos ------------>
				do{
					switch(opAlu){
						case 'A':
							CadAlunos(Alunos, TA);
							OrdAluno(Alunos, TA);
							break;
						case 'B':
							ConsAluno(Alunos, TA);
							break;
						case 'C':
							AltAluno(Alunos, TA);
							OrdAluno(Alunos, TA);
							break;
						case 'D':
							ExcAluno(Alunos, TA);
							OrdAluno(Alunos, TA);
							break;
						case 'E':
							RelAluno(Alunos, TA);
							break;
					}
					opAlu=MenuAlu();
				}while(opAlu!=27);
				break;
			case 'B':
				do{
					opDisc=MenuDisc();
					switch(opDisc){
						case 'A':
							CadDis(Disciplinas, TD);
							break;
						case 'B':
							ConsDisc(Disciplinas, TD);
							break;
						case 'C':
							AltDisc(Disciplinas, TD);
							break;
						case 'D':
							ExcDisc(Disciplinas, TD);
							break;
						case 'E':
							RelDisc(Disciplinas, TD);
							break;
					}
				}while(opDisc!=27);
				break;
			case 'C':
				do{
					opNota=MenuNota();
					switch(opNota){
						case 'A':
							CadNota(Notas,Alunos,Disciplinas,TN,TA,TD);
							break;
						case 'B':
							AltNota(Notas,Alunos,Disciplinas,TN,TA,TD);
							break;
						case 'C':
							ExcNota(Notas,TN);
							break;
						case 'D':
							RelNota(Notas,TN);
							break;
					}
				}while(opNota!=27);
				break;
			case 'D':
				do{
					opExtra=MenuExtra();
					switch(opExtra){
						case 'A':
							Reprovados(Alunos,Notas,TA,TN);
							break;
						case 'B':
							Clear();
							gotoxy(28,12);
							printf("***Procurar alunos por letra***\n");
							gotoxy(20,14);
							printf("Digite a Letra do Aluno que deseja Consultar: ");
							auxLetra = getche();
							BuscaLetra(Alunos,TA,auxLetra);
							break;
						case 'C':
							MediaGeral(Disciplinas, Notas, TD, TN);
							break;
						case 'D':
							RelGeral(Alunos,Disciplinas,Notas,TA,TD,TN);
							break;
					}
				}while(opExtra!=27);
				break;
		}
		op1=Menu();
	}while(op1!=27);
	
	return 0;
}
