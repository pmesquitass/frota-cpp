#ifndef USO_HPP
#define USO_HPP
#include <string>
class Uso{
    private:
        int veiculo_id, motorista_id;
        std::string data_saida, data_retorno;
        double km_inicial, km_final;
    public:
        Uso(int, int,std::string,double);
        int getVeiculoID();
        int getMotoristaID();
        std::string getDataSaida();
        std::string getDataRetorno();
        double getKmInicial();
        double getKmFinal();



};
#endif // USO_HPP
