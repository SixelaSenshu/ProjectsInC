 set terminal png
 set output "Cp.png"
 set title 'Comparaison des algorithmes de tris'
 set xlabel 'Taille de la liste'
 set ylabel 'Nombre de comparaisons'
 set style fill transparent solid 0.5 noborder
 plot 'plot.dat' using 0:2 title 'Bulle' with linespoints,\
  'plot.dat' using 0:5 title 'Insertion ' with linespoints,\
  'plot.dat' using 0:8 title 'Selection' with linespoints,\
  'plot.dat' using 0:11 title 'Rapide' with linespoints,\
  'plot.dat' using 0:14 title 'Tri fusion' with linespoints,\
  'plot.dat' using 0:17 title 'Tri par tas' with linespoints
 