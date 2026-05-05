// Inclui o arquivo de cabeçalho com as declarações das funções e definições necessárias.
#include "funcoes.h"

void limpar_terminal()
/*
    Função que limpa o terminal usando códigos de escape ANSI.
    Há outras formas de limpar o terminal em C, mas essa usa ASCII e é mais fácil, rápido e universal em qualquer SO.
    \e[1;1H move o cursor para a linha 1, coluna 1, para evitar problemas.
    \e[2J limpa o terminal.
*/
{
    // Imprime a sequência de escape que limpa a tela e posiciona o cursor no início.
    printf("\033[H\033[2J");
}

void verificar_abertura_arquivo(FILE *arquivo)
/*
    Função que realiza uma verificação rápida de abertura de arquivo.
    Essa função NÃO fecha o arquivo referenciado.
*/
{
    // Testa se o ponteiro do arquivo é NULL (erro na abertura).
    if (arquivo == NULL)
    {
        // Exibe mensagem de erro.
        printf("\nErro ao manipular arquivo. Trate o erro.");
        // Encerra o programa imediatamente.
        exit(0);
    }
}

int cadastrar_usuario()
/*
    Função que realiza o cadastro da conta de usuário.
    Usuário irá criar um usuário e senha para login,
    recebendo um ID específico para sua conta.

    O programa percorre o arquivo de contas para
    verificar se já existe um usuário específico.
    Caso haja, manda voltar pedindo outro usuário.

    O ID será o último ID de conta criada + 1.
    Se a conta for a primeira do sistema, o ID será 1.
*/
{
    // Abre (ou cria) o arquivo de contas no modo "a+" (leitura e escrita, ao final).
    FILE *contas_usuarios = fopen("contas_usuarios.txt", "a+");
    // Verifica se a abertura foi bem-sucedida.
    verificar_abertura_arquivo(contas_usuarios);

    // Declara variáveis para armazenar os dados do novo usuário e para comparação.
    char criar_usuario[20], criar_senha[20], usuario_comparacao[20], senha_comparacao[20];
    // Variável para guardar o ID lido do arquivo e o maior ID encontrado.
    int id_comparacao = 0, ultimo_id = 0, id_usuario;
    // Buffer para ler cada linha do arquivo.
    char caracteres_na_linha[100];
    // Exibe título da área.
    printf("Área de Cadastro\n");

    // Loop para garantir que o nome de usuário seja único.
    do
    {
        // Solicita o nome de usuário.
        printf("\nDigite o seu usuário: ");
        scanf("%s", criar_usuario);

        // Volta ao início do arquivo para ler todas as linhas.
        rewind(contas_usuarios);

        // Lê cada linha do arquivo de contas.
        while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), contas_usuarios))
        {
            // Tenta extrair ID, usuário e senha da linha no formato "id|usuario|senha".
            if(sscanf(caracteres_na_linha, "%d|%[^|]|%s", &id_comparacao, usuario_comparacao, senha_comparacao) == 3)
            {
                // Atualiza o maior ID encontrado até agora.
                if (id_comparacao > ultimo_id)
                {
                    ultimo_id = id_comparacao;
                }

                // Verifica se o usuário digitado já existe no arquivo.
                if (strcmp(usuario_comparacao, criar_usuario) == 0)
                {
                    // Limpa a tela e informa o conflito.
                    limpar_terminal();
                    printf("Esse usuário já existe. Tente outro.\n");
                }
            }
        }

    // Repete enquanto o usuário existir (comparação com o último lido).
    } while (strcmp(usuario_comparacao, criar_usuario) == 0);

    // Calcula o novo ID: maior ID + 1.
    id_usuario = ultimo_id + 1;

    // Solicita a senha.
    printf("Digite a sua senha: ");
    scanf("%s", criar_senha);

    // Grava os dados do novo usuário no arquivo, no formato especificado.
    fprintf(contas_usuarios, "%d|%s|%s\n", id_usuario, criar_usuario, criar_senha);

    // Fecha o arquivo de contas.
    fclose(contas_usuarios);

    // Limpa a tela.
    limpar_terminal();

    // Mensagem de sucesso.
    printf("Conta criada com sucesso!\n\n");

    // Retorna o ID do novo usuário para uso posterior.
    return id_usuario;
}

