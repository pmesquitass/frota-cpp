CREATE TABLE IF NOT EXISTS veiculos (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    placa TEXT NOT NULL UNIQUE,
    modelo TEXT NOT NULL,
    ano INTEGER NOT NULL,
    quilometragem INTEGER NOT NULL DEFAULT 0,
    status TEXT NOT NULL DEFAULT 'disponivel' CHECK (status IN ('disponivel','em_uso','manutencao'))
);

CREATE TABLE IF NOT EXISTS motoristas (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT NOT NULL,
    cnh TEXT NOT NULL UNIQUE,
    categoria TEXT NOT NULL,
    data_nascimento TEXT NOT NULL
);

CREATE TABLE IF NOT EXISTS usos (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    veiculo_id INTEGER NOT NULL,
    motorista_id INTEGER NOT NULL,
    data_saida TEXT NOT NULL,
    data_retorno TEXT,
    km_inicial INTEGER NOT NULL,
    km_final INTEGER,
    FOREIGN KEY (veiculo_id) REFERENCES veiculos(id),
    FOREIGN KEY (motorista_id) REFERENCES motoristas(id)
);
