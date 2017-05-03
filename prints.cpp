#include "prints.h"

void printif(Instrucao instrucoes[], int aux[], int ciclo, int q[], int *dep, int light[], int contador){
	
	if(dep[q[0]] == 0){
		aux[0] = 1;
	}
	else{
		aux[0] = 0;
	}
	
}

void printid(Instrucao instrucoes[], int aux[], int ciclo, int q[], int dep[], int light[], int contador){
	if(light[0] == 1){
		if(dep[q[1]] == 0){
			aux[1] = 1;
		}
		else{
			aux[1] = 0;
		}
	}
	else{
		aux[1] = 0;
	}
    
}

void printex(Instrucao instrucoes[], int aux[], int ciclo, int q[], int *dep, int light[], int contador){
	if(light[1] == 1){
		if(dep[q[2]] == 0){
			aux[2] = 1;
		}
		else{
			aux[2] = 0;
		}
	}
	else{
		aux[2] = 0;
	}
}

void printmem(Instrucao instrucoes[], int aux[], int ciclo, int q[], int *dep, int light[], int contador){
	if(light[2] == 1){
		if(dep[q[3]] == 0){
			aux[3] = 1;
		}
		else{
			aux[3] = 0;
		}
	}
	else{
		aux[3] = 0;
	}
}

void printwb(Instrucao instrucoes[], int aux[], int ciclo, int q[], int *dep, int light[], int contador){
	if(light[3] == 1){
		if(dep[q[4]] == 0){
			aux[4] = 1;
			if(q[0] < contador)aux[0] = 1;
		}
		else{
			aux[4] = 0;
		}
	}
	else{
		aux[4] = 0;
	}
}

void print(Instrucao instrucoes[], int aux[], int ciclo, int q[], int *dep, int light[], int contador){
//IFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIFIF
	if(aux[0] == 1){
    	cout << "IF:    " << instrucoes[q[0]].opcode << " " << instrucoes[q[0]].alvo << " " << instrucoes[q[0]].opr1 << " " << instrucoes[q[0]].opr2 << endl;
		q[0]++;
		light[0]=1;
		light[3]=0;
	}
	else{
        cout << "IF:    " << endl;
	}
//IDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDID
	if(aux[1] == 1){
    	cout << "ID:    " << instrucoes[q[1]].opcode << " " << instrucoes[q[1]].alvo << " " << instrucoes[q[1]].opr1 << " " << instrucoes[q[1]].opr2 << endl;
		q[1]++;
		light[1]=1;
		light[4]=0;
	}
	else{
        cout << "ID:    " << endl;
	}
//EXEXEXEXEXEXEXEXEXEXEXEXEXEXEXEXEXEXEXEXEXEXEXEXEX
	if(aux[2] == 1){
    	cout << "EX:    " << instrucoes[q[2]].opcode << " " << instrucoes[q[2]].alvo << " " << instrucoes[q[2]].opr1 << " " << instrucoes[q[2]].opr2 << endl;
		q[2]++;
		light[2]=1;
		light[0]=0;
	}
	else{
        cout << "EX:    " << endl;
	}
//MEMMEMMEMMEMMEMMEMMEMMEMMEMMEMMEMMEMMEMMEMMEMMEMMEM
	if(aux[3] == 1){
    	cout << "MEM:    " << instrucoes[q[3]].opcode << " " << instrucoes[q[3]].alvo << " " << instrucoes[q[3]].opr1 << " " << instrucoes[q[3]].opr2 << endl;
		q[3]++;
		light[3]=1;
		light[1]=0;
	}
	else{
        cout << "MEM:    " << endl;
	}
//WBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWB
	if(aux[4] == 1){
    	cout << "WB:    " << instrucoes[q[4]].opcode << " " << instrucoes[q[4]].alvo << " " << instrucoes[q[4]].opr1 << " " << instrucoes[q[4]].opr2 << endl;
		q[4]++;
		light[4]=1;
		light[2]=0;
		if(q[1]<contador)dep[q[1]]=0;
		if(q[2]<contador)dep[q[2]]=0;
		if(q[3]<contador)dep[q[3]]=0;
		if(q[4]<contador)dep[q[4]]=0;
	}
	else{
        cout << "WB:    " << endl;
	}

}


