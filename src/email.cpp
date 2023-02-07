#include "EMAIL.hpp"
#include <string>
#include <iostream>
using namespace std;

//atribui valores lidos ao email
Email::Email(string msg, int prior){
    this->msg = msg;
    this->prior = prior;
}

//atribui valores nulos ao email
Email::Email(){
    this->msg = " ";
    this->prior = -1;
}

//retorna mensagem do email
string Email::getMsg(){
    return this->msg;
}

//retorna prioridade do email
int Email::getPrior(){
    return this->prior;
}

//atribui mensagem lida ao email
void Email::setMsg(string msg){
    this->msg = msg;
}

//atribui prioridade ao email
void Email::setPrior(int prior){
    this->prior = prior;
}

//mostra mensagem do email na tela
void Email::imprimir(){
    cout<< this->getMsg();
}

//retorna o email que vem depois do atual
Email* Email::getProx(){
    return this->prox;
}

//atribui o email que vem depois do atual
void Email::setProx(Email *e){
    this->prox = e;
}
