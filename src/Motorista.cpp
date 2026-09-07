#include "Motorista.hpp"
#include <string>
Motorista::Motorista(std::string n,std::string data,std::string ncnh,std::string cat)
    : nome(n), data_nascimento(data), cnh(ncnh), categoria(cat){}
std::string Motorista::getNome(){return nome;}
std::string Motorista::getDataNascimento(){return data_nascimento;}
std::string Motorista::getCNH(){return cnh;}
std::string Motorista::getCategoria(){return categoria;}
