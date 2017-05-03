#include "pipeline.h"

Pipeline Instrucoes(string instrucao) {
    Pipeline inst;
    stringstream ss;
    ss << instrucao;
    string string = "";
    
    getline(ss, inst.opcode, ' ');
    if((inst.opcode == "add") || inst.opcode == "sub") {
        getline(ss, inst.alvo, ',');
        getline(ss, inst.opr1, ',');
        getline(ss, inst.opr2);
    }
    else if((inst.opcode == "beq") || (inst.opcode == "bne")) { 
        getline(ss, inst.opr1, ',');
        getline(ss, inst.opr2, ',');
        getline(ss, string);
        inst.jump = stoi(string);
    }
    else if(inst.opcode == "j"){
        getline(ss, string);
        inst.jump = stoi(string);
    }
    else if((inst.opcode == "lw") || (inst.opcode == "sw")){
        getline(ss, inst.alvo, ',');
        getline(ss, inst.num, '(');
        getline(ss, inst.opr1, ')');
    }

    inst.alvo.erase(std::remove(inst.alvo.begin(), inst.alvo.end(), ' '), inst.alvo.end());
    inst.opr1.erase(std::remove(inst.opr1.begin(), inst.opr1.end(), ' '), inst.opr1.end());
    inst.opr2.erase(std::remove(inst.opr2.begin(), inst.opr2.end(), ' '), inst.opr2.end());
    
    return inst;
}

int conflitos(Pipeline p1, Pipeline p2) {
    if((p1.alvo != "") && ((p2.opr1 == p1.alvo) || (p2.opr2 == p1.alvo))){
        return 1;
    }
    return 0;
}

void ordem(int& contaCiclos, int& contaInst, string *instrucoes, int cont, Pipeline *pipeline) {
    int pos = 0;
    int ii=0;
    while(ii < cont) {
        pipeline[contaInst] = Instrucoes(instrucoes[ii]);      
        if(contaInst > 0) {
            pos = pipeline[contaInst - 1].posicao + 5;                          
            for(int jj = 0; ((jj < 3) && (jj < ii)); jj++) {                             
                if((conflitos(pipeline[contaInst - (jj + 1)], pipeline[contaInst])) == 1){
                    while((pos - pipeline[contaInst - (jj + 1)].posicao) < 20){
                        pos += 5;
                    }
                    break;
                } else
                    pos = pipeline[contaInst - 1].posicao + 5;
            }
            pipeline[contaInst].posicao = pos;
        }
        if(pipeline[contaInst].jump > 0)
            ii = pipeline[contaInst].jump - 1;
        else
            ii++;
        contaCiclos = 5 + (pipeline[contaInst].posicao / 5);
        contaInst++;
    }
}

void printInst(Pipeline p) {
    if((p.opcode == "add") || (p.opcode == "sub")) {
        cout << p.opcode << " " << p.alvo << ", " << p.opr1 << ", " << p.opr2;
    }
    else if((p.opcode == "beq") || (p.opcode == "bne")){
        cout << p.opcode << " " << p.opr1 << ", " << p.opr2 << ", " << p.jump;
    }
    else if(p.opcode == "j"){
        cout << p.opcode << " " << p.jump;
    }
    else if((p.opcode == "lw") || (p.opcode == "sw")){
        cout << p.opcode << " " << p.alvo << "," << p.num << "(" << p.opr1 << ")";
    }
}

void printCiclo(int contaC, int contaI, Pipeline *pipeline, string *estagios) {
    cout << endl << "Quantidade total de ciclos: " << contaC << endl;
    cout << "-----------------------------------------------------" << endl;
    
    int *vetor = new int[contaI];
    for(int ii = 0; ii < contaI; ii++){
        vetor[ii] = 0;
    }
    int ciclo=0;
    while(ciclo < contaC) {
        cout << "Ciclo " << (ciclo + 1) << endl;
        for(int ii = 0; ii < 5; ii++) {
            cout << estagios[ii] << ": ";
            for(int jj = 0; jj < contaI; jj++) {
                if((pipeline[jj].posicao+vetor[jj]) == ((ciclo * 5) + ii)) {
                    printInst(pipeline[jj]);
                    vetor[jj] += 6;
                    if(vetor[jj] >= 30) vetor[jj] = 0;
                    break;
                }
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------" << endl;
    ciclo++;
    }
    delete[] vetor;
}