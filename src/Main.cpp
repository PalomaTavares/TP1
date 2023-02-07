#include <iostream>
#include <stdio.h>
#include <fstream>
#include <getopt.h>
#include <cstring>
#include "USER.hpp"
#include <string>
#include <sstream>

using namespace std;
#include "msgassert.h"


typedef struct opt
{
    int opescolhida;
    char lognome[100];
    int regmem;
    char inFile[100];
} opt_tipo;

void get_args(int argc, char **argv, opt_tipo *opt)
{
    // variaveis externas do getopt
    extern char *optarg;

    // variavel auxiliar
    int c;

    opt->opescolhida = 0;
    opt->regmem = 0;
    opt->lognome[0] = 0;

    while ((c = getopt(argc, argv, ":p:l")) != EOF)
    {
        switch (c)
        {
        case 'p':
            strcpy(opt->lognome, optarg);
            break;
        case 'l':
            opt->regmem = 1;
            break;
        default:
            exit(1);
            break;
        }
    };
}

int main(int argc, char *argv[])
{
    //Usuario *u = new Usuario();
    // u->cadastrarUser(1);
    // u->cadastrarUser(5);
    // u->entregarEmail("msg", 1, 1);
    // u->entregarEmail("aa", 6, 1);
    // u->entregarEmail("bbbb", 5, 5);
    // u->entregarEmail("aac", 1, 5);

//    u->removerUser(5);
//     v->removerUser(2);
//     u->removerUser(5);
//    u->consultarEmail(5);
//    u->consultarEmail(5);
//    u->consultarEmail(1);
//    u->consultarEmail(1);



    opt_tipo opt;

    get_args(argc, argv, &opt);
    
    // // iniciaMemLog
    // iniciaMemLog(opt.lognome);

    // // ativar ou nao o registro de acesso
    // if (opt.regmem)
    // {
    //     ativaMemLog();
    // }
    // else
    // {
    //     desativaMemLog();
    // }
    fstream file(argv[1], ios::in);
    //std::cout<<argv[1]<<endl;
    erroAssert(file, "Arquivo não existe");
    string linha;
    string operacao, msg;
    string msgCompleta;
    int id, pri=0;
    Usuario *u = new Usuario();
    while(getline(file, linha))
    {
        
        stringstream s(linha);
        s >> operacao >> id;
        if(operacao == "CADASTRA"){
            u->cadastrarUser(id);
        }
        if(operacao == "REMOVE"){
            u->removerUser(id);
        }
        if(operacao == "ENTREGA"){
            msgCompleta = "";
            s >> pri;
            s >> msg;
            //std::cout<<msg;
            while(msg != "FIM"){
                msgCompleta += " " + msg;
                s >> msg;
            }
            //cout<<" \n ID: "<<id<<"\npri: "<<pri<< "\nmsg: "<<msgCompleta;
            u->entregarEmail(msgCompleta, pri, id);
        }
        if(operacao == "CONSULTA"){
            u->consultarEmail(id);
        }
                
   }
   
    return 0;
}