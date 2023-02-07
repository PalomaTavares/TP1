#ifndef EMAIL_H
#define EMAIL_H
#include <string>
using namespace std;
class Email
{
public:
  //construtores de email
  Email(std::string msg, int prior);//seta valores lidos
  Email();//seta valores nulos

  //retorna a mesnsagem contida no email
  string getMsg();

  //retona a prioridade do email
  int getPrior();

  //atribui mensagem ao email
  void setMsg(string msg);
  
  //atribui prioridade ao email
  void setPrior(int prior);

  //retorna o email depois do atual
  Email* getProx();

  //atribui valores do email que vem depois do atual
  void setProx(Email *e);

  //mostra a mensagem do email na tela
  void imprimir();


private:
  string msg;
  int prior;
  Email *prox;
};

#endif