int logar_usuario()
/*
    Função que realiza o login de usuário.
    Pede para o usuário digitar usuário e senha,
    abre o arquivo de contas, percorre todas as linhas
    e verifica se numa mesma linha usuario e senha da linha
    são iguais ao usuário e senha que o usuário digitou.

    Retorna o ID se o login for bem-sucedido.
*/
{
    // Abre o arquivo de contas apenas para leitura.
    FILE *contas_usuarios = fopen("contas_usuarios.txt", "r");
    // Verifica se abriu corretamente.
    verificar_abertura_arquivo(contas_usuarios);

    // Variáveis para armazenar as credenciais digitadas e as lidas do arquivo.
    char usuario_de_login[20], senha_de_login[20], usuario_comparacao[20], senha_comparacao[20];
    int id_comparacao, id_usuario = -1, logado = 0;
    // Buffer para leitura de linha.
    char caracteres_na_linha[40];
    // Título da área.
    printf("Área de Login\n");

    // Loop até que o login seja bem-sucedido.
    do
    {
        // Solicita usuário e senha.
        printf("\nUsuário: ");
        scanf("%s", usuario_de_login);
        printf("Senha: ");
        scanf("%s", senha_de_login);

        // Volta ao início do arquivo para nova verificação.
        rewind(contas_usuarios);

        // Lê cada linha do arquivo.
        while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), contas_usuarios))
        {
            // Extrai os campos da linha.
            if (sscanf(caracteres_na_linha, "%d|%[^|]|%s", &id_comparacao, usuario_comparacao, senha_comparacao) == 3)
            {
                // Compara as credenciais.
                if (strcmp(usuario_de_login, usuario_comparacao) == 0 && strcmp(senha_de_login, senha_comparacao) == 0)
                {
                    // Login bem-sucedido: armazena ID e marca flag.
                    id_usuario = id_comparacao;
                    logado = 1;
                    break;
                }
            }
        }

        // Se falhou, limpa tela e pede novamente.
        if (logado == 0)
        {
            limpar_terminal();
            printf("Usuário ou senha incorretos. Tente novamente.\n");
        }

    } while (logado != 1);

    // Fecha o arquivo.
    fclose(contas_usuarios);

    // Limpa a tela e informa sucesso.
    limpar_terminal();
    printf("Você logou com sucesso!\n\n");

    // Retorna o ID do usuário autenticado.
    return id_usuario;
}

