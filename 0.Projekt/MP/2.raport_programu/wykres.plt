# Ustawienie formatu wyjściowego na PNG
set terminal png size 1200,800

# Ustawienie nazwy pliku wyjściowego
set output 'wykresy dla u(x,t).png'

# Ustawienie tytułu i etykiet osi
set title 'Wykres funkcji u'
set xlabel 'X'
set ylabel 'u'
set xrange[-0.01:1.01]
set yrange[-0.02:*]#1.01
set xtics 0.1
set mxtics 10
set ytics 0.1
set mytics 2
set key left
# Rysowanie wykresu
# [i=0:n-2] n - ilosc wykresow
#plot for [i=0:18] sprintf("WynikiDlaT%.6f.txt", i*0.005) using 1:2 with linespoints title sprintf("t=%.3f", i*0.005)
plot for [i=0:17] sprintf("WynikiDlaT%.6f.txt", i*0.0005) using 1:2 with linespoints title sprintf("t=%.3f", i*0.0005)
