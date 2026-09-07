#include "Veiculo.hpp"
#include <string>
Veiculo::Veiculo(std::string p,std::string m, int a,double km)
    : placa(p),modelo(m),ano(a),quilometragem(km),status("disponivel"){}
std::string Veiculo::getTipo(){return tipo;}
std::string Veiculo::getPlaca(){return placa;}
std::string Veiculo::getModelo(){return modelo;}
int Veiculo::getAno(){return ano;}
double Veiculo::getQuilometragem(){return quilometragem;}
std::string Veiculo::getStatus(){return status;}