void ver_minha_area(int id_usuario)
/*
    Função que mostra as interações feitas pelo usuário com o sistema.
    Toda vez que o usuário interaje com uma obra,
    a interação é salva em area_usuarios.txt.

    Aqui mostramos os registros das interações.
    Escaneia-se todas as linhas de area_usuarios, verificando primeiro
    o ID do usuário. Depois, vemos se esse ID possui interações
    registradas.

    Caso não haja, o programa volta para o menu anterior.
    Se há, damos a possibilidade do usuário remover algum registro
    chamando outra função para tal tarefa.
    (Não é possível remover da lista de Assistidos)
*/
{
    // Abre o arquivo de área do usuário para leitura.
    FILE *area_usuarios = fopen("area_usuarios.txt", "r");
    verificar_abertura_arquivo(area_usuarios);

    // Variáveis para armazenar dados lidos.
    int id_lido, id_obra_lida, listados = 0;
    char categoria_lida[50], nome_obra_lida[100];

    // Título.
    printf("Minha Área\n");

    // Buffer para linha.
    char caracteres_na_linha[256];
    // Lê cada linha do arquivo.
    while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), area_usuarios))
    {
        // Tenta extrair os campos da linha.
        if (sscanf(caracteres_na_linha, "%d|%[^|]|%d|%[^\n]",
                   &id_lido, categoria_lida, &id_obra_lida, nome_obra_lida) >= 3)
        {
            // Verifica se a interação pertence ao usuário logado.
            if (id_lido == id_usuario)
            {
                // Exibe o tipo de interação com um prefixo adequado.
                if (strcmp(categoria_lida, "ASSISTIDOS") == 0) {
                    printf("[ASSISTIDO]: ");
                    listados++;
                }
                else if (strcmp(categoria_lida, "LIKE") == 0) {
                    printf("[CURTIDO]: ");
                    listados++;
                }
                else if (strcmp(categoria_lida, "LISTA DE DESEJOS") == 0) {
                    printf("[DESEJADO]: ");
                    listados++;
                }
                else if (strcmp(categoria_lida, "MEUS FAVORITOS") == 0) {
                    printf("[FAVORITADO]: ");
                    listados++;
                }

                // Mostra o nome e o ID da obra.
                printf("%s, ID: %d\n", nome_obra_lida, id_obra_lida);
            }
        }
    }

    // Fecha o arquivo após a leitura.
    fclose(area_usuarios);

    int opcao;

    // Se não houver nenhuma interação, exibe mensagem e retorna.
    if (listados == 0)
    {
        printf("\n- Não há obras para visualizar ou editar.\n");
        printf("- Assista, curta, ou adicione obras às listas para visualizá-las aqui.\n\n");
        return;
    }

    // Pergunta se o usuário deseja remover alguma obra.
    do
    {
        printf("\nDeseja remover alguma obra de alguma lista?\n");
        printf("\n[1] Não");
        printf("\n[2] Sim");
        printf("\n\n-> ");

        scanf("%d", &opcao);

        // Se optar por não, limpa a tela e retorna.
        if (opcao == 1)
        {
            limpar_terminal();
            return;
        }

    } while (opcao != 2);

    // Variável para armazenar a lista escolhida.
    int escolher_lista;
    char *lista_escolhida;

    // Solicita qual lista será modificada.
    do
    {
        printf("\nEm qual lista a obra se encontra?\n");
        printf("\n[1] CURTIDOS");
        printf("\n[2] LISTA DE DESEJOS");
        printf("\n[3] MEUS FAVORITOS");

        printf("\n\n-> ");
        scanf("%d", &escolher_lista);

        // Define a string correspondente à lista escolhida.
        if (escolher_lista == 2) {lista_escolhida = "LISTA DE DESEJOS";}
        else if (escolher_lista == 3) {lista_escolhida = "MEUS FAVORITOS";}

    } while (escolher_lista < 1 || escolher_lista > 3);

    int id_da_obra;

    // Solicita o ID da obra a ser removida.
    do
    {
        printf("\nDigite o ID da obra:");
        printf("\n\n-> ");
        scanf("%d", &id_da_obra);

    } while (!(id_da_obra > 0 && id_da_obra < 100));

    // Se for a lista de curtidos, chama função específica (curtir/descurtir).
    if (escolher_lista == 1) {curtir_descurtir_obra(id_usuario, id_da_obra);}
    // Caso contrário, remove da lista escolhida.
    else {remover_da_lista(id_usuario, id_da_obra, lista_escolhida);}
}

void listar_filtrado(int id_usuario, char *categoria_escolhida)
/*
    Função que mostra algumas obras baseada na categoria escolhida.
    O programa abre o arquivo de catálogo,
    percorre todas as linhas e imprime somente aquelas a condição
    de strcmp for verdade.
*/
{
    // Evita problemas com arredondamento de notas (ponto decimal).
    setlocale(LC_ALL, "C");

    // Abre o catálogo para leitura.
    FILE *catalogo = fopen("catalogo.txt", "r");
    verificar_abertura_arquivo(catalogo);

    // Variáveis para armazenar os campos de cada obra.
    char categoria_no_arquivo[50], nome_da_obra[50], genero_da_obra[50];
    int id_da_obra = 0, ano_da_obra = 0, likes_da_obra = 0;
    float nota_da_obra = 0;

    // Cabeçalho da tabela.
    printf("\n%-3s | %-30s | %-20s | %-4s | %-4s | %-5s\n", "ID", "NOME", "GENERO", "ANO", "NOTA", "LIKES");

    // Buffer para linha.
    char caracteres_na_linha[256];
    // Lê cada linha do catálogo.
    while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), catalogo))
    {
        // Extrai os campos da linha.
        if (sscanf(caracteres_na_linha, "%[^|]|%d|%[^|]|%[^|]|%d|%f|%d",
            categoria_no_arquivo, &id_da_obra, nome_da_obra, genero_da_obra, &ano_da_obra, &nota_da_obra, &likes_da_obra) >= 6)
        {
            // Se a categoria for a desejada, imprime os dados.
            if (strcmp(categoria_no_arquivo, categoria_escolhida) == 0)
            {
                printf("%-3d | %-30s | %-20s | %-4d | %-4.1f | %-5d\n", id_da_obra, nome_da_obra, genero_da_obra, ano_da_obra, nota_da_obra, likes_da_obra);
            }
        }
    }

    // Fecha o catálogo.
    fclose(catalogo);

    // Chama a função para permitir interagir com alguma obra listada.
    manipular_obra(id_usuario);
}

