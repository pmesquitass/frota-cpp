#include <iostream>
#include <fstream>
#include <sstream>
#include "sqlite3.h"
#include "FrotaService.hpp"

std::string lerArquivo(const std::string& caminho) {
    std::ifstream arquivo(caminho);
    std::stringstream buffer;
    buffer << arquivo.rdbuf();
    return buffer.str();
}

int main() {
    Veiculo v1("KDKS234", "ONIX", 2014, 1500);
    Motorista m1("Pedro","14/03/2007","094503433","AB");
    sqlite3* db;
    int resultado = sqlite3_open("frota.db", &db);
    if (resultado != SQLITE_OK) {
        std::cerr << "Erro ao abrir o banco: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    std::cout << "Banco aberto com sucesso!" << std::endl;

    std::string sqlSchema = lerArquivo("db/schema.sql");
    if (sqlSchema.empty()) {
        std::cerr << "Nao consegui ler o schema.sql" << std::endl;
        sqlite3_close(  db);
        return 1;
    }

    char* erro = nullptr;
    resultado = sqlite3_exec(db, sqlSchema.c_str(), nullptr, nullptr, &erro);

    if (resultado != SQLITE_OK) {
        std::cerr << "Erro ao criar tabelas: " << erro << std::endl;
        sqlite3_free(erro);
    } else {
        std::cout << "Tabelas criadas com sucesso!" << std::endl;

        FrotaService fs(db);
        fs.cadastrarVeiculo(v1);
        fs.cadastrarMotorista(m1);
    }

    sqlite3_close(db);
    return 0;
}
