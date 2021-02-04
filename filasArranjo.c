//FILA POR ARRANJOS

#define MAXTAM 65536 //colocar 2 elevado a 15 depois
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

 

typedef int TApontador;

typedef struct{
    int indiceLutador;
    int forcaAtualLutador; 
    int forcaInicialLutador;   
}TLutador;


typedef struct {
    TLutador Lutador[MAXTAM];
    TApontador Frente, Tras;
}TFilaLutadores;

void TFila_Inicia(TFilaLutadores *pFila) {
    pFila->Frente = 0;
    pFila->Tras = 0;
   
}

int TFila_EhVazia(TFilaLutadores *pFila) {
    if (pFila->Frente == pFila->Tras) {
        return 1;
    }else {
        return 0;
    }
}

int TFila_Tamanho(TFilaLutadores *pFila) {
    return ((pFila->Tras >= pFila->Frente) ?
    (pFila->Tras - pFila->Frente) :
    (MAXTAM + pFila->Tras - pFila->Frente));
}

int TFila_Enfileira(TFilaLutadores * pFila, TLutador lutador) {
    if (pFila->Frente == (pFila->Tras +1) % MAXTAM){
        return 0; 
    }
    pFila->Lutador[pFila->Tras] = lutador;
    pFila->Tras = ((pFila->Tras + 1)) % MAXTAM ;
    
     return 1;
}



int TFila_Desenfileira(TFilaLutadores * pFila, TLutador *lutador) {
    if (TFila_EhVazia(pFila)){
        
    return 0;
    }
  
    *lutador = pFila->Lutador[pFila->Frente]; 
    
    pFila->Frente = (pFila->Frente + 1) % MAXTAM;
    return 1;
}
    