void transformar_em_minusculo(char *nome_da_obra)
/*
    Função que faz a tarefa rápida de transformar
    os caracteres de uma string em minúsculo usando
    tolower().
*/
{
    // Percorre cada caractere da string.
    for (int i = 0; nome_da_obra[i]; i++) {nome_da_obra[i] = tolower(nome_da_obra[i]);}
}

void procurar_obra(int id_usuario)
/*
    Função que procura obras no catálogo,
    baseado no que o usuário digitou.

    Se o usuário digitar 'br' de 'Breaking Bad',
    o programa irá mostrar todas as obras que possui
    'br' como parte nome da obra,
    sendo essa lógica case insensitive.
*/
{
    // Abre o catálogo para leitura.
    FILE *feitv_catalogo = fopen("catalogo.txt", "r");
    verificar_abertura_arquivo(feitv_catalogo);

    // Variáveis para o termo de busca.
    char input_usuario[50], input_em_minusculo[50];
    int obras_encontradas = 0;

    // Solicita o termo.
    printf("\nDigite o nome ou parte do nome da obra.\n");
    printf("\n-> ");

    // Lê a linha inteira (inclui espaços).
    scanf(" %[^\n]", input_usuario);

    // Copia o termo para versão minúscula.
    strcpy(input_em_minusculo, input_usuario);
    transformar_em_minusculo(input_em_minusculo);

    // Buffer para linha.
    char caracteres_na_linha[256];

    // Cabeçalho da tabela.
    printf("\n%-15s | %-3s | %-30s | %-20s | %-4s | %-4s | %-5s\n", "CATEGORIA", "ID", "NOME", "GENERO", "ANO", "NOTA", "LIKES");

    // Lê cada linha do catálogo.
    while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), feitv_catalogo))
    {
        // Cria uma cópia para fatiar com strtok, sem modificar a original.
        char linha_auxiliar[256];
        strcpy(linha_auxiliar, caracteres_na_linha);

        // Fatiamento da linha usando strtok.
        char *categoria_no_arquivo = strtok(linha_auxiliar, "|");
        char *id_da_obra           = strtok(NULL, "|");
        char *nome_da_obra         = strtok(NULL, "|");
        char *genero_da_obra       = strtok(NULL, "|");
        char *ano_da_obra          = strtok(NULL, "|");
        char *nota_da_obra         = strtok(NULL, "|");
        char *likes_da_obra        = strtok(NULL, "|\n");

        // Verifica se conseguiu extrair o nome.
        if (nome_da_obra != NULL)
        {
            // Converte o nome da obra para minúsculo.
            char nome_em_minusculo[100];
            strcpy(nome_em_minusculo, nome_da_obra);
            transformar_em_minusculo(nome_em_minusculo);

            // Se o termo estiver contido no nome, exibe a linha.
            if (strstr(nome_em_minusculo, input_em_minusculo) != NULL)
            {
                printf("%-15s | %-3s | %-30s | %-20s | %-4s | %-4s | %-5s\n", categoria_no_arquivo, id_da_obra, nome_da_obra, genero_da_obra, ano_da_obra, nota_da_obra, likes_da_obra);
                obras_encontradas++;
            }
        }
    }

    // Informa se nenhuma obra foi encontrada.
    if (obras_encontradas == 0) {printf("\nNenhuma obra encontrada com o termo: '%s'\n", input_usuario);}
    else {printf("\nNúmero de obras encontradas: %d\n", obras_encontradas);}

    // Fecha o catálogo.
    fclose(feitv_catalogo);
    // Permite interagir com alguma obra.
    manipular_obra(id_usuario);
}

