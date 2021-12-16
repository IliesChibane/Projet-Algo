TARGET = main.pdf
MAIN = main.tex
DEP = main.tex algorithme_resolution.tex

$(TARGET) : $(DEP)
	latexmk -pdf $(MAIN) -shell-escape
	latexmk -c $(DEP)
	rm -rf _minted-main

clean :
	latexmk -c $(DEP)
