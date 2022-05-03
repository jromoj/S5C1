# Todas las veces se revisa a.out y EDO2.py

all :: a.out EDO2.py

a.out :: EDO2.cpp
	g++ EDO2.cpp
	./a.out > datos.txt
	
EDO2.py ::
	python EDO2.py
	