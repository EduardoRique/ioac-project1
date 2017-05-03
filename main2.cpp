#include "prints.h"
#include <string>

using namespace std;

int main(){

    ifstream entrada("dados.txt");
	if(!entrada) {
		cerr << "O arquivo de entrada nao foi encontrado!" << endl;
		return 0;
	}
    string str1;
    string string;
    int contador = 0;

	while(getline(entrada, string)) {
		
			contador++;

	}

    Instrucao *vetor = new Instrucao[contador];
	Dependencia *info = new Dependencia[contador];

    entrada.clear();
	entrada.seekg(entrada.beg);

    int count = 0;

	while(count < contador) {

		entrada >> vetor[count].opcode;//lendo opcode

		if(vetor[count].opcode == "j") {
			getline(entrada, str1);
			cout << str1 << endl;
			vetor[count].alvo = str1;
			vetor[count].opr1 = "Void";
			vetor[count].opr2 = "Void";
		} else if(vetor[count].opcode == "lw") {
			getline(entrada, str1, ' ');
			getline(entrada, str1, ',');
			cout << str1 << endl;
			vetor[count].alvo = str1;
			getline(entrada, str1);			
			vetor[count].opr1 = str1;
			vetor[count].opr2 = "Void";
		} else if(vetor[count].opcode == "sw") {
			getline(entrada, str1, ' ');
			getline(entrada, str1, ',');
			cout << str1 << endl;
			vetor[count].alvo	= str1;
			getline(entrada, str1);
			vetor[count].opr1 = str1;
			vetor[count].opr2 = "Void";
		} else {

			cout << vetor[count].opcode << endl;
			cout << "==============================" << endl;

			for(int jj=1; jj<3; jj++) {
				getline(entrada, str1, ' ');
				getline(entrada, str1, ',');
				cout << str1 << endl;
                if(jj == 1) vetor[count].alvo = str1;
                else vetor[count].opr1 = str1;
				
					
			}

			entrada >> vetor[count].opr2;
			cout << vetor[count].opr2 << endl;
			cout << "==============================" << endl;
		}
		
		++count;
	}

    int ciclos=5;
    
    for(int i=0; i<contador; i++){
        for(int j=0; j<contador; j++){
            if(vetor[i].alvo == vetor[j].opr1 || vetor[i].alvo == vetor[j].opr2){
                ciclos += 4;
            }   
        } 
    }

	processando(vetor, contador, info);

	int *dep = new int[contador];
	for(int ii=0; ii<contador; ii++){
		if(info[ii].instrucao[0] >=0 || info[ii].instrucao[1] >=0){
			dep[ii] = 1;
		}
		else{
			dep[ii] = 0;
		}
	}

    
    cout << "Quantidade total de ciclos: " << ciclos << endl;
    int aux[5] = {0,0,0,0,0}; //Qual estagio deve ser printado
	int q[5] = {0,0,0,0,0}; //Indice da instrucao para cada estagio
	int light[5] = {0,0,0,0,0}; 
    for(int i=0; i<ciclos; i++){
        
                cout << "-------------------" << endl;
                cout << "Ciclo " << i+1 << endl;
                
                printif(vetor, aux, i+1, q, dep, light, contador);
                printid(vetor, aux, i+1, q, dep, light, contador);
                printex(vetor, aux, i+1, q, dep, light, contador);
                printmem(vetor, aux, i+1, q, dep, light, contador);
                printwb(vetor, aux, i+1, q, dep, light, contador);
				print(vetor, aux, i+1, q, dep, light, contador);
				
    }
	

    entrada.close();
	delete[] dep;
    delete[] info;
	delete[] vetor;
    return 0;
}