int main () {
    int Ncompetidores;
    int ExpoenteN ;
    int Krecuperacao;
    int k =0;
    //int i = 0;
    int forcaInicialPi;
    

    scanf("%d %d",&ExpoenteN,&Krecuperacao);
    Ncompetidores = pow(2,ExpoenteN);
    //printf("Quantidade de competidores : %d\n", Ncompetidores);

    TFilaLutadores MinhaFilaDeLutadores;
    TLutador lutador;
    TFila_Inicia(&MinhaFilaDeLutadores);
    
        
    int ForcaAtualLutadorX1 , ForcaAtualLutadorX2, ForcaInicialX1, ForcaInicialX2, indiceX1, indiceX2;
    
    
    for(k=1; k <= Ncompetidores; k++) {
       
       /*
        if (k == 16000) {
            forcaInicialPi = 999;
        }else{
        forcaInicialPi = 20 ;
        }*/
        
        scanf("%d",&forcaInicialPi);
        lutador.forcaInicialLutador = forcaInicialPi;
        lutador.indiceLutador = k;
        lutador.forcaAtualLutador = lutador.forcaInicialLutador;

        TFila_Enfileira(&MinhaFilaDeLutadores,lutador);
        //printf("Tamanho da Fila: %d\n",TFila_Tamanho(&MinhaFilaDeLutadores));
    } 
    
    //printf("EMPILHAMENTO CONCLUIDO!\n\n");

    
    //int contador = 1;

    while (TFila_Tamanho(&MinhaFilaDeLutadores) > 1 ){   
    //while (TFila_EhVazia(&MinhaFilaDeLutadores) == 0){    
        //printf("Tamanho da Fila: %d\n",TFila_Tamanho(&MinhaFilaDeLutadores));
       TFila_Desenfileira(&MinhaFilaDeLutadores,&lutador);
       ForcaInicialX1 = lutador.forcaInicialLutador;
       indiceX1 = lutador.indiceLutador;
       ForcaAtualLutadorX1 = lutador.forcaAtualLutador;
       
       TFila_Desenfileira(&MinhaFilaDeLutadores,&lutador);
       ForcaInicialX2 = lutador.forcaInicialLutador;
       indiceX2 = lutador.indiceLutador;
       ForcaAtualLutadorX2 = lutador.forcaAtualLutador;
       //printf("Força Desenfileirada x1: %d //// Indice desenfileirado x1: %d\n",ForcaLutadorX1,indiceX1);
       //printf("Força Desenfileirada x2: %d //// Indice desenfileirado x2: %d\n",ForcaLutadorX2,indiceX2);
       
       

        if (ForcaAtualLutadorX1 > ForcaAtualLutadorX2) { //lutador1 vence
            if ((ForcaAtualLutadorX1 - ForcaAtualLutadorX2 + Krecuperacao) <= ForcaInicialX1){
                ForcaAtualLutadorX1 = (ForcaAtualLutadorX1 - ForcaAtualLutadorX2) + Krecuperacao;
                
                lutador.indiceLutador = indiceX1;
                lutador.forcaAtualLutador = ForcaAtualLutadorX1;
                lutador.forcaInicialLutador = ForcaInicialX1;
                //lutador.forcaLutador = ForcaLutadorX1; //atualiza a forca do lutador vencedor
                
            }else{
                lutador.indiceLutador = indiceX1;
                lutador.forcaAtualLutador = ForcaInicialX1;
                lutador.forcaInicialLutador = ForcaInicialX1;
            }
            //printf("X1 venceu- indice enfileirado: %d //// Forca enfileirada: %d\n",indiceX1,ForcaLutadorX1);
            TFila_Enfileira(&MinhaFilaDeLutadores,lutador);
            
            
        }else if(ForcaAtualLutadorX1 < ForcaAtualLutadorX2) { //lutador2 vence
            if ((ForcaAtualLutadorX2-ForcaAtualLutadorX1+Krecuperacao) <= ForcaInicialX2){
                ForcaAtualLutadorX2 = ForcaAtualLutadorX2 - ForcaAtualLutadorX1 + Krecuperacao;
                
                lutador.indiceLutador = indiceX2;
                lutador.forcaAtualLutador = ForcaAtualLutadorX2;
                lutador.forcaInicialLutador = ForcaInicialX2;
            }else{
                lutador.indiceLutador = indiceX2;
                lutador.forcaAtualLutador = ForcaInicialX2;
                lutador.forcaInicialLutador = ForcaInicialX2;
            }
            //printf("X2 venceu- indice enfileirado: %d //// Forca enfileirada: %d\n",indiceX2,ForcaLutadorX2);
            TFila_Enfileira(&MinhaFilaDeLutadores,lutador);
            
        
        }else if (ForcaAtualLutadorX1 == ForcaAtualLutadorX2) { //x1 sempre tem indice menor por isso vai vencer
            
                
            
                if ((ForcaAtualLutadorX1 - ForcaAtualLutadorX2 + Krecuperacao) <= ForcaInicialX1){
                    ForcaAtualLutadorX1 = ForcaAtualLutadorX1 - ForcaAtualLutadorX2 + Krecuperacao;
                    lutador.indiceLutador = indiceX1;
                    lutador.forcaAtualLutador = ForcaAtualLutadorX1;
                    lutador.forcaInicialLutador = ForcaInicialX1;
                }else {
                    lutador.indiceLutador = indiceX1;
                    lutador.forcaAtualLutador = ForcaInicialX1;
                    lutador.forcaInicialLutador = ForcaInicialX1;
                }
                //printf("X1 venceu com menor indice- indice enfileirado: %d //// Forca enfileirada: %d\n",indiceX1,ForcaLutadorX1);
                TFila_Enfileira(&MinhaFilaDeLutadores,lutador);
                
            

        } 
             
        
    }
    
    
    int indiceVencedor;   
    //printf("Tamanho da Fila final: %d\n",TFila_Tamanho(&MinhaFilaDeLutadores)); 
    TFila_Desenfileira(&MinhaFilaDeLutadores,&lutador);
    indiceVencedor = lutador.indiceLutador;
    
    printf("%d\n",indiceVencedor);
    //printf("Tamanho da Fila final 2: %d\n",TFila_Tamanho(&MinhaFilaDeLutadores)); 
    return 0;
}
