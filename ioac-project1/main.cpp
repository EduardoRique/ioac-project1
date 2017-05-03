#include <iostream>
#include <string>
#include <fstream>

#include "pipeline.h"

using namespace std;

int main(int argc, char* argv[]) {

    //Abre o arquivo e conta as linhas
    ifstream entrada(argv[1]); 
    if(!entrada){
        cout << "O arquivo de entrada nao foi encontrado!" << endl;
        return 0;
    }
    int cont = 0;
    string str = "";
    while(!entrada.eof()) {
        getline(entrada, str);
        if(str != "")
            cont++;
    }
    entrada.clear();
    entrada.seekg(entrada.beg);
    
    if(cont <= 0) {
        cout << "Arquivo vazio" << endl;
        return 0;
    }

    //Faz a leitura e armazenamento do arquivo
    string *instrucoes = new string[cont];
    
    for(int ii = 0; ii < cont; ii++){
        getline(entrada, instrucoes[ii]);
    }
        
    entrada.clear();
    entrada.seekg(entrada.beg);

    //Coloca o codigo em ordem
    Pipeline *pipeline = new Pipeline[cont];
    int contaCiclos = 0;
    int contaInst = 0;
    ordem(contaCiclos, contaInst, instrucoes, cont, pipeline);
    string Estagios[5] = {"IF", "ID", "EX", "MEM", "WB"};

    //Imprime	
    printCiclo(contaCiclos, contaInst, pipeline, Estagios);

    delete[] instrucoes;
    delete[] pipeline;

    return 0;
}
