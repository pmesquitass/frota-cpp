#include "Uso.hpp"
#include <string>
Uso::Uso(int v,int m,std::string ds,double k)
                : veiculo_id(v), motorista_id(m), data_saida(ds),data_retorno(""),km_inicial(k),km_final(-1){}
int Uso::getVeiculoID(){return veiculo_id;}
int Uso::getMotoristaID(){return motorista_id;}
std::string Uso::getDataSaida(){return data_saida;}
std::string Uso::getDataRetorno(){return data_retorno;}
double Uso::getKmInicial(){return km_inicial;}
double Uso::getKmFinal(){return km_final;}
