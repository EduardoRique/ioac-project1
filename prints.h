#ifndef PRINTS_H
#define PRINTS_H

#include <iostream>

using std::cout;
using std::endl;
using std::string;

typedef struct{
    string opcode;
    string alvo;
    string opr1;
    string opr2;
    }Instrucao;

void printif(Instrucao instrucoes[], int &aux, int ciclo, int q);
void printid(Instrucao instrucoes[], int &aux, int ciclo, int q);
void printex(Instrucao instrucoes[], int &aux, int ciclo, int q);
void printmem(Instrucao instrucoes[], int &aux, int ciclo, int q);
void printwb(Instrucao instrucoes[], int &aux, int ciclo, int &q);

#endif