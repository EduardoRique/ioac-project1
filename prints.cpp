#include "prints.h"

void printif(Instrucao instrucoes[], int &aux, int ciclo, int q){
    if(aux == 1){
    cout << "IF:    " << instrucoes[q].opcode << " " << instrucoes[q].alvo << " " << instrucoes[q].opr1 << " " << instrucoes[q].opr2 << endl;
        }
    else if(aux == 0){
        cout << "IF:    " << endl;
    }
    else{}
}

void printid(Instrucao instrucoes[], int &aux, int ciclo, int q){
    
    for(int i=q; i<3; i++){
        if(instrucoes[q].alvo == instrucoes[i].opr1 || instrucoes[q].alvo == instrucoes[i].opr2){
            aux=2;
        } 
    }
    printif(instrucoes, aux, ciclo, q);
    
    aux=1;
    
    if(aux == 1 && ciclo%5 == 2){
    cout << "ID:    " << instrucoes[q].opcode << " " << instrucoes[q].alvo << " " << instrucoes[q].opr1 << " " << instrucoes[q].opr2 << endl;
    
    }
    else{
        cout << "ID:    " << endl;
        
    }
}

void printex(Instrucao instrucoes[], int &aux, int ciclo, int q){
    
    if(aux == 1 && ciclo%5 == 3){
    cout << "EX:    " << instrucoes[q].opcode << " " << instrucoes[q].alvo << " " << instrucoes[q].opr1 << " " << instrucoes[q].opr2 << endl;
    }
    else{
        cout << "EX:    " << endl;
        
        }
}

void printmem(Instrucao instrucoes[], int &aux, int ciclo, int q){
    
    
    if(aux == 1 && ciclo%5 == 4){
    cout << "MEM:    " << instrucoes[q].opcode << " " << instrucoes[q].alvo << " " << instrucoes[q].opr1 << " " << instrucoes[q].opr2 << endl;    
    }
    else{
        cout << "MEM:    " << endl;
           
    }
}

void printwb(Instrucao instrucoes[], int &aux, int ciclo, int &q){
     if(aux == 1 && ciclo%5 == 0){
        cout << "WB:    " << instrucoes[q].opcode << " " << instrucoes[q].alvo << " " << instrucoes[q].opr1 << " " << instrucoes[q].opr2 << endl;
        q++;
    }
    else{
        cout << "WB:    " << endl;
    }
}