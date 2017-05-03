#ifndef PRINTS_H
#define PRINTS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct{
    string opcode;
    string alvo;
    string opr1;
    string opr2;
    }Instrucao;

struct Dependencia {
	int instrucao[2];
};


void processando(Instrucao *linhas, int &countInstruction, Dependencia *info);

void printif(Instrucao instrucoes[], int aux[], int ciclo, int q[], int *dep, int light[], int contador);
void printid(Instrucao instrucoes[], int aux[], int ciclo, int q[], int dep[], int light[], int contador);
void printex(Instrucao instrucoes[], int aux[], int ciclo, int q[], int *dep, int light[], int contador);
void printmem(Instrucao instrucoes[], int aux[], int ciclo, int q[], int *dep, int light[], int contador);
void printwb(Instrucao instrucoes[], int aux[], int ciclo, int q[], int *dep, int light[], int contador);
void print(Instrucao instrucoes[], int aux[], int ciclo, int q[], int *dep, int light[], int contador);

#endif