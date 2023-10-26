#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct cadastro
{
    char renda[200];
    char nome[200];
    char ano[200];
    int vazio,cod;


}log[200];
//AQUI DECLARO AS FUN��ES A SEREM USADAS
int verifica_pos(void);
int verifica_cod( int cod );
int opt;
void cadastroP(int cod,int pos);
void list();
void consultaCod (void);
void excluirCliente (void);
int main(void){ //INICIO DO MAINa

    int i,Opcao,OpcaoCliente,posicao,retorno;
    int codaux;
    do
    {
        printf("1 - Cadastro de cliente\n");
        printf("2 - Cliente\n");
        printf("3 - Alterar Cliente\n");
        printf("4 - Excluir Cliente\n");
        printf("5 - Sair\n");
        printf(" Selecione uma opcao por favor: ");
        scanf("%d", &Opcao);
        getchar();
        if (Opcao == 1)
        {
            printf("Voce selecionou a opcao 1 - Cadastrar um novo Cliente\n");
            posicao=verifica_pos();

                if ( posicao != -1 )
                {

                    printf("\nEntre com um codigo de 1 a 200 para seu cadastro: \n");
                    scanf("%d",&codaux);fflush(stdin);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        cadastroP( codaux, posicao );
                    else{
                        printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
                        getchar();
                        system("cls");
                        main();
                    }

                }
                else
                    printf("\nNao e possivel realizar mais cadastros!\n");

                break;

        }
        else if (Opcao == 2)
        {
            system("cls");
            do{
            printf("Voce selecionou a opcao 2 - Cliente\n\n");
            printf("1 - Pesquisar Cliente por codigo\n");
            printf("2 - Listar todos os Cliente\n");
            printf("3 - Voltar ao menu principal\n");
            printf("Selecione uma opcao por favor: ");
            scanf("%d", &OpcaoCliente);
            getchar();
                 if(OpcaoCliente == 1){
                    consultaCod();
                }
                else if(OpcaoCliente == 2){
                    list();
                }
                else if(OpcaoCliente == 3){
                    printf("Voce selecionou voltar ao menu principal, pressione ENTER para continuar");
                    getchar();
                    system("cls");
                }
                else
                    printf("Opcao Invalida\n\n");
    }while(OpcaoCliente =!3 || OpcaoCliente > 3 || OpcaoCliente < 0 || OpcaoCliente == 0);
        }
        else if (Opcao == 3)
        {
            printf("Voce selecionou a opcao 3 - Alterar Clienen");
        }
        else if (Opcao == 4)
        {
            printf("Voce selecionou a opcao 4 - Excluir Cliente\n");
            excluirCliente();
        }
        else if (Opcao == 5)
        {
            printf("Voce selecionou a opcao 6 - Sair\n");
        }
        else{
            printf("Opcao invalida, favor pressione enter para voltar ao menu principal");
            getchar();
            system("cls");
        }
        }    while (Opcao != 5 || Opcao < 5);

} // FIM DO MAIN
void list(){ // Lista os usuarios cadastrados.
    int i,j;
    for(i=0;i<200;i++){
        if(log[i].cod!=NULL){
            printf("\nCodigo: %d \nNome: %s\nAno de Nascimento: %s\nRenda: %s\n\n", log[i].cod,log[i].nome,log[i].ano,log[i].renda);
    }
}
    printf("Pressione enter para volta ao menu principal");
    getchar();
    system("cls");

} //FIM DO LIST
void cadastroP(int cod, int pos){ //Cadastro das pessoas
    int i;
    do{
    pos = verifica_pos();
    log[pos].cod = cod;
        printf("\nDigite Nome Completo: ");
        gets(log[pos].nome);
        printf("\nDigite seu Ano de nascimento: ");
        gets(log[pos].ano);
        printf("\nDigite seu Renda Mensal: ");
        gets(log[pos].renda);
        log[pos].vazio = 1;

        opt ==1;
        getchar();
    }while(opt==1);
    system("cls");
    main();

} // FIM DO CADASTRO DE PESSOAS
int verifica_pos( void ) //VERIFICADOR DA POSI��O
{
    int cont = 0;

    while ( cont <= 200 )
    {

        if ( log[cont].vazio == 0 )
            return(cont);

        cont++;

    }

    return(-1);

} // FIM DO VERIFICADOR
int verifica_cod( int cod ) // VERIFICADOR DE C�DIGO
{
    int cont = 0;

    while ( cont <= 200 )
    {
        if ( log[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);

} // FIM DO VERIFICADOR

void consultaCod (void) // CONSULTAR 1 CADASTRADO QUALQUER VIA C�DIGO DADO POR USU�RIO.
{
    int cont = 0, cod;

    printf("\nEntre com o codigo\n");
    scanf("%d",&cod);
    fflush(stdin);
    system("cls");

    while ( cont <= 200 )
    {

        if (log[cont].cod==cod)
        {
            if (log[cont].vazio==1)
            {

                printf("\nCodigo: %d \nNome: %s\nAno de Nascimento: %s\nRenda Mensal: %s\n\n", log[cont].cod,log[cont].nome,log[cont].ano,log[cont].renda);


                system ("pause");

                system("cls");

                break;

            }
        }

        cont++;

        if ( cont > 200 ){
            printf("\nCodigo nao encontrado, pressione enter para volar ao menu principal\n");
            getchar();
            system("cls");
        }

    }
} // FIM DA FUN��O CONSULTAR
void excluirCliente(void)  // EXCLUI CLIENTE
{
    int cod, cont = 0;
    char resp;
    printf("\nEntre com o codigo do registro que deseja excluir: \n");
    scanf("%d", &cod );

    while ( cont <= 200 )
    {

        if ( log[cont].cod == cod )
        {

            if (log[cont].vazio == 1 )
            {
                printf("\nCodigo: %d \nNome: %s\nAno de Nascimento: %s\nRenda Mensal: %s\n\n", log[cont].cod,log[cont].nome,log[cont].ano,log[cont].renda);
                getchar();
                printf("\nDeseja realmente exlucir? s/n: ");
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    log[cont].vazio=0;
                    log[cont].cod = NULL;
                    printf("\nExclusao feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 200 )
            printf("\nCodigo nao encontrado\n");

    }

    system("pause");
    system("cls");

}