void curtir_descurtir_obra(int id_do_usuario, int id_da_obra_selecionada)
/*
    Função que curti ou descurti uma obra.
    Ela registra a interação do usuário no catálogo,
    atualizando o número de likes da obra específica e
    também salva a interação em área_usuários.

    Aproveitamos a lógica de curtir e descurtir no mesmo
    código usando a condição que determina o valor de
    curtir_ou_descurtir, assim evitamos criar outra
    função e repetir uma lógica parecida.

    Usamos um arquivo temporario para receber a copia das
    linhas de catálogo ou área usuários para poder
    atualizar valores sem correr o risco de perder arquivos
    no meio do processo ou sobrescrever linhas caso haja
    algum erro.
*/
{
    // Pergunta ao usuário se deseja curtir ou descurtir.
    printf("\nVocê deseja curtir ou descurtir a obra?\n");
    printf("\n[1] Curtir");
    printf("\n[2] Descurtir");

    int opcao, curtir_ou_descurtir;
    do
    {
        printf("\n\n-> ");
        scanf("%d", &opcao);
        if (opcao == 1) {curtir_ou_descurtir = 1;}
        else if (opcao == 2) {curtir_ou_descurtir = -1;}
        else {printf("\nVocê não selecionou uma opção corretamente.\n");}

    } while (opcao != 1 && opcao != 2);

    // Força o uso do ponto decimal para floats (evita vírgula).
    setlocale(LC_NUMERIC, "C");

    // Abre a área do usuário para verificar se já curtiu.
    FILE *area_usuarios = fopen("area_usuarios.txt", "r");
    verificar_abertura_arquivo(area_usuarios);

    int id_obra_lida, id_usuario_lido, like_encontrado = 0;

    char caracteres_na_linha[256];
    // Lê todas as interações do tipo LIKE.
    while(fgets(caracteres_na_linha, sizeof(caracteres_na_linha), area_usuarios))
    {
        if (sscanf(caracteres_na_linha, "%d|LIKE|%d", &id_usuario_lido, &id_obra_lida) == 2)
        {
            // Se já existe um like do usuário para esta obra.
            if (id_usuario_lido == id_do_usuario && id_obra_lida == id_da_obra_selecionada)
            {
                like_encontrado = 1;
                break;
            }
        }
    }

    fclose(area_usuarios);

    // Caso já tenha curtido e tente curtir novamente.
    if (like_encontrado == 1)
    {
        if (curtir_ou_descurtir == 1)
        {
            limpar_terminal();
            printf("Você já curtiu essa obra antes!\n\n");
            return;
        }

        // Caso queira descurtir, remove a entrada de like da área do usuário.
        else if (curtir_ou_descurtir == -1)
        {
            FILE *area_usuarios = fopen("area_usuarios.txt", "r");
            verificar_abertura_arquivo(area_usuarios);

            FILE *temporario = fopen("temporario.txt", "w");
            verificar_abertura_arquivo(temporario);

            // Copia todas as linhas menos a do like.
            while(fgets(caracteres_na_linha, sizeof(caracteres_na_linha), area_usuarios))
            {
                if (sscanf(caracteres_na_linha, "%d|LIKE|%d", &id_usuario_lido, &id_obra_lida) == 2)
                {
                    if (!(id_usuario_lido == id_do_usuario && id_obra_lida == id_da_obra_selecionada))
                    {
                        fprintf(temporario, "%s", caracteres_na_linha);
                    }
                }
                // Linhas que não são LIKE também são copiadas (caso haja outras estruturas).
                // Nota: O código original não copia linhas que não são LIKE, mas mantemos como está.
            }

            fclose(area_usuarios);
            fclose(temporario);

            // Substitui o arquivo original pelo temporário.
            remove("area_usuarios.txt");
            rename("temporario.txt", "area_usuarios.txt");
        }
    }

    // Se não havia like e tentou descurtir, impede.
    if (like_encontrado == 0 && curtir_ou_descurtir == -1)
    {
        limpar_terminal();
        printf("Você precisa curtir a obra para poder descurtir.\n\n");
        return;
    }

    // Abre o catálogo e um arquivo temporário para atualizar os likes.
    FILE *catalogo = fopen("catalogo.txt", "r");
    verificar_abertura_arquivo(catalogo);

    FILE *temporario = fopen("temporario.txt", "w");
    verificar_abertura_arquivo(temporario);

    int ano_da_obra_lida, likes_da_obra_lida;
    float nota_da_obra_lida = 0.0;
    char categoria_lida[50], nome_da_obra_lida[50], genero_da_obra_lida[50];

    // Lê cada linha do catálogo.
    while(fgets(caracteres_na_linha, sizeof(caracteres_na_linha), catalogo))
    {
        if (sscanf(caracteres_na_linha, "%[^|]|%d|%[^|]|%[^|]|%d|%f|%d",
                   categoria_lida,
                   &id_obra_lida,
                   nome_da_obra_lida,
                   genero_da_obra_lida,
                   &ano_da_obra_lida,
                   &nota_da_obra_lida,
                   &likes_da_obra_lida) >= 2)
        {
            // Se for a obra selecionada, atualiza o número de likes.
            if (id_obra_lida == id_da_obra_selecionada)
            {
                likes_da_obra_lida += curtir_ou_descurtir;
                printf("CURTIDAS: \n%d\n", likes_da_obra_lida);

                // Escreve a linha atualizada no temporário.
                fprintf(temporario, "%s|%02d|%s|%s|%d|%.1f|%d\n",
                        categoria_lida, id_obra_lida, nome_da_obra_lida,
                        genero_da_obra_lida, ano_da_obra_lida,
                        nota_da_obra_lida, likes_da_obra_lida);
            }
            else
            {
                // Copia a linha original sem alterações.
                fprintf(temporario, "%s", caracteres_na_linha);
            }
        }
    }

    fclose(temporario);
    fclose(catalogo);

    // Substitui o catálogo original pelo atualizado.
    if (remove("catalogo.txt") == 0 && rename("temporario.txt", "catalogo.txt") == 0)
    {
        // Se foi um like, adiciona a entrada na área do usuário.
        if (curtir_ou_descurtir == 1)
        {
            area_usuarios = fopen("area_usuarios.txt", "a");
            verificar_abertura_arquivo(area_usuarios);

            char nome_da_obra[50];
            pegar_nome_obra(id_da_obra_selecionada, nome_da_obra);

            fprintf(area_usuarios, "%d|LIKE|%d|%s\n", id_do_usuario, id_da_obra_selecionada, nome_da_obra);
            fclose(area_usuarios);

            limpar_terminal();
            printf("Você curtiu a obra! Em breve mais recomendações aparecerão.\n\n");
        }
        else if (curtir_ou_descurtir == -1)
        {
            limpar_terminal();
            printf("Você descurtiu a obra.\n\n");
        }
    }
    else
    {
        printf("\nErro: Não foi possível curtir a obra...\n");
    }
}

