/*
Lista de Exercicio 2
-
Aluno : Alex Sandro Pereira Garcia
-
Profesora :Dr.Soraia Silva Prietch
-
Tema : 11. Sistema de avaliação de um curso de graduação pelos alunos
- Objetivo:
		1.1 =>	Armazenar registros de dados dos alunos
		1.2 =>  Consulta  exibi todos os alunos de ambos os sexos ou apenas do F/M
		1.3 =>  Colsultar Alunos e informações dos cursos ou curso

 */
// Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define Max_Cadastros  1

typedef struct
{
    int dia,mes,ano,semestre;
    long int RGA;
    char Curso[64],Questionario[3];
    float  Nota_Curso;
} curso ;

typedef struct Aluno
{
    char   Nome [64],Sexo;
    int    Idade;
    int    cpf[10];
    curso re;
} dados;

/*
Funções
-> void Cadastro(dados reg[],FILE *); Com passagem de parametro e sem retorno
-> void Consulta1 (FILE *arq); Com passagem de parametro
*/

void Cadastro(dados reg[],FILE *arq)
{
    int i,j;
    arq = fopen("cadastro.bin","wb");
    for(i = 0; i <= Max_Cadastros; i++)
    {

        printf("\n Nome : ");
        gets(reg[i].Nome);
        fflush(stdin);

        printf("\n Sexo (  M - Masculino /F - Feminino  ) : ");
        scanf("%c",&reg[i].Sexo);
        fflush(stdin);

        printf("\n CPF ");
        for(j=0; j<=10; j++)
        {
            scanf("%i",&reg[i].cpf[j]);
            fflush(stdin);
        }

        printf("\n \n -=- Dados sobre o curso -=- \n \n ");

        fflush(stdin);
        printf("\n Curso :");
        gets(reg[i].re.Curso);
        fflush(stdin);


        printf("\n Semestre : ");
        scanf("%i",&reg[i].re.semestre);
        fflush(stdin);

        printf("\n RGA: ");
        scanf("%i",&reg[i].re.RGA);
        fflush(stdin);

        printf("\n Data da Matricula (Em numeros ) : ");
        scanf("%i",&reg[i].re.dia);
        scanf("%i",&reg[i].re.mes);
        scanf("%i",&reg[i].re.ano);
        fflush(stdin);

        system("pause");
        system("cls");

        printf("\n\n -=- Questionario Responda ele com S/N -=- \n\n");

        printf("Você está satisfeito com o seu curso? ");
        scanf("%c",&reg[i].re.Questionario[0]);
        fflush(stdin);

        printf("\n ");
        scanf("%c",&reg[i].re.Questionario[1]);
        fflush(stdin);

        printf("\n ");
        scanf("%c",&reg[i].re.Questionario[2]);
        fflush(stdin);

        if(arq==NULL)
        {
            printf("Erro ao abrir arquivo");
        }
        else
        {
            fwrite(&reg,sizeof(dados),Max_Cadastros,arq);
        }
    };

 fclose(arq); // Fim da etapa de cadastro
};

void Consulta1 (FILE *arq){
}

int main(){
    FILE *arq;
    dados reg[Max_Cadastros];
    Cadastro(reg,arq);



}
