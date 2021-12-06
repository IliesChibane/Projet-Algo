TARGET = main.pdf
MAIN = main.tex
DEP = main.tex algo1.tex algo2.tex algo3.tex suppressionnoeud.tex conclusion.tex annexe.tex

$(TARGET) : $(DEP)
	latexmk -pdf $(MAIN) -shell-escape
	latexmk -c $(DEP)
	rm -rf _minted-main

clean :
	latexmk -c $(DEP)
