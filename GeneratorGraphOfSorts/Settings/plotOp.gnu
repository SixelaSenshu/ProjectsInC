 set terminal png
 set output "Op.png"
 set title 'Comparaison des algorithmes de tris'
 set xlabel 'Taille de la liste'
 set ylabel 'Nombre opérations'
 set style fill transparent solid 0.5 noborder
 plot 'plot.dat' using 0:3 title 'Bulle' with linespoints,\
      'plot.dat' using 0:6 title 'Insertion' with linespoints,\
      'plot.dat' using 0:9 title 'Selection' with linespoints,\
      'plot.dat' using 0:12 title 'Rapide' with linespoints,\
      'plot.dat' using 0:15 title 'Tri fusion' with linespoints,\
      'plot.dat' using 0:18 title 'Tri par tas' with linespoints
 