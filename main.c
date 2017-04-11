#include <locale.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Variáveis
int idx;

//Funções
void MenuPricipal();
void setDefaultValues();
void redirecionamento();
void Receitas();
void Cardapios();
void TiposDeReceitas();
void ListarReceitas();
void ListarCardapios();
void ListarTiposDeReceitas();
void EditarReceitas();
void EditarCardapios();
void EditarTiposDeReceitas();
void AdicionarReceitas();
void AdicionarCardapios();
void AdicionarTiposDeReceitas();
void ExcluirReceitas();
void ExcluirCardapios();
void ExcluirTiposDeReceitas();
int lestring();
char s[20];
int t;

//Structs
struct DadosReceita {
    char   nome[50];
    char    tipo[30];
    char   ingredientes[200];
    char   mododefazer[200];
    char   cardapio[50];
};

struct DadosReceita receitas[30];
struct DadosReceita aux;

struct DadosCardapio{
    char nome[30];
    char receitas[30];
};

struct DadosCardapio cardapio[9];

struct DadosTiposDeReceitas{
    char nome[30];
};

struct DadosTiposDeReceitas tiposdereceitas[4];

void MenuPricipal(){
    int menu;
    system("@cls||clear");
    printf("############################################\n");
    printf("#                  Menu                    #\n");
    printf("#                                          #\n");
    printf("#             1 - Receitas                 #\n");
    printf("#             2 - Tipos de Receitas        #\n");
    printf("#             3 - Cardápio                 #\n");
    printf("#                                          #\n");
    printf("############################################\n");
    scanf("%d",&menu);

    switch (menu){
        case 1:
            system("@cls||clear");
            Receitas();
            break;
        case 2:
            system("@cls||clear");
            TiposDeReceitas();
            break;
        case 3:
            system("@cls||clear");
            Cardapios();
            break;
        default:
            system("@cls||clear");
            printf("Menu não existe!!!!!\n");
            redirecionamento();
            MenuPricipal();
    }
    return;
}

void Receitas(){
    int menu = 0;
    system("@cls||clear");
    printf("############################################\n");
    printf("#                Receitas                  #\n");
    printf("#                                          #\n");
    printf("#             1 - Listar                   #\n");
    printf("#             2 - Editar                   #\n");
    printf("#             3 - Adicionar                #\n");
    printf("#             4 - Excluir                  #\n");
    printf("#             5 - Voltar                   #\n");
    printf("#                                          #\n");
    printf("############################################\n");
    scanf("%d",&menu);

    switch (menu){
        case 1:
            system("@cls||clear");
            ListarReceitas();
            break;
        case 2:
            system("@cls||clear");
            EditarReceitas();
            break;
        case 3:
            system("@cls||clear");
            AdicionarReceitas();
            break;
        case 4:
            system("@cls||clear");
            ExcluirReceitas();
            break;
        case 5:
            system("@cls||clear");
            MenuPricipal();
            break;
        default:
            system("@cls||clear");
            printf("Menu não existe!!!!!\n");
            redirecionamento();
            Receitas();
    }
    return;
}