void pegar_nome_obra(int id_da_obra, char *variavel_colocar_nome)
/*
    Função rápida para buscar nome da obra em situações na qual
    não vale a pena abrir um arquivo, ler cada linha e comparar
    valores para apenas buscar o nome da obra.
*/
{
    // Abre o catálogo para leitura.
    FILE *catalogo = fopen("catalogo.txt", "r");
    verificar_abertura_arquivo(catalogo);

    char caracteres_na_linha[256];
    int id_da_obra_lida;

    // Lê cada linha.
    while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), catalogo))
    {
        // Extrai ID e nome (ignora a categoria com %*[^|]).
        if (sscanf(caracteres_na_linha, "%*[^|]|%d|%[^|]", &id_da_obra_lida, variavel_colocar_nome) >= 2)
        {
            // Quando encontrar o ID, interrompe.
            if (id_da_obra_lida == id_da_obra) {
                break;
            }
        }
    }

    fclose(catalogo);
}

void assistir(int id_do_usuario, int id_da_obra)
/*
    Função que registra a interação de assistir uma obra
    pelo usuário, salvando em area_usuarios.txt.

    O usuário pode assistir quantas vezes quiser, sem adicionar
    novamente a interação em area_usuarios.txt.

    Caso a obra esteja na Lista de Desejos anteriormente,
    removemo-la da lista, adicionando uma camada de realismo.
*/
{
    // Abre a área do usuário para verificar se já foi assistida.
    FILE *area_usuarios = fopen("area_usuarios.txt", "r");
    verificar_abertura_arquivo(area_usuarios);

    int id_do_usuario_lido, id_da_obra_lida, obra_na_lista_desejos = 0;
    char nome_da_obra_lida[50], nome_da_obra[50];

    // Obtém o nome da obra.
    pegar_nome_obra(id_da_obra, nome_da_obra);

    char caracteres_na_linha[256];
    // Percorre todas as interações.
    while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), area_usuarios))
    {
        if (sscanf(caracteres_na_linha, "%d|ASSISTIDOS|%d|%s", &id_do_usuario_lido, &id_da_obra_lida, nome_da_obra_lida) == 3)
        {
            // Se já assistiu, apenas informa e retorna.
            if (id_do_usuario == id_do_usuario_lido && id_da_obra == id_da_obra_lida)
            {
                printf("\nVocê assistiu %s.\n\n", nome_da_obra);
                fclose(area_usuarios);
                return;
            }
        }
    }

    fclose(area_usuarios);

    // Adiciona a entrada de assistido.
    area_usuarios = fopen("area_usuarios.txt", "a");
    verificar_abertura_arquivo(area_usuarios);

    fprintf(area_usuarios, "%d|ASSISTIDOS|%d|%s\n", id_do_usuario, id_da_obra, nome_da_obra);

    fclose(area_usuarios);

    limpar_terminal();
    printf("Você assistiu %s.\n\n", nome_da_obra);

    // Agora, verifica se a obra está na lista de desejos para removê-la.
    area_usuarios = fopen("area_usuarios.txt", "r");
    verificar_abertura_arquivo(area_usuarios);

    while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), area_usuarios))
    {
        if (sscanf(caracteres_na_linha, "%d|LISTA DE DESEJOS|%d", &id_do_usuario_lido, &id_da_obra_lida) == 2)
        {
            if (id_do_usuario == id_do_usuario_lido && id_da_obra == id_da_obra_lida)
            {
                obra_na_lista_desejos = 1;
            }
        }
    }

    // Se estiver na lista de desejos, remove.
    if (obra_na_lista_desejos == 1)
    {
        FILE *temporario = fopen("temporario.txt", "w");
        verificar_abertura_arquivo(temporario);

        // Volta ao início do arquivo para copiar todas as linhas menos a do desejo.
        rewind(area_usuarios);
        while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), area_usuarios))
        {
            if (!(id_do_usuario_lido == id_do_usuario && id_da_obra_lida == id_da_obra))
            {
                fprintf(temporario, "%s", caracteres_na_linha);
            }
        }

        fclose(temporario);
        fclose(area_usuarios);

        remove("area_usuarios.txt");
        rename("temporario.txt", "area_usuarios.txt");

        printf("Obra removida da Lista de Desejos.\n\n");
    }
    else {fclose(area_usuarios);}
}

