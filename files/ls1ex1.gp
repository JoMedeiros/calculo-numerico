set xrange[-1.5:2.5]
set yrange[-5:5]
plot x**3 - 2*x**2 - x + 2 title "funcao cubica", -2*x + 2 title "reta tangente em x = 1", -0.63113 title "reta ponto critico 1", 2.11261 title "reta ponto critico 2"
set label "(1, f(x))" at 1,0 point pt 7
set label "tan(x) = 0" at 1,0 point pt 7 offset -8,-1
set label "ponto critico 1" at 1.54858,-0.63113 point pt 7
set label "ponto critico 2" at -0.21525,2.11261 point pt 7