void ListarReceitas(){
    int i, menu;
    for (i = 0; i < 30; i++){
        if (*receitas[i].nome != '\0'){

            printf("%d - %s - Tipo: %s |  Ingredientes: %s | Modo de Fazer: %s \n",i,receitas[i].nome, receitas[i].tipo, receitas[i].ingredientes, receitas[i].mododefazer);
        }
    }
    scanf("%d",&menu);
    if (receitas[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        ListarReceitas();
    } else{
        printf("Receita: %s, selecionada!", receitas[menu].nome);
    }
    return;
}
void EditarReceitas(){
    int i, menu;
    char nome[30];
    char nome2[30];
    char senha1[21];
    printf("Seleciona umas das Receitas:\n");
    for (i = 0; i < 30; i++){
        if (*receitas[i].nome != '\0'){

            printf("%d - %s - Tipo: %s |  Ingredientes: %s | Modo de Fazer: %s \n",i,receitas[i].nome, receitas[i].tipo, receitas[i].ingredientes, receitas[i].mododefazer);
        }
    }
    scanf("%d",&menu);
    if (receitas[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        ListarReceitas();
    } else{
        int menu2;
        system("@cls||clear");
        printf("Receita: %s, selecionada!\n", receitas[menu].nome);
        //printf("############################################\n");
        printf("#           O que deseja Editar?           #\n");
        printf("#                                          #\n");
        printf("#             1 - Nome                     #\n");
        printf("#             2 - Tipo                     #\n");
        printf("#             3 - Ingredientes             #\n");
        printf("#             4 - Modo de Fazer            #\n");
        printf("#             5 - Cardápio                 #\n");
        printf("#             6 - Voltar                   #\n");
        printf("#                                          #\n");
        printf("############################################\n");
        scanf("%d",&menu2);
        switch (menu2){
            case 1:
                system("@cls||clear");
                printf("Insira o novo nome: \n");
                t = lestring(s, 20);
                strcpy(receitas[menu].nome, s);
                Receitas();
                break;
            case 2:
                system("@cls||clear");
                printf("Insira o novo tipo: \n");
                t = lestring(s, 20);
                strcpy(receitas[menu].tipo, s);
                Receitas();
                break;
            case 3:
                system("@cls||clear");
                printf("Insira o novo ingredientes: \n");
                t = lestring(s, 20);
                strcpy(receitas[menu].ingredientes, s);
                Receitas();
                break;
            case 4:
                system("@cls||clear");
                printf("Insira o novo modo de fazer: \n");
                t = lestring(s, 20);
                strcpy(receitas[menu].mododefazer, s);
                Receitas();
                break;
            case 5:
                system("@cls||clear");
                printf("Insira o novo cardapio: \n");
                t = lestring(s, 20);
                strcpy(receitas[menu].cardapio, s);
                Receitas();
                break;
            case 6:
                system("@cls||clear");
                MenuPricipal();
                break;
            default:
                system("@cls||clear");
                printf("Opção não existe!!!!!\n");
                redirecionamento();
                MenuPricipal();
        }
    }
    return;
}
void AdicionarReceitas(){
    int i = 0;
    for( i = 0; i < 30 ; i++){
        if (*receitas[i].nome == '\0'){
            break;
        }
    }
    printf("Insira a nova Nome da receita: \n");
    t = lestring(s, 50);
    strcpy(receitas[i].nome,s);
    printf("Insira a nova Tipo da receita: \n");
    t = lestring(s, 50);
    strcpy(receitas[i].tipo,s);
    printf("Insira o novo Ingradiente da receita: \n");
    t = lestring(s, 150);
    strcpy(receitas[i].ingredientes,s);
    printf("Insira o novo Modo de fazer da receita: \n");
    t = lestring(s, 50);
    strcpy(receitas[i].mododefazer,s);
    printf("Insira o novo Cardapio da receita: \n");
    t = lestring(s, 50);
    strcpy(receitas[i].cardapio,s);
    MenuPricipal();
    return;
}
void ExcluirReceitas(){
    int i=0, menu;
    for (i = 0; i < 30; i++){
        if (*receitas[i].nome != '\0'){

            printf("%d - %s - Tipo: %s |  Ingredientes: %s | Modo de Fazer: %s \n",i,receitas[i].nome, receitas[i].tipo, receitas[i].ingredientes, receitas[i].mododefazer);
        }
    }
    scanf("%d",&menu);
    for( i = menu; i < 30; i++){
        if (*receitas[i].nome != '\0'){

            strcpy(receitas[i].nome,receitas[i+1].nome);
            strcpy(receitas[i].tipo,receitas[i+1].tipo);
            strcpy(receitas[i].ingredientes,receitas[i+1].ingredientes);
            strcpy(receitas[i].mododefazer,receitas[i+1].mododefazer);
            strcpy(receitas[i].cardapio,receitas[i+1].cardapio);

            }
    }
    MenuPricipal();
    return;
}
void Cardapios(){
    int menu;
    system("@cls||clear");
    printf("############################################\n");
    printf("#               Cardápios                  #\n");
    printf("#                                          #\n");
    printf("#             1 - Listar                   #\n");
    printf("#             2 - Editar                   #\n");
    printf("#             3 - Adicionar                #\n");
    printf("#             4 - Excluir                  #\n");
    printf("#                                          #\n");
    printf("############################################\n");
    scanf("%d",&menu);

    switch (menu){
        case 1:
            system("@cls||clear");
            ListarCardapios();
            break;
        case 2:
            system("@cls||clear");
            EditarCardapios();
            break;
        case 3:
            system("@cls||clear");
            AdicionarCardapios();
            break;
        case 4:
            system("@cls||clear");
            ExcluirCardapios();
            break;
        default:
            system("@cls||clear");
            //system(limpar);
            printf("Menu não existe!!!!!\n");
            redirecionamento();
            MenuPricipal();
    }
    return;
}
void ListarCardapios(){
    int i, menu;
    for (i = 0; i < 9; i++){
        if (*cardapio[i].nome != '\0'){

            printf("%d - %s\n",i,cardapio[i].nome);
        }
    }
    scanf("%d",&menu);
    if (cardapio[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        ListarCardapios();
    } else{
        printf("Cardápio: %s, selecionado!", cardapio[menu].nome);
    }
    return;
}
void EditarCardapios(){
    int i, menu;
    char nome[30];
    char nome2[30];
    char senha1[21];
    printf("Seleciona um dos Cardápios:\n");
    for (i = 0; i < 9; i++){
        if (*cardapio[i].nome != '\0'){

            printf("%d - %s\n",i,cardapio[i].nome);
        }
    }
    scanf("%d",&menu);
    if (cardapio[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        ListarReceitas();
    } else{
        int menu2;
        system("@cls||clear");
        printf("Cardápio: %s, selecionada!\n", cardapio[menu].nome);
        //printf("############################################\n");
        printf("#           O que deseja Editar?           #\n");
        printf("#                                          #\n");
        printf("#             1 - Nome                     #\n");
        printf("#                                          #\n");
        printf("############################################\n");
        scanf("%d",&menu2);
        switch (menu2){
            case 1:
                system("@cls||clear");
                printf("Insira o novo nome: \n");
                t = lestring(s, 20);
                strcpy(cardapio[menu].nome, s);
                Cardapios();
                break;
            case 2:
                system("@cls||clear");
                printf("Insira a nova receita: \n");
                t = lestring(s, 20);
                strcpy(receitas[menu].tipo, s);
                Cardapios();
                break;
            default:
                system("@cls||clear");
                printf("Opção não existe!!!!!\n");
                redirecionamento();
                MenuPricipal();
        }
    }
    return;
}
void AdicionarCardapios(){
    return;
}
void ExcluirCardapios(){
    return;
}
void TiposDeReceitas(){
    int menu;
    system("@cls||clear");
    printf("############################################\n");
    printf("#            Tipos de Receitas             #\n");
    printf("#                                          #\n");
    printf("#             1 - Listar                   #\n");
    printf("#             2 - Editar                   #\n");
    printf("#             3 - Adicionar                #\n");
    printf("#             4 - Excluir                  #\n");
    printf("#                                          #\n");
    printf("############################################\n");
    scanf("%d",&menu);

    switch (menu){
        case 1:
            system("@cls||clear");
            ListarTiposDeReceitas();
            break;
        case 2:
            system("@cls||clear");
            EditarTiposDeReceitas();
            break;
        case 3:
            system("@cls||clear");
            AdicionarTiposDeReceitas();
            break;
        case 4:
            system("@cls||clear");
            ExcluirTiposDeReceitas();
            break;
        default:
            system("@cls||clear");
            printf("Menu não existe!!!!!\n");
            redirecionamento();
            MenuPricipal();
    }
    return;
}
void ListarTiposDeReceitas(){
    int i, menu;
    for (i = 0; i < 4; i++){
        if (*tiposdereceitas[i].nome != '\0'){
            printf("%d - %s \n",i,tiposdereceitas[i].nome);
        }
    }
    scanf("%d",&menu);
    if (*tiposdereceitas[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        ListarTiposDeReceitas();
    } else{
        printf("Tipo: %s, selecionada!", tiposdereceitas[menu].nome);
    }
    return;
}
void EditarTiposDeReceitas(){
    int i, menu;
    char nome[30];
    char nome2[30];
    char senha1[21];
    printf("Seleciona um dos Cardápios:\n");
    for (i = 0; i < 4; i++){
        if (*tiposdereceitas[i].nome != '\0'){
            printf("%d - %s \n",i,tiposdereceitas[i].nome);
        }
    }
    scanf("%d",&menu);
    if (tiposdereceitas[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        ListarReceitas();
    } else{
        int menu2;
        system("@cls||clear");
        printf("Tipo de Receita: %s, selecionada!\n", tiposdereceitas[menu].nome);
        //printf("############################################\n");
        printf("#           O que deseja Editar?           #\n");
        printf("#                                          #\n");
        printf("#             1 - Nome                     #\n");
        printf("#                                          #\n");
        printf("############################################\n");
        scanf("%d",&menu2);
        switch (menu2){
            case 1:
                system("@cls||clear");
                printf("Insira o novo nome: \n");
                t = lestring(s, 20);
                strcpy(tiposdereceitas[menu].nome, s);
                TiposDeReceitas();
                break;
            default:
                system("@cls||clear");
                printf("Opção não existe!!!!!\n");
                redirecionamento();
                TiposDeReceitas();
        }
    }
    return;
}
void AdicionarTiposDeReceitas(){
    return;
}
void ExcluirTiposDeReceitas(){
    return;
}
void redirecionamento(){
    int i;
    for(i = 3; i > 0;i--){
        printf("Você será redirecionado em %d",i);
        usleep(1000*1000);
        printf("\n");
    }
    return;
}

void setDefaultValues(){
    //Tipos de Receitas
    strcpy(tiposdereceitas[0].nome,"Bebida");
    strcpy(tiposdereceitas[1].nome,"Prato Salgado");
    strcpy(tiposdereceitas[2].nome,"Sobremesa");

    //Receitas
    strcpy(receitas[0].nome,"Suco de Limão"); strcpy(receitas[0].tipo,"Bebida"); strcpy(receitas[0].ingredientes,"Água, Limão");strcpy(receitas[0].mododefazer,"Pegue uma jarra, coloque água, esprema o limão, misture.");strcpy(receitas[0].cardapio,"Almoço de Domingo");
    strcpy(receitas[1].nome,"Suco de Laraja"); strcpy(receitas[1].tipo,"Bebida"); strcpy(receitas[1].ingredientes,"Água, Laranja"); strcpy(receitas[1].mododefazer,"Pegue uma jarra, coloque água, esprema a laranja, misture."); strcpy(receitas[1].cardapio,"Almoço de Domingo");
    strcpy(receitas[2].nome,"Carne Assada"); strcpy(receitas[2].tipo,"Prato Salgado"); strcpy(receitas[2].ingredientes,"Carne de Boi, Temperos"); strcpy(receitas[2].mododefazer,"Tempere a Carne, coloque na churrasqueira."); strcpy(receitas[2].cardapio,"Jantar de Sexta");
    strcpy(receitas[3].nome,"Cerveja"); strcpy(receitas[3].tipo,"Bebida"); strcpy(receitas[3].ingredientes,"Cerveja"); strcpy(receitas[3].mododefazer,"Abra a latinha, tome."); strcpy(receitas[3].cardapio,"Jantar de Sexta");
    strcpy(receitas[4].nome,"Salgado"); strcpy(receitas[4].tipo,"Prato Salgado"); strcpy(receitas[4].ingredientes,"Massa, Recehio"); strcpy(receitas[4].mododefazer,"Faça a massa, recheie, asse."); strcpy(receitas[4].cardapio,"Jantar de Sexta");
    strcpy(receitas[5].nome,"Prato Tradicional"); strcpy(receitas[5].tipo,"Prato Salgado"); strcpy(receitas[5].ingredientes,"Arroz, Feijão, Carne, Macarrão, Salada."); strcpy(receitas[5].mododefazer,"Prepare tudo, coloque no prato."); strcpy(receitas[5].cardapio,"Almoço de Domingo");
    strcpy(receitas[6].nome,"Leite com Toddy"); strcpy(receitas[6].tipo,"Bebida"); strcpy(receitas[6].ingredientes,"Leite, Toddy"); strcpy(receitas[6].mododefazer,"Coloque o leite no copo, adicione duas colheres de Toddy, misture."); strcpy(receitas[6].cardapio,"Café da Manhã de Sábado");
    strcpy(receitas[7].nome,"Bolo de Chocolate");strcpy(receitas[7].tipo,"Sobremesa");strcpy(receitas[7].ingredientes,"4 ovos, 4 colheres de Toddy, 2 colheres de manteiga, 2 xícaras de açucar, 3 xícaras de varinha de trigo, 1 xícara de leite, 1 colher de fermento.");strcpy(receitas[7].mododefazer,"Misture tudo, asse.");strcpy(receitas[7].cardapio,"Café da Manhã de Sábado");
    strcpy(receitas[8].nome,"Bolo de Cenoura"); strcpy(receitas[8].tipo,"Sobremesa"); strcpy(receitas[8].ingredientes,"1/2 xícara (chá) de óleo, 3 cenouras médias raladas, 4 ovos, 2 xícaras (chá) de açúcar, 2 e 1/2 xícaras (chá) de farinha de trigo, 1 colher (sopa) de fermento em pó."); strcpy(receitas[8].mododefazer,"PMisture tudo, asse."); strcpy(receitas[8].cardapio,"Café da Manhã de Sábado");
    strcpy(receitas[9].nome,"Mousse de Maracujá"); strcpy(receitas[9].tipo,"Sobremesa"); strcpy(receitas[9].ingredientes,"2 caixas de gelatina de maracujá, 2 xícaras de água quente, 1/2 xícara de suco de maracujá, 2 xícaras de leite de vaca, 1 lata de leite condensado, 1 lata de creme de leite sem soro"); strcpy(receitas[9].mododefazer,"Misture tudo e coloque na geldeira."); strcpy(receitas[9].cardapio,"Café da Manhã de Sábado");

    //Cárdapios
    strcpy(cardapio[0].nome,"Almoço de Domingo");
    strcpy(cardapio[1].nome,"Jantar de Sábado");
    strcpy(cardapio[2].nome,"Café da manhã de Sábado");

    return;
}

int main(){
    setlocale(LC_ALL,"");
    setDefaultValues();
    MenuPricipal();
    return 0;
}

int lestring(char s[], int max)
{
    int i = 0;
    char letra;

    /* No caso o max é o tamanho que s pode receber. Deve ser passado o tamanho
       mesmo, ou seja, se for passado 100 a função já se encarrega de não deixar
       passar de 99 cars (+1 do finalizador)
     */
    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);

        /* Veja que se encontrou um ENTER (\n) mas não leu nenhum caractere válido,
              * não aceita. Precisa ler algo. Decrementa o i para anular o efeito do i++
              * do laço e volta no laço com continue
         */
        if ((letra == '\n') && (i == 0)) {
            i = i - 1;
            continue;
        }

        /* Agora se leu um enter já tendo lido caracteres válidos, então
         * o usuário terminou de digitar sua string e ela possui ao menos
         * um caractere válido
         */
        if (letra == '\n')
            break;
        s[i] = letra;
    }

    /* Finaliza a string */
    s[i] = 0;

    /* retorna a quantidade de cars lidos (pode ser útil). Então, esta função
       lê uma string e retorna o seu tamanho
     */
    return (i);
}