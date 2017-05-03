#ifndef PIPELINE_H
#define PIPELINE_H

#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

typedef struct{
    
    string opcode = "";
    string alvo = "";
    string opr1 = "";
    string opr2 = "";
    string num = "";
    int posicao = 0;
    int jump = 0;

    }Pipeline;

    Pipeline Instrucoes(string instrucao);

    int conflitos(Pipeline p1, Pipeline p2);

    void ordem(int& contaCiclos, int& contaInst, string *instrucoes, int cont, Pipeline *pipeline);

    void printInst(Pipeline p);

    void printCiclo(int contaC, int contaI, Pipeline *pipeline, string *estagios);

#endif