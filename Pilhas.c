#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTAM 50



typedef struct {
    float Item[MAXTAM];
    int Topo ; /*topo é o indíce dos elementos dentro da pilha */

} TPilha ; /*Tpilha é o nome da estrutura*/

int TPilha_Inicia ( TPilha *p) {
    p -> Topo = -1; /*inicia a pilha*/
    return 1;
}

int TPilha_Vazia (TPilha *p) {
    if (p -> Topo == -1) {
        return 1;
    }else {
        return 0;
    }
}

int TPilha_Cheia (TPilha * p) {
    if (p->Topo == MAXTAM -1){
        return 1;
    }else{
        return 0;
    }
}


void TPilha_Insere (TPilha *p, float x ) { /* x é o valor FLOAT que queremos inserir no topo da pilha */
    if (TPilha_Cheia(p) == 1) {
        printf("ERRO: Pilha Cheia");
    }else{
        p -> Topo++;
        p -> Item[p->Topo] = x;
    }
}

float Tpilha_Retira (TPilha *p) {
    float aux;
    if (TPilha_Vazia(p) == 1) {
        printf("Erro: Pilha Vazia!");
        return 0;
    }else {
        aux = p->Item[p->Topo];
        p -> Topo-- ; /*retorna o topo ao indice anterior*/
        return aux;
    }
}


int main() {

    char EntradaDeDados[MAXTAM];
   scanf("%s",EntradaDeDados);

   TPilha MinhaPilha;// = (TPilha*)malloc(sizeof(TPilha));
    //TPilha *p;
    TPilha_Inicia(&MinhaPilha);
   

    int k= 0;
    float aux1;
    /*float aux2;*/
    float operando1 =0;
    float operando2 =0;
    float ResultadoProvisorio =0;
    float ResultadoFinal = 0;

    for (k=0; k < strlen(EntradaDeDados) ; k++){
        switch (EntradaDeDados[k]) {
            
            case '+':
            operando1 = Tpilha_Retira(&MinhaPilha);
            operando2 = Tpilha_Retira(&MinhaPilha);
            ResultadoProvisorio = operando1 + operando2;
            TPilha_Insere(&MinhaPilha,ResultadoProvisorio);  
            break;

            case '-':
            operando1 = Tpilha_Retira(&MinhaPilha);
            operando2 = Tpilha_Retira(&MinhaPilha);
            ResultadoProvisorio = operando2 - operando1;
            TPilha_Insere(&MinhaPilha,ResultadoProvisorio);
            break;

            case '*':
            operando1 = Tpilha_Retira(&MinhaPilha);
            operando2 = Tpilha_Retira(&MinhaPilha);
            ResultadoProvisorio = operando1 * operando2;
            TPilha_Insere(&MinhaPilha,ResultadoProvisorio);
            break;

            case '/':
            operando1 = Tpilha_Retira(&MinhaPilha);
            operando2 = Tpilha_Retira(&MinhaPilha);
            ResultadoProvisorio = operando2 / operando1;
            TPilha_Insere(&MinhaPilha,ResultadoProvisorio);
            break;
                    
            default:
            scanf("%f",&aux1);
            TPilha_Insere(&MinhaPilha,aux1);
            break;
        }
        
        
    }   
    ResultadoFinal = Tpilha_Retira(&MinhaPilha);
    printf("%f\n",ResultadoFinal);

return 0;
}
