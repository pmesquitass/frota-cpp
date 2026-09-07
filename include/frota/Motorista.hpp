#ifndef MOTORISTA_HPP
#define MOTORISTA_HPP
#include <string>

class Motorista{
    private:
        std::string nome,data_nascimento,cnh,categoria;
    public:
        Motorista(std::string,std::string,std::string,std::string);
        std::string getNome();
        std::string getDataNascimento();
        std::string getCNH();
        std::string getCategoria();

};


#endif // MOTORISTA_HPP
