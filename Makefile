#generate: map_test1.cc
	g++ map_test1.cc -std=c++0x -I . -lm -DFLAT -o generate.exe
#main: wap_sol1.cc
	g++ wap_sol1.cc -std=c++0x -I . -lm -o main.exe
