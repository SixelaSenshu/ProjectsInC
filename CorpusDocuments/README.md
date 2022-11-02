* ## Introduction

Ce tp permet à un utilisateur de déposer plusieurs fichier.txt dans le dossier et de générer un corpus de document avec des précision sur chacun des mots dans le corpus.

* ## Structure du dossier

    - ### Sources

    On a donc le dossier sources avec le fichier main ainsi que tous les fichier permettant la compilation en un executable (.c).

    - ### Headers

    On a donc le dossier headers avec tous les headers permettant la compilation d'un fichier (.h).

    - ### Contenu

    On a donc les fichiers texte qui permettront de faire le corpus de documents ( Déja plusieurs par défaut (.txt)). 

    - ### Autres

    * On a le makefile permettant l'automatisation du fonctionnement du projet

    * Les données générer par la compilation (.o)


* ## Fonctionnement

    - ### Content
    
    On insère dans le content tous les fichiers texte que l'on veut.
    Et on les place dans l'invite de commande lors de l'execution 
    ``` gcc sources/main.c -o main && ./main content/*.txt ```

    - ### Make
        On a plusieurs commandes
        - Make Clear : nettoie les fichiers 
        - Make : Permet de générer les fichiers et leur compilation