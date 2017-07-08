/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
** DESCRIÇÃO:	Rotinas de Interação com uma Lista de Alunos
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header_definicoes.h"
#include "header_estruturas.h"
#include "header_prototipos.h"

/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
** NOTAS:		Para as rotinas cujo retorno é um Boolean, se o valor
**				retornado for FALSE, não ocorreram erros durante a
**				execução da rotina. Retorna TRUE, caso contrário.
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

// FUNÇÃO 1: Criar uma nova lista. P.S: Listas vazias apontam para "NULL".
lstAluno* listaAlunos_Init()
{
	return NULL;
}

// FUNÇÃO 2: Transfere a lista de um Arquivo para a Memória Principal.
Boolean listaAlunos_Ler(lstAluno **L)
{
	FILE		*arq;
	Aluno 		A;
	Boolean 	resposta;

	if ( *L != NULL ) return TRUE;

	arq = fopen("ALUNOS.DAT", "rb");
	if ( arq == NULL ) return TRUE;
	else if ( feof(arq) ) 
	{
		fclose(arq);
		return FALSE;
	}

	do
	{
		fread( &A, sizeof(Aluno), 1, arq);

		resposta = listaAlunos_insereFinal(L, &A);
		if ( resposta == TRUE ) return TRUE;

	} while ( !feof(arq) );

	fclose(arq);
	return FALSE;
}


// FUNÇÃO 3: Transfere a lista da Memória Principal para um Arquivo, destruindo as celulas a cada iteração.
Boolean listaAlunos_Escrever(lstAluno **L)
{
	lstAluno 	*pAux, *pDel;
	FILE 		*arq;

	if ( *L == NULL ) 
	{
		printf("\nEscrever: A Lista esta vazia!\n");
		return TRUE;
	}

	arq = fopen("ALUNOS.DAT", "wb");
	if ( arq == NULL ) 
	{
		printf("\nEscrever: Falha ao abrir arquivo!\n");
		return TRUE;
	}
	

	for ( pAux = *L; pAux != NULL; free(pDel) )
	{
		fwrite( &(pAux->celula), sizeof(Aluno), 1, arq);
		pDel = pAux;
		pAux = pAux->prox;
	}

	fclose(arq);
	return FALSE;
}


// FUNÇÃO 4: Inserir um elemento "Aluno" na lista de Alunos, pelo INíCIO.
Boolean listaAlunos_insereInicio(lstAluno **L, Aluno *A)
{
	lstAluno 	*novo;

	novo = (lstAluno*) malloc( sizeof(lstAluno) );
	if ( novo == NULL ) return TRUE;

	strcpy( (novo->celula).Matricula, A->Matricula );
	strcpy( (novo->celula).Nome, A->Nome );
	strcpy( (novo->celula).DtNascimento, A->DtNascimento );
	strcpy( (novo->celula).Endereco, A->Endereco );
	strcpy( (novo->celula).Telefone, A->Telefone );

	novo->prox = *L;
	*L = novo;

	return FALSE;
}


// FUNÇÃO 5: Insere um elemento "Aluno" na lista de Alunos, pelo FINAL.
Boolean listaAlunos_insereFinal(lstAluno **L, Aluno *A)
{
	lstAluno 	*novo, *pAux;

	novo = (lstAluno*) malloc( sizeof(lstAluno) );
	if ( novo == NULL ) return TRUE;

	strcpy( (novo->celula).Matricula, A->Matricula );
	strcpy( (novo->celula).Nome, A->Nome );
	strcpy( (novo->celula).DtNascimento, A->DtNascimento );
	strcpy( (novo->celula).Endereco, A->Endereco );
	strcpy( (novo->celula).Telefone, A->Telefone );

	pAux = *L;
	if ( pAux != NULL )
	{
		while ( pAux->prox != NULL ) pAux = pAux->prox;
	}

	pAux->prox = novo;
	novo->prox = NULL;

	return FALSE;
}
