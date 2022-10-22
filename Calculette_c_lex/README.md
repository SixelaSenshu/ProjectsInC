# Guide d'utilisation
----------------------------------------------------------------
## 1.MAKEFILE
- make clear : Nettoie tous les fichiers
- make exec : Génère l'éxécutable du programme
- make move : Décale tous les éxécutable dans un fichier

-> Faire make clear && make pour lancer le programme
-> make si aucun éxécutable
----------------------------------------------------------------
## 2.Src
* Les .c :
    - utils.c : Fichier avec tous les fonctions utilitaires
    - stack.c : Fichier avec les fonctions de la pile
    - main.c : Fichier qui gère le programme 
    - caclulette.c : Fichier lex qui permet de reconnaître les diffèrentes unités lexical
* Les .h :
    - cal.h : Fichier avec tous les defines et enum
    - *.h : Tous les headers des fichiers c