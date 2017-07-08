/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
** DESCRIÇÃO:	Definição de Estruturas e Tipos Definidos
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

typedef unsigned short int Boolean;

typedef struct aluno Aluno;
struct aluno
{
    char    Matricula[T_MATRIC];

    char    Nome[T_NOME];
    char    DtNascimento[T_DATA];
    char    Endereco[T_ADDRS];
    char    Telefone[T_FONE];

};


typedef struct lista_aluno lstAluno;
struct lista_aluno
{
    Aluno       celula;
    lstAluno    *prox;

};
