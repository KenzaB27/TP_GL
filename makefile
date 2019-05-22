.SILENT:
.PHONY : compil run clean suppr valgrind gdb
# Fichier Makefile generique
SHELL := /bin/bash


#--- VARIABLES ---
#Fichiers
DIR = bin
FICHIER_SORTIE := $(DIR)/analog
CPP := $(wildcard *.cpp)
LIBRAIRIES :=
CMD =

O := $(patsubst %,$(DIR)/%,$(CPP:.cpp=.o))
DEP :=$(O:.o=.d)

#Variables de compilation
COMPILATEUR := g++
COMPILATEUR_FLAGS := -Wall -W -ansi -pedantic -std=c++11
DEBUG := -g
DEPENDANCES := -MMD


#Variables d'edition de liens
EDITION_DE_LIENS := g++
EDITION_FLAGS :=


#Variables de commande
ECHO := echo
RM := rm
RM_FLAGS := -f -r
CLEAN := clean
MAKE := make
VALGRIND := valgrind --leak-check=yes
GDB := gdb



#--- COMMANDES ---
compil : $(FICHIER_SORTIE)

test : $(FICHIER_SORTIE)
	cd Tests; ./mktest.sh; cd ..

#Edition de Lien
$(FICHIER_SORTIE) : $(O)
	@echo "Edition de lien de $(FICHIER_SORTIE)"
	$(EDITION_DE_LIENS) -o $(FICHIER_SORTIE) $(EDITION_FLAGS) $(O) $(LIBRAIRES)

#Execution
run : $(FICHIER_SORTIE)
	@echo "Execution ..."
	./$(FICHIER_SORTIE) $(CMD)

#Nettoyage
clean :
	$(MAKE) suppr
	$(MAKE) compil

#Suppression
suppr :
	@echo "Nettoyage ..."
	$(RM) $(RM_FLAGS) $(FICHIER_SORTIE) $(DIR)

#Valgrind
valgrind :
	$(MAKE) suppr
	$(MAKE) compil
	@echo "Valgrind de $(FICHIER_SORTIE) ..."
	$(VALGRIND) ./$(FICHIER_SORTIE)

#GDB
gdb :
	$(MAKE) suppr
	$(MAKE) compil
	@echo "GdB de $(FICHIER_SORTIE) ..."
	$(GDB) ./$(FICHIER_SORTIE) -x input.gdb

#on inclut toutes les dependances des fichiers .cpp
-include $(DEP)

#Pattern de Compilation
$(DIR)/%.o : %.cpp | $(DIR)
	@echo "    Compilation de $<"
	$(COMPILATEUR) $(COMPILATEUR_FLAGS) $(DEBUG) $(DEPENDANCES) -o $@ -c $<

#Creation du repertoire d'objets au besoin
$(DIR) :
	mkdir -p $@