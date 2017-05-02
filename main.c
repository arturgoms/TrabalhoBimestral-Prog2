#include <locale.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <windows.h>

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
void Comparador();
void Comparador2();
void Ordena();
int lestring();
char s[20];
int t;

//Structs
struct DadosReceita {
    char   nome[50];
    char   tipo[30];
    char   ingredientes[200];
    char   mododefazer[200];
    char   cardapio[50];
};

struct DadosReceita receitas[30];
struct DadosReceita aux;

struct DadosCardapio{
    char nome[30];
    char receitas[30];
    char id[10];
};

struct DadosCardapio cardapio[9];

struct DadosTiposDeReceitas{
    char nome[30];
    char id[10];
};

struct DadosTiposDeReceitas tiposdereceitas[9];

int lestring(char s[], int max)
{
    int i = 0;
    char letra;
    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);
        if ((letra == '\n') && (i == 0)) {
            i = i - 1;
            continue;
        }
        if (letra == '\n')
            break;
        s[i] = letra;
    }
    s[i] = 0;
    return (i);
}
void ordenaNomes(int tamanho){
    char sNomeAux[255];
    for( int i = 1; i < tamanho; i++ ) {
        for( int j = i; j > 0; j-- ) {
            if( strcoll(receitas[j].nome, receitas[j-1].nome) < 0){
                strcpy(sNomeAux,receitas[j].nome);
                strcpy(receitas[j].nome,receitas[j-1].nome);
                strcpy(receitas[j-1].nome,sNomeAux);}
        }
    }
}
void ordenaCardapios(int tamanho){
    char sNomeAux[255];
    for( int i = 1; i < tamanho; i++ ) {
        for( int j = i; j > 0; j-- ) {
            if( strcoll(cardapio[j].nome, cardapio[j-1].nome) < 0){
                strcpy(sNomeAux,cardapio[j].nome);
                strcpy(cardapio[j].nome,cardapio[j-1].nome);
                strcpy(cardapio[j-1].nome,sNomeAux);}
        }
    }
}
void Comparador(int i, int grupo)
{
    int j = 0, menu, menu2;
    bool whilesair = false;

    if(grupo == 1){
        while(1){
            printf("Você adicionará a receita %s à um tipo já existente?\n(1)Sim ou (0)Não\n", receitas[i].nome);
            scanf("%d", &menu);
            switch(menu){
                case 0:
                    printf("Insira o novo tipo da receita %s: \n", receitas[i].nome);
                    t = lestring(s, 50);
                    strcpy(receitas[i].tipo,s);
                    //cria novo tipo de receita em tiposdereceitas
                    for (j = 0; j < 9; j++){
                        if (*tiposdereceitas[j].nome == '\0'){
                            break;
                        }
                    }
                    strcpy(tiposdereceitas[j].nome,s);
                    whilesair = true;
                    break;
                case 1:
                    while(1){
                        //adiciona um tipo de receita já existente na receita
                        printf("Qual?\n");
                        for (j = 0; j < 9; j++){
                            if (*tiposdereceitas[j].nome != '\0'){
                                printf("%d - %s\n", j, tiposdereceitas[j].nome);
                            }
                        }
                        scanf("%d", &menu2);
                        if(*tiposdereceitas[menu2].nome == '\0'){
                            printf("Tipo nº%d não existe!!!!!\n", menu2);
                        } else{
                            printf("%s\n", tiposdereceitas[menu2].nome);
                            strcpy(receitas[i].tipo,tiposdereceitas[menu2].nome);
                            whilesair = true;
                            break;
                        }
                    }
                    break;
                default:
                    printf("Opção não existe!!!!!\n");
            }
            if (whilesair == true){
                break;
            }
        }
    } else{
        while(1){
            printf("Você adicionará a receita %s à um cardápio já existente?\n(1)Sim ou (0)Não\n", receitas[i].nome);
            scanf("%d", &menu);
            switch(menu){
                case 0:
                    printf("Insira o novo cardápio da receita %s: \n", receitas[i].nome);
                    t = lestring(s, 50);
                    strcpy(receitas[i].cardapio,s);
                    //cria novo cardápio em cardapio
                    for (j = 0; j < 4; j++){
                        if (*cardapio[j].nome == '\0'){
                            break;
                        }
                    }
                    strcpy(cardapio[j].nome,s);
                    whilesair = true;
                    break;
                case 1:
                    while(1){
                        //adiciona um cardápio já existente na receita
                        printf("Qual?\n");
                        for (j = 0; j < 9; j++){
                            if (*cardapio[j].nome != '\0'){
                                printf("%d - %s\n", j, cardapio[j].nome);
                            }
                        }
                        scanf("%d", &menu2);
                        if(*cardapio[menu2].nome == '\0'){
                            printf("Cardápio nº%d não existe!!!!!\n", menu2);
                        } else{
                            printf("%s\n", cardapio[menu2].nome);
                            strcpy(receitas[i].cardapio,cardapio[menu2].nome);
                            whilesair = true;
                            break;
                        }
                    }
                    break;
                default:
                    printf("Opção não existe!!!!!\n");
            }
            if (whilesair == true){
                break;
            }
        }
    }
    return;
}

