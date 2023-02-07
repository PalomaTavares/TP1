#include <iostream>
using namespace std;
#include "USER.hpp"
#include "CAIXAENT.hpp"
#include <string>
#include <sstream>
#include <cstring>
#include "msgassert.h"

// construtor de usuario
Usuario::Usuario()
{
    this->inicio = nullptr;
}

// destrutor do usuario
Usuario::~Usuario()
{
    CaixaEntrada *aux = this->inicio;
    CaixaEntrada *c = aux;

    while (aux != nullptr)
    {
        delete c;
        aux = aux->frente;
        c = aux;
    }
}

// adiciona novo usuário
void Usuario::cadastrarUser(int id)
{
    CaixaEntrada *aux = this->inicio;

    //caso caixa de entrada esteja vazia
    if (this->inicio == nullptr)
    {
        CaixaEntrada *c = new CaixaEntrada(id);
        this->inicio = c;
        std::cout << "OK: CONTA " << c->getId() << " CADASTRADA" << std::endl;
    }
    else
    {
        while (aux != nullptr)
        {
            if (aux->getId() == id)
            {
                //caso já exista uma conta com o id recebido
                std::cout << "ERRO: CONTA " << aux->getId() << " JA EXISTENTE" << std::endl;
                return;;
            }
            aux = aux->frente;
        }
        CaixaEntrada *c = new CaixaEntrada(id);
        c->frente = this->inicio;
        this->inicio = c;
        std::cout << "OK: CONTA " << c->getId() << " CADASTRADA" << std::endl;
        return;
    }
}

// remove o usuario com o id selecionado
void Usuario::removerUser(int id)
{
    //caso não tenha nenhum
    CaixaEntrada *p = this->inicio;
    if (this->inicio == nullptr)
    {
        std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
        return;
    }

    //caso seja o primeiro usuário
    if (id == p->getId())
    {
        this->inicio = p->frente;
        delete p;
        std::cout << "OK: CONTA " << p->getId() << " REMOVIDA" << std::endl;
        return;
    }

    CaixaEntrada *aux = this->inicio;
    p = p->frente;

    //caso seja um usuário depois do primeiro 
    while (p != nullptr)
    {
        if (id == p->getId())
        {

            aux->frente = p->frente;
            delete p;
            std::cout << "OK: CONTA " << p->getId() << " REMOVIDA" << std::endl;
            return;
        }
        aux = aux->frente;
        p = p->frente;
        
    }
    std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
}

// coloca email na caixa de entrada do usuario que tem o id recebido
void Usuario::entregarEmail(string msg, int prior, int id)
{
    CaixaEntrada *aux = this->inicio;
    while (aux != nullptr)
    {
        if (aux->getId() == id)
        {
            aux->Enfileira(msg, prior);
            std::cout << "OK: MENSAGEM PARA " << aux->getId() << " ENTREGUE" << std::endl;
            return;
        }
        //sai do loop caso não exista uma caixa de entrada na próxima posição
        if(aux->frente == nullptr){
            break;
        }
        aux = aux->getFrente();
    }
    std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
}

// mostra na tela email com maior prioridade da conta com o id recebido
void Usuario::consultarEmail(int id)
{
    //caso a caixa de entrada não exista
    CaixaEntrada *aux = this->inicio;
    if (this->inicio == nullptr)
    {
        std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
        return;
    }
    while (aux != nullptr)
    {
        if (aux->getId() == id)
        {
            //caso a caixa de entrada esteja vazia
            if (aux->tamanho == 0)
            {
                std::cout << "CONSULTA " << aux->getId() << ": CAIXA DE ENTRADA VAZIA" << std::endl;
                return;
            }
            aux->retornarEmail();
            return;
        }
        if (aux->frente == nullptr)
        {
            break;
        }
        aux = aux->frente;
    }
    std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
}