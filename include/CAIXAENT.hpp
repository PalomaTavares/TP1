#ifndef CAIXAENT_H
#define CAIXAENT_H

#include "EMAIL.hpp"

class CaixaEntrada
{
public:
    //construtor
    CaixaEntrada(int id);

    //adiciona email a caixa de entrada
    void Enfileira(string msg, int prior);

    //retorna o tamnaho da pilha
    int getTamanho();

    //retorna o id da caixa de entrada
    int getId();

    //retorna o primeiro elemento da caixa de entrada
    CaixaEntrada* getFrente();

    //atribui os valores a primeira posição da pilha
    void setFrente(CaixaEntrada *e);

    friend class Usuario;
   
   //retorna o email de maior prioridade da caixa de entrada
    void retornarEmail();

private:
    CaixaEntrada *frente;
    Email *primeiro;
    Email *ultimo;

protected:
    int tamanho{0};
    int id;
};
#endif