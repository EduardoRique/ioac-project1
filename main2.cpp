#include "prints.h"

int main(){
    int aux=1;
    Instrucao instrucoes[3] = {
        {"add", "$t0", "$zero", "$v0"},
        {"add", "$t1", "$t0", "$t2"},
        {"sub", "$t3", "$t1", "$t4"}
    };
    int ciclos=5;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(instrucoes[i].alvo == instrucoes[j].opr1 || instrucoes[i].alvo == instrucoes[j].opr2){
                ciclos += 4;
            }   
        } 
    }
    
    cout << "Quantidade total de ciclos: " << ciclos << endl;
    int q=0;
    for(int i=0; i<ciclos; i++){
        
                cout << "-------------------" << endl;
                cout << "Ciclo " << i+1 << endl;
                
                printif(instrucoes, aux, i+1, q);
                printid(instrucoes, aux, i+1, q);
                printex(instrucoes, aux, i+1, q);
                printmem(instrucoes,aux, i+1, q);
                printwb(instrucoes, aux, i+1, q);
                
    }
    return 0;
}