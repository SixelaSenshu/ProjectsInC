 set terminal png
 set output "Np.png"
 set title 'Comparaison des algorithmes de tris'
 set xlabel 'Taille de la liste'
 set ylabel 'Nombre de permutations'
 set style fill transparent solid 0.5 noborder
 plot 'plot.dat' using 0:1 title 'Bulle' with linespoints,\
  'plot.dat' using 0:4 title 'Insertion' with linespoints,\
  'plot.dat' using 0:7 title 'Selection' with linespoints,\
  'plot.dat' using 0:10 title 'Rapide' with linespoints,\
  'plot.dat' using 0:13 title 'Tri fusion' with linespoints,\
  'plot.dat' using 0:16 title 'Tri par tas' with linespoints
 