TARGET = main.pdf
MAIN = main.tex
DEP = main.tex algo1.tex algo2.tex algo3.tex

$(TARGET) : $(DEP)
	latexmk -pdf $(MAIN)
	latexmk -c $(DEP)

clean :
	latexmk -c $(DEP)
