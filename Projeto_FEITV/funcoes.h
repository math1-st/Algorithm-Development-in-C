/*
funcoes.h é um arquivo de cabeçalho.
Aqui, chama-se todos os protótipos de funções e
todas as bibliotecas usadas tanto em main.c quanto funcoes.c.

Colocando tudo aqui, os outros arquivos ficam menores,
mais fáceis de ler, e organizados.
*/

#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Funções úteis

// Limpa a tela do terminal de forma universal.
void limpar_terminal();

// Verifica se o ponteiro do arquivo é nulo e encerra o programa em caso de erro.
void verificar_abertura_arquivo(FILE *arquivo);

// Converte todos os caracteres de uma string para letras minúsculas.
void transformar_em_minusculo(char *nome_da_obra);

// Busca o nome de uma obra no catálogo através do seu ID.
void pegar_nome_obra(int id_da_obra, char *variavel_colocar_nome);


// Criação e Login de usuários

// Cria uma nova conta, gera um ID único e salva no arquivo de contas.
int cadastrar_usuario();

// Verifica usuário e senha no arquivo e retorna o ID do usuário se estiver correto.
int logar_usuario();


// Navegação e consulta de obras

// Exibe as interações do usuário (Assistidos, Likes, Desejos) e menu de playlists.
void ver_minha_area(int id_usuario);

// Lista obras de uma categoria específica (Filme/Série) em formato de tabela.
void listar_filtrado(int id_usuario, char *categoria_escolhida);

// Busca obras no catálogo que contenham o termo digitado pelo usuário.
void procurar_obra(int id_usuario);


// Funções de Interação com obras

// Adiciona ou remove um "Like" de uma obra e atualiza o contador no catálogo.
void curtir_descurtir_obra(int id_do_usuario, int id_da_obra_selecionada);

// Registra que o usuário assistiu a obra e a remove da lista de desejos, se necessário.
void assistir(int id_do_usuario, int id_da_obra);

// Adiciona uma obra específica à lista de "Desejos" do usuário.
void adicionar_lista_desejos(int id_usuario, int id_obra);

// Adiciona uma obra do catálogo a uma playlist personalizada criada pelo usuário.
void adicionar_obra_na_playlist(int id_usuario, int id_obra, char *nome_playlist);

// Remove uma obra de listas padrões (LIKE ou DESEJOS).
void remover_da_lista(int id_usuario, int id_obra, char *lista);

// Permite ao usuário escolher entre Assistir, Curtir ou Adicionar a Listas.
void manipular_obra(int id_usuario);


// Funções de Playlist

// Cria um novo registro de playlist (Título) no arquivo do usuário.
void criar_playlist(int id_usuario);

// Lista o conteúdo interno de uma playlist específica.
int listar_obras_playlist(int id_usuario, char *nome_playlist);

// Remove uma obra específica de uma playlist.
void remover_da_playlist(int id_usuario, int id_obra, char *nome_playlist);

// Altera o nome de uma playlist existente.
void editar_nome_playlist(int id_usuario, char *nome_antigo);

// Apaga uma playlist e todos os seus vínculos com obras.
void excluir_playlist(int id_usuario, char *nome_playlist);



#endif
