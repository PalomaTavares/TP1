#include "CAIXAENT.hpp"
#include "EMAIL.hpp"
#include <string>
#include "msgassert.h"
#include <iostream>
using namespace std;

// construtor atribui valores nulos aos atributos da classe
CaixaEntrada::CaixaEntrada(int id) // recebe id
{
    this->frente = nullptr; // Célula cabeça;
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    tamanho = 0;
    this->id = id;
}

// retorna a quantidade de emails
int CaixaEntrada::getTamanho()
{
    return tamanho;
}

// coloca a caixa de entrada recebida na primeira posição
void CaixaEntrada::setFrente(CaixaEntrada *e)
{
    this->frente = e;
}

// coloca email na caixa de entrada de acordo com sua prioridade
void CaixaEntrada::Enfileira(string msg, int prior)
{
    //caso a caixa de entrada  esteja vazia
    if (this->getTamanho() == 0)
    {
        Email *novo = new Email();
        novo->setMsg(msg);
        novo->setPrior(prior);
        novo->setProx(nullptr);
        this->primeiro = novo;
        this->ultimo = novo;
        tamanho++;
    }else
    {
        //caso a caixa de entrada tiver um elemento
        Email *novo = new Email();
        novo->setMsg(msg);
        novo->setPrior(prior);
        if (primeiro->getProx() == nullptr)
        {
            if (primeiro->getPrior() >= novo->getPrior())
            {
                primeiro->setProx(novo);
                novo->setProx(nullptr);
                this->ultimo = novo;
                tamanho++;
            }
            else
            {
                novo->setProx(primeiro);
                this->primeiro = novo;
                tamanho++;
            }
        }
        else if(novo->getPrior() > this->primeiro->getPrior())
        {
                novo->setProx(primeiro);
                this->primeiro = novo;
                tamanho++;
        }     
        else{
            Email *aux = this->primeiro;
            while (aux != nullptr)
            {
                if(aux->getProx() != nullptr){
                    if (aux->getPrior() >= novo->getPrior() && novo->getPrior() > aux->getProx()->getPrior())
                    {
                        novo->setProx(aux->getProx());
                        aux->setProx(novo);
                        tamanho++;
                        return;
                    }

                }
                
                
                aux = aux->getProx();
            }
            this->ultimo->setProx(novo);
            this->ultimo = novo;
            this->ultimo->setProx(nullptr);
            tamanho++;
        }
    }
}

//reotna id da caixa de entrada
int CaixaEntrada::getId()
{
    return this->id;
}

//mostra mensagem na tela
void CaixaEntrada::retornarEmail()
{
    Email *aux = this->primeiro->getProx();
    std::cout << "CONSULTA " << this->getId() << ": " << this->primeiro->getMsg() << "\n";
    delete this->primeiro;
    this->primeiro = aux;
    tamanho--;
}

//retorna o primeiro elemento da caixa de entrada
CaixaEntrada *CaixaEntrada::getFrente()
{
    return this->frente;
}