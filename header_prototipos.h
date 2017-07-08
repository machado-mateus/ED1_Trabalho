/*
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
** DESCRIÇÃO:	Protótipos de todas as rotinas do sistema.
** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MODULO:		Rotinas para Manipulação de Alunos
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Inicio ~
lstAluno* listaAlunos_Init();
Boolean listaAlunos_Ler(lstAluno**);
Boolean listaAlunos_Escrever(lstAluno**);
Boolean listaAlunos_insereInicio(lstAluno**, Aluno*);
Boolean listaAlunos_insereFinal(lstAluno**, Aluno*);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Final ~