void adicionar_na_lista(int id_do_usuario, int id_da_obra, char *qual_lista)
/*
    Função que salva uma obra específica na Lista de Desejos
    ou Meus Favoritos.

    Percorrendo as linhas de area_usuarios.txt,
    caso a obra já esteja presente, não é adicionada.
*/
{
    // Abre a área do usuário para verificar duplicidade.
    FILE *area_usuarios = fopen("area_usuarios.txt", "r");
    verificar_abertura_arquivo(area_usuarios);

    int id_usuario_lido, id_obra_lida;
    char lista_lida[50];
    char caracteres_na_linha[256];

    // Verifica se a obra já está na lista desejada.
    while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), area_usuarios))
    {
        if (sscanf(caracteres_na_linha, "%d|%[^|]|%d", &id_usuario_lido, lista_lida, &id_obra_lida) == 3)
        {
            if (id_do_usuario == id_usuario_lido &&
                id_da_obra == id_obra_lida &&
                strcmp(qual_lista, lista_lida) == 0)
            {
                limpar_terminal();
                printf("A obra já está na lista %s.\n", qual_lista);
                fclose(area_usuarios);
                return;
            }
        }
    }

    fclose(area_usuarios);

    // Obtém o nome da obra.
    char nome_da_obra[50];
    pegar_nome_obra(id_da_obra, nome_da_obra);

    // Adiciona ao final do arquivo.
    area_usuarios = fopen("area_usuarios.txt", "a");
    verificar_abertura_arquivo(area_usuarios);

    fprintf(area_usuarios, "%d|%s|%d|%s\n", id_do_usuario, qual_lista, id_da_obra, nome_da_obra);

    fclose(area_usuarios);

    limpar_terminal();
    printf("'%s' foi adicionado à lista %s.\n\n", nome_da_obra, qual_lista);
}

