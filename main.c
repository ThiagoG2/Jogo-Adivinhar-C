/****************************************************************
  SUPER JOGO DA ADIVINHAÇÃO                                     *
  Desenvolvedor: Thiago Gabriel Gomes                           *
                                                                *
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Jogador
{
    char nome[50];
    int tentativas;
};

#define TAMANHO_VETOR 1000

struct Jogador jogadores[TAMANHO_VETOR];

int quantidade_jogadores = 0;

void bubbleSort (struct Jogador *vetor, int n)
{
    int k, j,i;
    struct Jogador aux;
    for (k = 1; k < n; k++)
    {
        for (j = 0; j < n - k; j++)
        {
            if (vetor[j].tentativas > vetor[j + 1].tentativas)
            {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    for(i=0; i< quantidade_jogadores; i++)
    {
        printf("%dº Lugar - Jogador: %s , Recorde: %d\n", i+1, vetor[i].nome, vetor[i].tentativas);
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int booleanAdivinhar = 1;
    int tentativas = 0;
    int tentativaJogador = 0;
    int opcaoMenu;
    int sairMenu = 0;

    struct Jogador jogador;

    do
    {
        printf("=====   SUPER JOGO DA ADIVINHAÇÃO   =====\n\n");
        printf("1 - JOGAR\n");
        printf("2 - RANKING\n");
        printf("3 - AJUDA\n");
        printf("4 - SAIR\n");
        printf("Informe o que deseja fazer: ");
        scanf("%d", &opcaoMenu);

        switch(opcaoMenu)
        {
        case 1:
            system("cls");
            printf("\t\tVocê está preparado? O jogo já vai começar!!!\n\n");
            printf("\tAntes de começar informe o seu nome de jogador: ");
            scanf("%s", &jogador.nome);
            getchar();
            srand(time(NULL));
            int numeroBOT = rand() % 1000;
            fflush(stdin);
            system("cls");
            printf("\t\tO JOGO COMEÇOU!\n\tO BOT já escolheu o número, agora é sua vez de acertar!\n\tVocê deve escolher um número entre 0 e 1000 para acertar.\n");
            do
            {
                printf("Tentativa %d: ", tentativas+1);
                scanf("%d", &tentativaJogador);
                if(tentativas == 14)
                {
                    printf("\n\t* Você perdeu - Limite de tentativas atingido *\n\t O número escolhido pelo BOT foi: %d.\n", numeroBOT);
                    booleanAdivinhar = 0;
                    tentativas = 0;
                }
                else if(numeroBOT > tentativaJogador)
                {
                    printf("\t\tVocê errou!\nDICA: O número que o BOT escolheu é maior que %d.\n", tentativaJogador);
                    tentativas++;
                    booleanAdivinhar = 1;
                }
                else if(numeroBOT < tentativaJogador)
                {
                    printf("\t\tVocê errou!\nDICA: O número que o BOT escolheu é menor que %d.\n", tentativaJogador);
                    tentativas++;
                    booleanAdivinhar = 1;
                }
                else
                {
                    tentativas++;
                    jogador.tentativas = tentativas;
                    insereNovoJogador(jogador);
                    printf("\nParabéns, você acertou!!! O seu número de tentativas foi de %d tentativas\nVeja em \"RANKING\" a sua colocação no jogo.\n", tentativas);
                    booleanAdivinhar = 0;
                    tentativas = 0;
                }
            }
            while(booleanAdivinhar);
            voltarMenu();
            break;
        case 2:
            system("cls");
            printf("\n\t\t****** RANKING ******\n");
            if(!quantidade_jogadores)
            {
                printf("\nAinda não há jogadores cadastrados no ranking do jogo.\n");
            }
            else
            {
                printf("\n");
                bubbleSort(jogadores, quantidade_jogadores);
                printf("\n");
            }
            voltarMenu();
            break;
        case 3:
            system("cls");
            printf("\n\t\tO JOGO DA ADIVINHAÇÃO - COMO FUNCIONA:\n");
            printf("\n-------------------------------------------------------------------------------");
            printf("\n- O BOT irá pensar em um número entre 0 e 1000 e o jogador terá que adivinhar.");
            printf("\n- Sempre que o jogador fizer uma tentativa será dada uma dica se o número que o BOT pensou é maior ou menor.");
            printf("\n- Ao final o jogador conseguirá visualizar quantas tentivas foi preciso para acertar.");
            printf("\n- Em \"RANKING\" o jogador verá o recorde de todos os que já jogaram e venceram o jogo da adivinhação e a sua posição no jogo.");
            printf("\n- O jogador só terá até 15 tentativas para vencer o jogo.");
            printf("\n- O jogador que perder não irá entrar no ranking.");
            printf("\n- Os melhores colocados no ranking são aqueles que conseguiram vencer com menos tentativas.\n");
            printf("\n\t\t\tBom jogo :D\n\n");
            voltarMenu();
            break;
        case 4:
            system("cls");
            printf("\n\t\t\t=====  GAME OVER  =====\n");
            exit(0);
        default:
            system("cls");
            printf("Opção Inválida!\n");
        }
    }while(!sairMenu);

    return 0;
}
void voltarMenu()
{
    int opcao;
    printf("\nDeseja voltar para o menu?");
    printf("\n1 - Sim\n2 - Sair do Jogo\n");
    scanf("%d", &opcao);

    switch(opcao)
    {
    case 1:
        system("cls");
        break;
    case 2:
        system("cls");
        printf("\n\t\t\t=====  GAME OVER  =====\n");
        exit(0);
    default:
        system("cls");
        printf("Opção Inválida!\n");

    }
}
void insereNovoJogador(struct Jogador j)
{
    if(quantidade_jogadores == TAMANHO_VETOR)
    {
        printf("Não é possivel inserir mais jogadoress, capacidade maxima atingida");
        return;
    }

    jogadores[quantidade_jogadores] = j;

    quantidade_jogadores++;

}