void MenuPricipal(){
    int menu;
    system("@cls||clear");
    printf("############################################\n");
    printf("#                  Menu                    #\n");
    printf("#                                          #\n");
    printf("#             1 - Receitas                 #\n");
    printf("#             2 - Tipos de Receitas        #\n");
    printf("#             3 - Cardápio                 #\n");
    printf("#             4 - Sair                     #\n");
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
        case 4:
            exit(0);
        default:
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
            printf("Menu não existe!!!!!\n");
            redirecionamento();
            Receitas();
    }
    return;
}

void ListarReceitas(){
    int i, menu, cont = 0;
    for (i = 0; i < 30; i++){
        if (*receitas[i].nome != '\0'){

            //printf("%d - %s\n\n",i, receitas[i].nome);
            cont++;
        }
    }
    ordenaNomes(cont);
    for (i = 0; i < 30; i++){
        if (*receitas[i].nome != '\0'){

            printf("%d - %s\n\n",i, receitas[i].nome);
            //cont++;
        }
    }

    scanf("%d",&menu);
    if (*receitas[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        ListarReceitas();
    } else{
        system("@cls||clear");
        printf("Receita: %s, selecionada!\n\n", receitas[menu].nome);
        printf("%d - %s \n\n| Tipo: %s \n| Ingredientes: %s \n| Modo de Fazer: %s \n| Cardápio: %s \n\n", menu, receitas[menu].nome, receitas[menu].tipo, receitas[menu].ingredientes, receitas[menu].mododefazer, receitas[menu].cardapio);
        while(1){
            system("pause");
            Receitas();
        }
    }
    return;
}
void EditarReceitas(){
    int i, menu;
    printf("Selecione umas das Receitas:\n\n");
    for (i = 0; i < 30; i++){
        if (*receitas[i].nome != '\0'){

            printf("%d - %s \n| Tipo: %s \n| Ingredientes: %s \n| Modo de Fazer: %s \n| Cardápio: %s\n\n", i, receitas[i].nome, receitas[i].tipo, receitas[i].ingredientes, receitas[i].mododefazer, receitas[i].cardapio);
        }
    }
    scanf("%d",&menu);
    if (*receitas[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        Receitas();
    } else{
        int menu2;
        system("@cls||clear");
        printf("Receita: %s, selecionada!\n\n", receitas[menu].nome);
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
                Comparador(menu, 1);
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
                Comparador(menu, 0);
                Receitas();
                break;
            case 6:
                system("@cls||clear");
                MenuPricipal();
                break;
            default:
                printf("Opção não existe!!!!!\n");
                redirecionamento();
                MenuPricipal();
        }
    }
    return;
}
void AdicionarReceitas(){
    int i = 0;
    for(i = 0; i < 30 ; i++){
        if (*receitas[i].nome == '\0'){
            break;
        }
    }
    printf("Insira o nome da nova receita: \n");
    t = lestring(s, 50);
    strcpy(receitas[i].nome,s);

    //Perguntar por um tipo de receita já existente ou criar um novo
    Comparador(i, 1);

    printf("Insira os ingredientes da receita %s: \n", receitas[i].nome);
    t = lestring(s, 150);
    strcpy(receitas[i].ingredientes,s);

    printf("Insira o modo de fazer da receita %s: \n", receitas[i].nome);
    t = lestring(s, 50);
    strcpy(receitas[i].mododefazer,s);

    //Pergunta por um cardápio já existente ou criar um novo
    Comparador(i, 0);

    printf("Receita %s adicionada!\n", receitas[i].nome);
    redirecionamento();
    Receitas();
    return;
}
void ExcluirReceitas(){
    int i = 0, menu;
    for (i = 0; i < 30; i++){
        if (*receitas[i].nome != '\0'){

            printf("%d - %s \n| Tipo: %s \n| Ingredientes: %s \n| Modo de Fazer: %s \n| Cardápio: %s\n\n", i, receitas[i].nome, receitas[i].tipo, receitas[i].ingredientes, receitas[i].mododefazer, receitas[i].cardapio);
        }
    }
    scanf("%d",&menu);
    if (*receitas[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        Receitas();
    } else{
        printf("Receita: %s excluida!\n", receitas[menu].nome);
        for(i = menu; i < 30; i++){
            if (*receitas[i].nome != '\0'){

                strcpy(receitas[i].nome,receitas[i+1].nome);
                strcpy(receitas[i].tipo,receitas[i+1].tipo);
                strcpy(receitas[i].ingredientes,receitas[i+1].ingredientes);
                strcpy(receitas[i].mododefazer,receitas[i+1].mododefazer);
                strcpy(receitas[i].cardapio,receitas[i+1].cardapio);
            }
        }
    }
    redirecionamento();
    Receitas();
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
    printf("#             5 - Voltar                   #\n");
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
        case 5:
            system("@cls||clear");
            MenuPricipal();
            break;
        default:
            system("@cls||clear");
            printf("Menu não existe!!!!!\n");
            redirecionamento();
            MenuPricipal();
    }
    return;
}
void ListarCardapios(){
    int i, menu, j = -1, cont;
    for (i = 0; i < 9; i++){
        if (*cardapio[i].nome != '\0'){
            cont++;
        }
    }
    ordenaCardapios(cont);
    for (i = 0; i < 9; i++){
        if (*cardapio[i].nome != '\0'){

            printf("%d - %s\n\n",i,cardapio[i].nome);
        }
    }

    scanf("%d",&menu);
    if (*cardapio[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        ListarCardapios();
    } else{
        system("@cls||clear");
        printf("Cardápio: %s, selecionado!\n\n", cardapio[menu].nome);
        for(i = 0; i < 30; i++){
            if (*receitas[i].cardapio != '\0'){
                if(strcmp(receitas[i].cardapio, cardapio[menu].nome) == 0){

                    j++;
                    printf("%d - %s \n| Tipo: %s \n| Ingredientes: %s \n| Modo de Fazer: %s \n| Cardápio: %s\n\n", j, receitas[i].nome, receitas[i].tipo, receitas[i].ingredientes, receitas[i].mododefazer, receitas[i].cardapio);
                }
            }
        }
    }
    while(1){
        system("pause");
        Cardapios();
    }
    return;
}
void EditarCardapios(){
    int i, menu;
    printf("Selecione um dos Cardápios:\n");
    for (i = 0; i < 9; i++){
        if (*cardapio[i].nome != '\0'){

            printf("%d - %s\n", i, cardapio[i].nome);
        }
    }
    scanf("%d",&menu);
    if (*cardapio[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        Cardapios();
    } else{
        system("@cls||clear");
        printf("Cardápio: %s, selecionado!\n", cardapio[menu].nome);
        printf("Insira o novo nome: \n");
        t = lestring(s, 20);
        for(i = 0; i < 30; i++){
            if (*receitas[i].cardapio != '\0'){
                if(strcmp(receitas[i].cardapio, cardapio[menu].nome) == 0){

                    strcpy(receitas[i].cardapio, s);
                }
            }
        }
        strcpy(cardapio[menu].nome, s);
        Cardapios();
        }
    return;
}
void AdicionarCardapios(){
    int i = 0;
    for(i = 0; i < 30 ; i++){
        if (*cardapio[i].nome == '\0'){
            break;
        }
    }
    printf("Insira o nome do novo cardápio: \n");
    t = lestring(s, 50);
    strcpy(cardapio[i].nome, s);
    printf("Cardápio %s adicionado!\n", cardapio[i].nome);
    redirecionamento();
    Cardapios();
    return;
}
void ExcluirCardapios(){
    int i = 0, menu;
    for (i = 0; i < 9; i++){
        if (*cardapio[i].nome != '\0'){

            printf("%d - %s\n",i,cardapio[i].nome);
        }
    }
    scanf("%d",&menu);
    printf("Cardápio: %s excluido!\n", cardapio[menu].nome);
    for(i = menu; i < 9; i++){
        if (*receitas[i].nome != '\0'){

            strcpy(cardapio[i].nome,cardapio[i+1].nome);
            }
    }
    redirecionamento();
    Cardapios();
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
    printf("#             5 - Voltar                   #\n");
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
        case 5:
            system("@cls||clear");
            MenuPricipal();
            break;
        default:
            printf("Menu não existe!!!!!\n");
            redirecionamento();
            TiposDeReceitas();
    }
    return;
}
void ListarTiposDeReceitas(){
    int i, menu, j = -1;
    for (i = 0; i < 9; i++){
        if (*tiposdereceitas[i].nome != '\0'){

            printf("%d - %s \n\n",i,tiposdereceitas[i].nome);
        }
    }
    scanf("%d",&menu);
    if (*tiposdereceitas[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        ListarTiposDeReceitas();
    } else{
        system("@cls||clear");
        printf("Tipo: %s, selecionado!\n\n", tiposdereceitas[menu].nome);
        for(i = 0; i < 30; i++){
            if (*receitas[i].tipo != '\0'){
                if(strcmp(receitas[i].tipo, tiposdereceitas[menu].nome) == 0){

                    j++;
                    printf("%d - %s \n| Tipo: %s \n| Ingredientes: %s \n| Modo de Fazer: %s \n| Cardápio: %s\n\n", j, receitas[i].nome, receitas[i].tipo, receitas[i].ingredientes, receitas[i].mododefazer, receitas[i].cardapio);
                }
            }
        }
    }
    while(1){
        system("pause");
        TiposDeReceitas();
    }
    return;
}
void EditarTiposDeReceitas(){
    int i, menu;
    printf("Selecione um dos tipos de receita:\n");
    for (i = 0; i < 9; i++){
        if (*tiposdereceitas[i].nome != '\0'){

            printf("%d - %s \n",i,tiposdereceitas[i].nome);
        }
    }
    scanf("%d",&menu);
    if (*tiposdereceitas[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        TiposDeReceitas();
    } else{
        system("@cls||clear");
        printf("Tipo de Receita: %s, selecionado!\n", tiposdereceitas[menu].nome);
        printf("Insira o novo nome: \n");
        t = lestring(s, 20);
        for(i = 0; i < 30; i++){
            if (*receitas[i].tipo != '\0'){
                if(strcmp(receitas[i].tipo, tiposdereceitas[menu].nome) == 0){

                    strcpy(receitas[i].tipo, s);
                }
            }
        }
        strcpy(tiposdereceitas[menu].nome, s);
        TiposDeReceitas();
    }
    return;
}
void AdicionarTiposDeReceitas(){
    int i = 0;
    for(i = 0; i < 9 ; i++){
        if (*tiposdereceitas[i].nome == '\0'){
            break;
        }
    }
    printf("Insira o nome do novo tipo de receita: \n");
    t = lestring(s, 50);
    strcpy(tiposdereceitas[i].nome, s);
    printf("Tipo de receita: %s adicionado!\n", tiposdereceitas[i].nome);
    redirecionamento();
    TiposDeReceitas();
    return;
}
void ExcluirTiposDeReceitas(){
    int i, menu, menu2, p;
    printf("Selecione um dos tipos de receita:\n");
    for (i = 0; i < 9; i++){
        if (*tiposdereceitas[i].nome != '\0'){

            printf("%d - %s \n",i,tiposdereceitas[i].nome);
        }
    }
    scanf("%d",&menu);
    if (*tiposdereceitas[menu].nome == '\0'){
        printf("Opção não existe!!!!!\n");
        redirecionamento();
        TiposDeReceitas();
    } else{
        system("@cls||clear");
        printf("Tipo de Receita: %s, selecionado!\n", tiposdereceitas[menu].nome);
        printf("#################################################\n");
        printf("#            (!) Você gostaria de:              #\n");
        printf("#                                               #\n");
        printf("#  (1) Apagar todas    | (2) Apagar             #\n");
        printf("#   as receitas do     |  o tipo selecionado    #\n");
        printf("#   tipo selecionado?  |  e manter as receitas  #\n");
        printf("#                      |  deste, sem tipo       #\n");
        printf("#                      |                        #\n");
        printf("#                                               #\n");
        printf("#################################################\n");
        scanf("%d", &menu2);
        switch(menu2){
            case 1:
                for(i = 0; i < 30; i++){
                    if(*receitas[i].tipo != '\0'){
                        if(strcmp(receitas[i].tipo, tiposdereceitas[menu].nome) == 0){
                            for(p = i; p < 30; p++) {
                                strcpy(receitas[i].nome, receitas[i + 1].nome);
                                strcpy(receitas[i].tipo, receitas[i + 1].tipo);
                                strcpy(receitas[i].ingredientes, receitas[i + 1].ingredientes);
                                strcpy(receitas[i].mododefazer, receitas[i + 1].mododefazer);
                                strcpy(receitas[i].cardapio, receitas[i + 1].cardapio);
                            }
                        }
                    }
                }
                for(i = menu; i < 9; i++){
                    if(*receitas[i].tipo != '\0'){

                        strcpy(tiposdereceitas[i].nome,tiposdereceitas[i+1].nome);
                    }
                }
                break;
            case 2:
                //Cria um tipo "Não classificado" caso este não exista ainda
                for(i = 0; i < 9; i++){
                    if(strcmp(tiposdereceitas[i].nome, "Não classificado") == 0){
                        break;
                    } else if(*tiposdereceitas[i].nome == '\0'){
                        strcpy(tiposdereceitas[i].nome,"Não classificado");
                        break;
                    }
                }
                //Torna as receitas do tipo escolhido como de "Não classificado"
                for(i = 0; i < 30 && *receitas[i].tipo != '\0'; i++){
                    //if(*receitas[i].tipo != '\0'){
                        if(strcmp(receitas[i].tipo, tiposdereceitas[menu].nome) == 0){

                            strcpy(receitas[i].tipo, "Não classificado");
                        }
                    //}
                }
                //Apaga o tipo de receita
                for(i = menu; i < 9; i++){
                    if(*tiposdereceitas[i].nome != '\0'){

                        strcpy(tiposdereceitas[i].nome,tiposdereceitas[i+1].nome);
                    }
                }
                break;
            default:
                printf("Opção não existe!!!!!\n");
            }
    printf("Tipo de Receita excluído!\n");
    redirecionamento();
    TiposDeReceitas();
    return;
    }
}
void redirecionamento(){
    int i;
    printf("Você será redirecionado em ");
    for(i = 3; i > 0;i--){
        printf("%d", i);
        //printf("Você será redirecionado em %d",i);
        usleep(1000*1000);
        //Sleep(1000);
        printf("\n");
    }
    return;
}

void setDefaultValues(){
    int i = 0;
    //Tipos de Receitas
    strcpy(tiposdereceitas[0].nome,"Bebida");
    strcpy(tiposdereceitas[1].nome,"Prato Salgado");
    strcpy(tiposdereceitas[2].nome,"Sobremesa");
    for(i = 0; i < 9; i++){
        strcpy(tiposdereceitas[i].id,"tipo");
    }

    //Receitas
    strcpy(receitas[0].nome,"Suco de Limão"); strcpy(receitas[0].tipo,"Bebida"); strcpy(receitas[0].ingredientes,"Água, Limão");strcpy(receitas[0].mododefazer,"Pegue uma jarra, coloque água, esprema o limão, misture.");strcpy(receitas[0].cardapio,"Almoço de Domingo");
    strcpy(receitas[1].nome,"Suco de Laranja"); strcpy(receitas[1].tipo,"Bebida"); strcpy(receitas[1].ingredientes,"Água, Laranja"); strcpy(receitas[1].mododefazer,"Pegue uma jarra, coloque água, esprema a laranja, misture."); strcpy(receitas[1].cardapio,"Almoço de Domingo");
    strcpy(receitas[2].nome,"Carne Assada"); strcpy(receitas[2].tipo,"Prato Salgado"); strcpy(receitas[2].ingredientes,"Carne de Boi, Temperos"); strcpy(receitas[2].mododefazer,"Tempere a Carne, coloque na churrasqueira."); strcpy(receitas[2].cardapio,"Jantar de Sexta");
    strcpy(receitas[3].nome,"Cerveja"); strcpy(receitas[3].tipo,"Bebida"); strcpy(receitas[3].ingredientes,"Cerveja"); strcpy(receitas[3].mododefazer,"Abra a latinha, tome."); strcpy(receitas[3].cardapio,"Jantar de Sexta");
    strcpy(receitas[4].nome,"Salgado"); strcpy(receitas[4].tipo,"Prato Salgado"); strcpy(receitas[4].ingredientes,"Massa, Recheio"); strcpy(receitas[4].mododefazer,"Faça a massa, recheie, asse."); strcpy(receitas[4].cardapio,"Jantar de Sexta");
    strcpy(receitas[5].nome,"Prato Tradicional"); strcpy(receitas[5].tipo,"Prato Salgado"); strcpy(receitas[5].ingredientes,"Arroz, Feijão, Carne, Macarrão, Salada."); strcpy(receitas[5].mododefazer,"Prepare tudo, coloque no prato."); strcpy(receitas[5].cardapio,"Almoço de Domingo");
    strcpy(receitas[6].nome,"Leite com Toddy"); strcpy(receitas[6].tipo,"Bebida"); strcpy(receitas[6].ingredientes,"Leite, Toddy"); strcpy(receitas[6].mododefazer,"Coloque o leite no copo, adicione duas colheres de Toddy, misture."); strcpy(receitas[6].cardapio,"Café da manhã de Sábado");
    strcpy(receitas[7].nome,"Bolo de Chocolate");strcpy(receitas[7].tipo,"Sobremesa");strcpy(receitas[7].ingredientes,"4 ovos, 4 colheres de Toddy, 2 colheres de manteiga, 2 xícaras de açucar, 3 xícaras de varinha de trigo, 1 xícara de leite, 1 colher de fermento.");strcpy(receitas[7].mododefazer,"Misture tudo, asse.");strcpy(receitas[7].cardapio,"Café da manhã de Sábado");
    strcpy(receitas[8].nome,"Bolo de Cenoura"); strcpy(receitas[8].tipo,"Sobremesa"); strcpy(receitas[8].ingredientes,"1/2 xícara (chá) de óleo, 3 cenouras médias raladas, 4 ovos, 2 xícaras (chá) de açúcar, 2 e 1/2 xícaras (chá) de farinha de trigo, 1 colher (sopa) de fermento em pó."); strcpy(receitas[8].mododefazer,"Misture tudo, asse."); strcpy(receitas[8].cardapio,"Café da manhã de Sábado");
    strcpy(receitas[9].nome,"Mousse de Maracujá"); strcpy(receitas[9].tipo,"Sobremesa"); strcpy(receitas[9].ingredientes,"2 caixas de gelatina de maracujá, 2 xícaras de água quente, 1/2 xícara de suco de maracujá, 2 xícaras de leite de vaca, 1 lata de leite condensado, 1 lata de creme de leite sem soro"); strcpy(receitas[9].mododefazer,"Misture tudo e coloque na geladeira."); strcpy(receitas[9].cardapio,"Café da manhã de Sábado");

    //Cárdapios
    strcpy(cardapio[0].nome,"Almoço de Domingo");
    strcpy(cardapio[1].nome,"Jantar de Sexta");
    strcpy(cardapio[2].nome,"Café da manhã de Sábado");
    for(i = 0; i < 9; i++){
        strcpy(cardapio[i].id,"cardápio");
    }

    ordenaNomes(10);
    return;
}

int main(){
    setlocale(LC_ALL,"");
    setDefaultValues();

    MenuPricipal();
    return 0;
}


/*void Comparador2(struct grupo, int i)
{
    int j = 0, menu, menu2;
    bool whilesair = false;

    while(1){
        printf("Você adicionará a receita %s à um %s já existente?\n(1)Sim ou (0)Não\n", receitas[i].nome, grupo.id);
        scanf("%d", &menu);
        switch(menu){
            case 1:
                while(1){
                    //adiciona um tipo/cardapio de receita já existente na receita
                    printf("Qual?\n");
                    for (j = 0; j < 9; j++){
                        if (*grupo[j].nome != '\0'){
                            printf("%d - %s\n", j, grupo[j].nome);
                        }
                    }
                    scanf("%d", &menu2);
                    if(*grupo[menu2].nome == '\0'){
                        printf("O %s nº%d não existe!!!!!\n", grupo.id, menu2);
                    } else{
                        printf("%s\n", grupo[menu2].nome);
                        strcpy(receitas[i].tipo,grupo[menu2].nome);
                        whilesair = true;
                        break;
                    }
                }
                break;
            case 0:
                printf("Insira o novo %s da receita %s: \n", grupo.id, receitas[i].nome);
                t = lestring(s, 50);
                strcpy(receitas[i].tipo,s);
                //cria novo tipo/cardapio de receita em tiposdereceitas
                for (j = 0; j < 9; j++){
                    if (*grupo[j].nome == '\0'){
                        break;
                    }
                }
                strcpy(grupo[j].nome,s);
                whilesair = true;
                break;
            default:
                printf("Opção não existe!!!!!\n");
        }
        if (whilesair == true){
            break;
        }
    }
}*/




void Ordena() {
   char t[50];
   int i, j;
   //clrscr();

   /*printf("\nEnter any five strings : ");
   for (i = 0; i < 5; i++)
      scanf("%s", s[i]);*/

   for (i = 1; i < 30; i++) {
      for (j = 1; j < 30; j++) {
         if (strcmp(receitas[j - 1].nome, receitas[j].nome) > 0) {
            strcpy(t, receitas[j - 1].nome);
            strcpy(receitas[j - 1].nome, receitas[j].nome);
            strcpy(receitas[j].nome, t);
         }
      }
   }

   /*printf("\nStrings in order are : ");
   for (i = 0; i < 5; i++)
      printf("\n%s", s[i]);*/

   //getch();
}

