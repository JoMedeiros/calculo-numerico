CC = g++
CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -pg
RM = rm -rf

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

.PHONY: all clean distclean doxy

all: dir ls1ex1 ls1ex2 ls1ex3

#### Lista 1 - Exercício 1 ####
ls1ex1: $(OBJ_DIR)/ls1ex1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^ -I$(INC_DIR)
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

#### Lista 1 - Exercício 2 ####
ls1ex2: $(OBJ_DIR)/ls1ex2.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^ -I$(INC_DIR)
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

#### Lista 1 - Exercício 3 ####
ls1ex3: $(OBJ_DIR)/ls1ex3.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^ -I$(INC_DIR)
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="
	
# Cria os diretórios necessários
dir:
	mkdir -p bin build

# Opção para depurar (só a questão 03)
debug: CPPFLAGS += -g -O0
debug: all

####		Dependências 		####
# l1ex1
$(OBJ_DIR)/ls1ex1.o: $(SRC_DIR)/ls1ex1.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $< -I$(INC_DIR)
# l1ex2
$(OBJ_DIR)/ls1ex2.o: $(SRC_DIR)/ls1ex2.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $< -I$(INC_DIR)
# l1ex3
$(OBJ_DIR)/ls1ex3.o: $(SRC_DIR)/ls1ex3.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $< -I$(INC_DIR)
	
# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Limpar os arquivos objetos e executáveis
clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
