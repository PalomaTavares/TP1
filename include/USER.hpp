#ifndef USER_H
#define USER_H

#include <string>
#include "CAIXAENT.hpp"

class Usuario
{
public:
    // construtor que inicializa os valores da classe
    Usuario();

    //destrutor da classe
    ~Usuario();

    //adiciona nova caixa de entrada
    void cadastrarUser(int id);

    //remove uma caixa de entrada 
    void removerUser(int id);

    //adiciona novo email na caixa de entrada
    void entregarEmail(string msg, int prior, int id);

    //imprime email na tela
    void consultarEmail(int id);
    
private:
    CaixaEntrada *inicio;
};
#endif