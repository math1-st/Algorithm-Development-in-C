/*
funcoes.h é um arquivo de cabeçalho.
Aqui, chama-se todos os protótipos de funções e
todas as bibliotecas usadas tanto em main.c quanto funcoes.c.

Colocando tudo aqui, os outros arquivos ficam menores,
mais fáceis de ler, e organizados.
*/

#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>  // Resolve o warning da função 'exit'
// Necessário para o strcmp()
#include <string.h>
// Biblioteca para transformar letras maiúsculas em minúsculas. (Usada na função procurar_obra())
#include <ctype.h>
// Usamos o locale temporariamente na função de curtir_descurtir para não gerar problemas com pontuação.
#include <locale.h>

// Limpa a tela do terminal usando sequências de escape ASCII.
void limpar_terminal();

// Verifica se um arquivo foi aberto corretamente; interrompe o programa se houver erro.
void verificar_abertura_arquivo(FILE *arquivo);

// Realiza o cadastro de um novo usuário e retorna seu ID único.
int cadastrar_usuario();

// Realiza o login do usuário verificando nome e senha, e retorna o ID do usuário.
int logar_usuario();

// Exibe as obras interagidas pelo usuário (curtidas, assistidas, etc).
void ver_minha_area(int id_usuario);

// Lista obras do catálogo baseando-se em uma categoria específica.
void listar_filtrado(int id_usuario, char *categoria_escolhida);

// Converte todos os caracteres de uma string para minúsculo.
void transformar_em_minusculo(char *nome_da_obra);

// Busca obras no catálogo por nome ou parte do nome.
void procurar_obra(int id_usuario);

// Gerencia o sistema de likes/dislikes de uma obra e atualiza o catálogo.
void curtir_descurtir_obra(int id_do_usuario, int id_da_obra_selecionada);

// Busca o nome de uma obra no catálogo através do seu ID.
void pegar_nome_obra(int id_da_obra, char *variavel_colocar_nome);

// Registra que um usuário assistiu a uma obra e a remove da lista de desejos se fora adicionado.
void assistir(int id_do_usuario, int id_da_obra);

// Adiciona uma obra específica a uma lista escolhida (Favoritos ou Desejos).
void adicionar_na_lista(int id_do_usuario, int id_da_obra, char *qual_lista);

// Remove uma obra de uma lista específica do usuário.
void remover_da_lista(int id_do_usuario, int id_da_obra, char *qual_lista);

// Abre o menu de opções (curtir, assistir, favoritar) para uma obra selecionada.
void manipular_obra(int id_usuario);

#endif // FUNCOES_H_INCLUDED
