menu.exe: *.cpp
	g++ *.cpp -o menu.exe -Wall -Werror -Wconversion
	./menu.exe