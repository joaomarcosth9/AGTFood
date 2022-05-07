#include <stdio.h>
#include <stdlib.h>

float conta_final = 0;

char escolha_principal[30];
char escolha_adicional[30];
char escolha_bebida[30];

void menu_principal(){
    const char espetinho_carne[] = "ESPETINHO DE CARNE";
    const char espetinho_queijo[] = "ESPETINHO DE QUEIJO COALHO";
    const char x_costela[] = "X-COSTELA";
    const float preco_espetinho_carne = 600;
    const float preco_espetinho_queijo = 650;
    const float preco_x_costela = 1300;

    printf("\nNossas opcoes principais sao:\n");
    printf("(1) %s - R$ %.2f\n", espetinho_carne, preco_espetinho_carne/100);
    printf("(2) %s - R$ %.2f\n", espetinho_queijo, preco_espetinho_queijo/100);
    printf("(3) %s - R$ %.2f\n", x_costela, preco_x_costela/100);
    printf("Escolha: ");
    int escolha;
    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            for(int i=0; i < sizeof(espetinho_carne); i++){
                escolha_principal[i] = espetinho_carne[i];
            }
            conta_final += preco_espetinho_carne;
            break;
        case 2:
            for(int i=0; i < sizeof(espetinho_queijo); i++){
                escolha_principal[i] = espetinho_queijo[i];
            }
            conta_final += preco_espetinho_queijo;
            break;
        case 3:
            for(int i=0; i < sizeof(x_costela); i++){
                escolha_principal[i] = x_costela[i];
            }
            conta_final += preco_x_costela;
            break;
        default:
            printf("Essa nao eh uma opcao, tente novamente.");
            exit(1);
    }
}

void menu_adicional(){
    const char adicional[] = "BATATA FRITA";
    const float preco_adicional = 1000;
    const char sem_adicional[] = "SEM ADICIONAL";

    printf("\nVai querer adicional de %s - R$ %.2f? - (S/N)\n", adicional, preco_adicional/100);
    printf("Escolha: ");
    char escolha;
    scanf(" %c", &escolha);

    if(escolha == 'S' || escolha == 's'){
        printf("Ok! Adicional inserido no pedido.\n");
        for(int i=0; i < sizeof(adicional); i++){
            escolha_adicional[i] = adicional[i];
        }
        conta_final += preco_adicional;
    } else if (escolha == 'N' || escolha == 'n') {
        printf("Ok! Sem adicional.\n");
        for(int i=0; i < sizeof(sem_adicional); i++){
            escolha_adicional[i] = sem_adicional[i];
        }
    } else {
        printf("Opcao invalida!\n");
        exit(1);
    }
}

void menu_bebida(){
    const char suco[] = "SUCO";
    const char agua_com_gas[] = "AGUA COM GAS";
    const float preco_suco = 500;
    const float preco_agua_com_gas = 700;
    const char sem_bebida[] = "SEM BEBIDA";        

    printf("\nDeseja pedir alguma bebida? (S/N)\n");
    printf("Escolha: ");
    char escolha;
    scanf(" %c", &escolha);

    if(escolha == 'S' || escolha == 's'){
        printf("Ok! Qual bebida vai querer?\n");
        printf("(1) %s - R$ %.2f\n", suco, preco_suco/100);
        printf("(2) %s - R$ %.2f\n", agua_com_gas, preco_agua_com_gas/100);
        printf("Escolha: ");
        int escolha;
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                for(int i=0; i < sizeof(suco); i++){
                    escolha_bebida[i] = suco[i];
                }
                conta_final += preco_suco;
                break;
            case 2:
                for(int i=0; i < sizeof(agua_com_gas); i++){
                    escolha_bebida[i] = agua_com_gas[i];
                }
                conta_final += preco_agua_com_gas;
                break;
            default:
                printf("Essa nao eh uma opcao de bebida.\n");
                for(int i=0; i < sizeof(sem_bebida); i++){
                    escolha_bebida[i] = sem_bebida[i];
                }
        }
    } else if (escolha == 'N' || escolha == 'n') {
        printf("Ok! Sem bebida.\n");
        for(int i=0; i < sizeof(sem_bebida); i++){
            escolha_bebida[i] = sem_bebida[i];
        }
    } else {
        printf("Opcao invalida!\n");
        exit(1);
    }
}

void main(){
    printf("Seja bem vindo(a) a AGTFood!\n");

    menu_principal();

    menu_adicional();

    menu_bebida();

    printf("\nConfira seu pedido: \n");
    printf("Escolha principal: %s\n", escolha_principal);
    printf("Adicional: %s\n", escolha_adicional);
    printf("Bebida: %s\n", escolha_bebida);
    printf("Preço total: R$ %.2f\n\n", conta_final/100);
    printf("Confirma? (S/N): ");
    char confirma;
    scanf(" %c", &confirma);

    if(confirma == 'S' || confirma == 's'){
        printf("\nOk! Pedido confirmado!\n");
        exit(0);
    } else {
        printf("\nOk, pedido cancelado.\n");
        exit(0);
    }
}
