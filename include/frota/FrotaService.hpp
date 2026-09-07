#ifndef FROTASERVICE__HPP
#define FROTASERVICE__HPP
#include "sqlite3.h"
#include "Veiculo.hpp"
class FrotaService{
    private:
        sqlite3* db;
    public:
        FrotaService(sqlite3* conexao);
        void cadastrarVeiculo(Veiculo veiculo);





};




#endif // FROTASERVICE__HPP
