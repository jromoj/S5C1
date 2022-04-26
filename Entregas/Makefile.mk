# Todas las veces se ejecutan los comandos a.cpp y a.py

all :: a.cpp a.py

a.cpp :: a.out
	g++ a.cpp
	./a.out > datos.txt
	
a.py ::
	python a.py
	