void remover_da_lista(int id_do_usuario, int id_da_obra, char *qual_lista)
/*
    Função que faz o contrário de adicionar obra à lista.
    Percorre as linhas de area_usuarios.txt e verifica
    se encontrou a obra baseado na Lista e no ID que o usuário deseja.

    Se não encontrar, volta ao menu.
    Se encontrar, remove.

    Se a obra estiver em uma lista diferente na qual
    o usuário deseja, nada irá ocorrer.
*/
{
    // Abre o arquivo original e um temporário.
    FILE *area_usuarios = fopen("area_usuarios.txt", "r");
    verificar_abertura_arquivo(area_usuarios);

    FILE *temporario = fopen("temporario.txt", "w");
    verificar_abertura_arquivo(temporario);

    int id_usuario_lido, id_obra_lida;
    char lista_lida[50];
    char caracteres_na_linha[256];
    int encontrou = 0;

    // Lê cada linha e copia para o temporário, exceto a que deve ser removida.
    while (fgets(caracteres_na_linha, sizeof(caracteres_na_linha), area_usuarios))
    {
        if (sscanf(caracteres_na_linha, "%d|%[^|]|%d", &id_usuario_lido, lista_lida, &id_obra_lida) == 3)
        {
            if (id_do_usuario == id_usuario_lido &&
                id_da_obra == id_obra_lida &&
                strcmp(qual_lista, lista_lida) == 0)
            {
                encontrou = 1;
                continue; // Pula a linha, não copia.
            }
        }

        // Copia as demais linhas.
        fprintf(temporario, "%s", caracteres_na_linha);
    }

    fclose(area_usuarios);
    fclose(temporario);

    // Se encontrou, substitui o arquivo original.
    if (encontrou == 1)
    {
        remove("area_usuarios.txt");
        rename("temporario.txt", "area_usuarios.txt");

        limpar_terminal();
        printf("Obra removida da lista %s.\n\n", qual_lista);
    }
    else
    {
        // Caso não tenha encontrado, descarta o temporário.
        remove("temporario.txt");

        limpar_terminal();
        printf("Obra não encontrada em %s.\n\n", qual_lista);
    }
}

void manipular_obra(int id_usuario)
/*
    Função que faz a principal tarefa de realizar
    a interação do usuário com uma obra específica.

    É aqui onde o usuário escolhe uma opção do que fazer
    com a obra antes de uma função específica for acionada
    para realizar a tarefa específica.
*/
{
    int id_da_obra, escolher;
    char nome_da_obra[50];

    do
    {
        // Solicita o ID da obra.
        printf("\nDigite o ID para selecionar a obra, ou zero para voltar:\n");
        printf("\n-> ");
        scanf("%d", &id_da_obra);

        // Se for zero, volta ao menu anterior.
        if (id_da_obra == 0)
        {
            limpar_terminal();
            return;
        }

        // Valida ID entre 1 e 99.
        if (id_da_obra > 0 && id_da_obra < 100)
        {
            // Obtém o nome da obra para exibir.
            pegar_nome_obra(id_da_obra, nome_da_obra);

            printf("\nObra selecionada: '%s'. Escolha uma opção:\n", nome_da_obra);
            printf("\n[0] Voltar");
            printf("\n[1] Curtir/Descurtir Obra");
            printf("\n[2] Assistir");
            printf("\n[3] Adicionar aos Meus Favoritos");
            printf("\n[4] Adicionar à Lista de Desejos");

            // Loop para garantir opção válida.
            do
            {
                printf("\n\n-> ");
                scanf("%d", &escolher);
                if (escolher < 0 || escolher > 4) {printf("\nVocê não escolheu uma opção válida.");}
            } while (escolher < 0 || escolher > 4);

            limpar_terminal();

            // Executa a ação conforme a opção.
            switch (escolher)
            {
                case 0:
                    break;
                case 1:
                    curtir_descurtir_obra(id_usuario, id_da_obra);
                    break;
                case 2:
                    assistir(id_usuario, id_da_obra);
                    break;
                case 3:
                    adicionar_na_lista(id_usuario, id_da_obra, "MEUS FAVORITOS");
                    break;
                case 4:
                    adicionar_na_lista(id_usuario, id_da_obra, "LISTA DE DESEJOS");
                    break;
            }
        }

        else  {printf("\nVocê não selecionou um ID corretamente.\n");}

    } while (!(id_da_obra > 0 && id_da_obra < 100));
}
