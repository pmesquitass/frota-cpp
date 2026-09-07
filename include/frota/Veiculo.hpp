#ifndef VEICULO_HPP
#define VEICULO_HPP
#include <string>

class Veiculo{
    private:
        std::string tipo,placa,modelo,status;
        double quilometragem;
        int ano;
    public:
        Veiculo(std::string,std::string,int,double);
        std::string getTipo();
        std::string getPlaca();
        std::string getModelo();
        std::string getStatus();
        int getAno();
        double getQuilometragem();


};


#endif
