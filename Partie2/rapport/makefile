TARGET = main.pdf
MAIN = main.tex
DEP = main.tex presentation_probleme.tex presentation_solution.tex etude_experimentale.tex

$(TARGET) : $(DEP)
	latexmk -pdf $(MAIN) -shell-escape
	latexmk -c $(DEP)
	rm -rf _minted-main

clean :
	latexmk -c $(DEP)
