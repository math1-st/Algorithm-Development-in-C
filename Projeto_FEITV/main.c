#include "funcoes.h"

int main(int argc, char *argv[])
{
    // Forçando o terminal a ler caracteres em português.
    setlocale(LC_ALL, "Portuguese");

    int opcao, id_usuario;

    printf("Bem-vindo ao FEI TV!\n");

    do
    {
        printf("\nEscolha uma das opcões abaixo:");
        printf("\n[1] Cadastrar-se");
        printf("\n[2] Login");
        printf("\n\n-> ");

        scanf("%d", &opcao);
        getchar();
        limpar_terminal();

        switch(opcao)
        {
            case 1:
                id_usuario = cadastrar_usuario();
                break;

            case 2:
                id_usuario = logar_usuario();
                break;

            default:
                printf("Opção invalida. Tente novamente.\n\n");
                break;
        }

    } while (opcao != 1 && opcao != 2);

    do
    {
        printf("O que deseja acessar?\n");
        printf("\n[0] Sair");
        printf("\n[1] Minha Área (Assistidos, Playlists, Likes e Lista de Desejos)");
        printf("\n[2] Lista de Categorias");
        printf("\n[3] Procurar Obra Específica");
        printf("\n\n-> ");

        scanf("%d", &opcao);

        limpar_terminal();

        int subopcao;

        // Baseado no que o usuário pediu, listará coisas diferentes.
        switch (opcao)
        {
            case 0:
                break;
            case 1:
                // Ver Continuar Assistindo, Assistidos, Meus Favoritos.
                ver_minha_area(id_usuario);
                break;

            case 2:
                // Listar Categorias para assistir.
                printf("Qual categoria você quer acessar?\n");
                printf("\n[0] Voltar");
                printf("\n[1] Destaque");
                printf("\n[2] Top Animações");
                printf("\n[3] Top Ação");
                printf("\n[4] Top Drama");
                printf("\n[5] Top Esportes");
                printf("\n[6] Top 10 no Brasil");
                printf("\n[7] Documentários");
                printf("\n\n-> ");

                scanf("%d", &subopcao);
                getchar();
                limpar_terminal();

                switch (subopcao)
                {
                    case 0:
                        break;
                    case 1:
                        listar_filtrado(id_usuario, "DESTAQUE");
                        break;
                    case 2:
                        listar_filtrado(id_usuario, "TOP ANIMACOES");
                        break;
                    case 3:
                        listar_filtrado(id_usuario, "TOP ACAO");
                        break;
                    case 4:
                        listar_filtrado(id_usuario, "TOP DRAMAS");
                        break;
                    case 5:
                        listar_filtrado(id_usuario, "TOP ESPORTES");
                        break;
                    case 6:
                        listar_filtrado(id_usuario, "TOP 10 NO BRASIL");
                        break;
                    case 7:
                        listar_filtrado(id_usuario, "DOCUMENTARIOS");
                        break;
                    default:
                        limpar_terminal();
                        printf("Opção inválida. Tente novamente.\n\n");
                        break;
                }

                break;

            case 3:
                procurar_obra(id_usuario);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
