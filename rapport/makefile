TARGET = main.pdf
MAIN = main.tex
DEP = main.tex algo2.tex AlgoDichotomie.tex

$(TARGET) : $(DEP)
	latexmk -pdf $(MAIN)
	latexmk -c $(DEP)

clean :
	latexmk -c $(DEP)
