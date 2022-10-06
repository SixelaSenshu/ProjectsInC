####
CC = gcc
CFLAGS = -DNDEBUG
EXEC=main
OPTION=-o
NBLISTE=50
TAILLE=10
NBEXPRES=10

.PHONY: clear all 
# Ensemble des commandes afin de générer les fichiers compilées & données 
## Exécution des fichiers et ensemble des dépendances
all : $(EXEC)

## Décalage de tous les fichiers dans le Data
main : data plot.dat csv.csv Np.png Op.png Cp.png
	mv plot.dat Data && mv csv.csv Data && mv data Data && mv Op.png Data/img && mv Np.png Data/img && mv Cp.png Data/img

## Éxécution du fichier sur la sortie standard
show : Data data
	./data 1 $(NBEXPRES) $(TAILLE) $(NBLISTE)

## Insertion des données des tri dans le csv 
csv.csv : data
	./data 2 $(NBEXPRES) $(TAILLE) $(NBLISTE) > csv.csv 

## Insertion des données dans le fichier .dat & génération des graphiques 
plot.dat : Settings/plotNp.gnu Settings/plotOp.gnu Settings/plotCp.gnu data
	./data 3 $(NBEXPRES) $(TAILLE) $(NBLISTE) > plot.dat && gnuplot Settings/plotNp.gnu && gnuplot Settings/plotCp.gnu && gnuplot Settings/plotOp.gnu

## Compilation du fichier.c en éxécutable 
data : Src/main.c
	$(CC) Src/main.c $(CFLAGS) $(OPTION) data

clear : 
	rm -f Data/* 
