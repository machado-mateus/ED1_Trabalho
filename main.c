/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
** DESCRIÇÃO:	Programa Principal.
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header_definicoes.h"
#include "header_estruturas.h"
#include "header_prototipos.h"

int main()
{
    lstAluno 	*L;
    Aluno 		A;
    int 		resposta;
    Boolean 	rc;

    L = listaAlunos_Init();

    while ( 1 )
    {
    	system("clear");

    	printf("NOVO ALUNO\n");
    	printf("\tMatricula: ");
    	scanf(" %6[^\n]", A.Matricula);
    	printf("\tNome: ");
    	scanf(" %40[^\n]", A.Nome);
    	printf("\tNascimento: ");
    	scanf(" %10[^\n]", A.DtNascimento);
    	printf("\tEndereço: ");
    	scanf(" %30[^\n]", A.Endereco);
    	printf("\tTelefone: ");
    	scanf(" %10[^\n]", A.Telefone);

    	rc = listaAlunos_insereInicio(&L, &A);
    	if ( rc == TRUE ) 
    	{
    		printf("Falha ao Inserir na Lista!\n");
    		break;
    	}

    	printf("\n\nDeseja Continuar? (Sim = 1, Não = 0)\nRESPOSTA: ");
    	scanf(" %i", &resposta);
    	if ( resposta == 0 ) break;
    }

    rc = listaAlunos_Escrever(&L);
    if ( rc == TRUE ) 
	{
		printf("Falha ao Escrever Lista em Arquivo!\n");
	}

    return 0;
}
