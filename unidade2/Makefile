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

all: dir ls4ex1 ls4ex2 ls4ex3 ls5ex1

#### Lista 4 - Exercício 1 ####
ls4ex1: $(OBJ_DIR)/ls4ex1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^ -I$(INC_DIR)
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

#### Lista 4 - Exercício 2 ####
ls4ex2: $(OBJ_DIR)/ls4ex2.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^ -I$(INC_DIR)
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

#### Lista 4 - Exercício 3 ####
ls4ex3: $(OBJ_DIR)/ls4ex3.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/$@ $^ -I$(INC_DIR)
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="
	
#### Lista 5 - Exercício 1 ####
ls5ex1: $(OBJ_DIR)/ls5ex1.o
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
# ls4ex1
$(OBJ_DIR)/ls4ex1.o: $(SRC_DIR)/ls4ex1.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $< -I$(INC_DIR)
# ls4ex2
$(OBJ_DIR)/ls4ex2.o: $(SRC_DIR)/ls4ex2.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $< -I$(INC_DIR)
# ls4ex3
$(OBJ_DIR)/ls4ex3.o: $(SRC_DIR)/ls4ex3.cpp
	$(CC) -c $(CPPFLAGS) -o $@ $< -I$(INC_DIR)
# ls5ex1
$(OBJ_DIR)/ls5ex1.o: $(SRC_DIR)/ls5ex1.cpp
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