void processando(Instrucao *linhas, int &countInstruction, Dependencia *info) {

	int count = 0;
	int jj = 0;

	while(count < countInstruction) {

		if(linhas[count].opcode == "add" || linhas[count].opcode == "sub") {
			
			if (count > 0) {

				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}
					if(linhas[ii].alvo == linhas[count].opr1 || linhas[ii].alvo == linhas[count].opr2) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
										
					} else {
						info[count].instrucao[jj] = -1;
						++jj;
					}
				}
			} else {
				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if(linhas[count].opcode == "j") {
			if (count > 0) {
				
				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}

					std::size_t found1 = linhas[ii].alvo.find(linhas[count].alvo);
					std::size_t found2 = linhas[ii].alvo.find(linhas[count].opr1);
					if(found1!=std::string::npos) {
						
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
						
					} else if(found2!=std::string::npos) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}

					} else {
						info[count].instrucao[jj] = -1;
						++jj;					
					}
					
				}
			} else {

				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if(linhas[count].opcode == "beq") {
			//count = linhas[count].informacao[3] - 1;

			if (count > 0) {
				
				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}

					std::size_t found1 = linhas[ii].alvo.find(linhas[count].alvo);
					std::size_t found2 = linhas[ii].alvo.find(linhas[count].opr1);
					if(found1!=std::string::npos) {
						
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
						
					} else if(found2!=std::string::npos) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}

					} else {
						info[count].instrucao[jj] = -1;
						++jj;					
					}
					
				}
			} else {

				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if(linhas[count].opcode == "bne") {
			//count = linhas[count].informacao[3] - 1;

			if (count > 0) {
				
				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}

					std::size_t found1 = linhas[ii].alvo.find(linhas[count].alvo);
					std::size_t found2 = linhas[ii].alvo.find(linhas[count].opr1);
					if(found1!=std::string::npos) {
						
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
						
					} else if(found2!=std::string::npos) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}

					} else {
						info[count].instrucao[jj] = -1;
						++jj;					
					}
					
				}
			} else {

				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if(linhas[count].opcode == "lw") {

			if (count > 0) {
				string str1, str2;
				int cut1 = 0, cut2 = 0;
				int tamanho1 = linhas[count].alvo.size();
				if(tamanho1>3) {
					while(tamanho1-cut1!=4) {
						cut1++;
					}
					str1 = linhas[count].alvo.substr(cut1, 3);
				} else {
					str1 = linhas[count].alvo;
				}
				int tamanho2 = linhas[count].opr1.size();
				if(tamanho2>3) {
					while(tamanho2-cut2!=4) {
						cut2++;
					}
					str2 = linhas[count].opr1.substr(cut2, 3);
				} else {
					str2 = linhas[count].opr1;
				}
				//cout << "str1: " << str1 << endl;
				//cout << "str2: " << str2 << endl;
				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}

					std::size_t found1 = linhas[ii].alvo.find(str1);
					std::size_t found2 = linhas[ii].alvo.find(str2);
					if(found1!=std::string::npos) {
						
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
						
					} else if(found2!=std::string::npos) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}

					} else {
						info[count].instrucao[jj] = -1;
						++jj;					
					}
					
				}
			} else {

				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if (linhas[count].opcode == "sw") {
			if (count > 0) {
				string str1, str2;
				int cut1 = 0, cut2 = 0;
				int tamanho1 = linhas[count].alvo.size();
				if(tamanho1>3) {
					while(tamanho1-cut1!=4) {
						cut1++;
					}
					str1 = linhas[count].alvo.substr(cut1, 3);
				} else {
					str1 = linhas[count].alvo;
				}
				int tamanho2 = linhas[count].opr1.size();
				if(tamanho2>3) {
					while(tamanho2-cut2!=4) {
						cut2++;
					}
					str2 = linhas[count].opr1.substr(cut2, 3);
				} else {
					str2 = linhas[count].opr1;
				}
				//cout << "str1: " << str1 << endl;
				//cout << "str2: " << str2 << endl;
				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}

					std::size_t found1 = linhas[ii].alvo.find(str1);
					std::size_t found2 = linhas[ii].alvo.find(str2);
					if(found1!=std::string::npos) {
						
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
						
					} else if(found2!=std::string::npos) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}

					} else {
						info[count].instrucao[jj] = -1;
						++jj;					
					}
					
				}
			} else {

				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else {
			cerr << "Lista de comandos com comando invalido!" << endl;
			exit(1);
		}	
	}

}