#include "FrotaService.hpp"
#include <string>
#include <iostream>
FrotaService::FrotaService(sqlite3* conexao){db=conexao;}

void FrotaService::cadastrarVeiculo(Veiculo v){
    std::string sql = "INSERT INTO veiculos (placa, modelo, ano, quilometragem, status) VALUES (?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt, nullptr);

    sqlite3_bind_text(stmt,1,v.getPlaca().c_str(),-1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,2,v.getModelo().c_str(),-1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,3,v.getAno());
    sqlite3_bind_double(stmt,4,v.getQuilometragem());
    sqlite3_bind_text(stmt,5,v.getStatus().c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

}
void FrotaService::cadastrarMotorista(Motorista m){
        std::string sql = "INSERT INTO motoristas (nome, data_nascimento, cnh, categoria) VALUES (?, ?, ?, ?)";
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(db,sql.c_str(),-1,&stmt,nullptr);

        sqlite3_bind_text(stmt,1,m.getNome().c_str(),-1,SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt,2,m.getDataNascimento().c_str(),-1,SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt,3,m.getCNH().c_str(),-1,SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt,4,m.getCategoria().c_str(),-1,SQLITE_TRANSIENT);
        sqlite3_step(stmt);
        int stepResult = sqlite3_step(stmt);
        if (stepResult != SQLITE_DONE) {
    std::cerr << "Erro ao cadastrar motorista: " << sqlite3_errmsg(db) << std::endl;
}
        sqlite3_finalize(stmt);
}

