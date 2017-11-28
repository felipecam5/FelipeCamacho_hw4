Resuls_hw5.pdf : Results_hw5.tex AJUSTEMODELO.pdf 
	pdflatex Results_hw5.tex


AJUSTEMODELO.pdf : Plots.py Resultados.txt
	python Plots.py 
	

Resultados.txt: CurvaRotacion.x
	./CurvaRotacion.x

CurvaRotacion.x : CurvaRotacion.c
	cc CurvaRotacion.c -o CurvaRotacion.x -lm


clean :
	rm CurvaRotacion.x clean  *.pdf *.log *.aux *.txt *.wav
