all: wap1.exe wap2.exe wap1_generate wap2_generate

wap1_generate: wap1_generate.cc
	g++ wap1_generate.cc -std=c++0x -I . -lm -o wap1_generate.exe
wap2_generate: wap2_generate.cc
	g++ wap2_generate.cc -std=c++0x -I . -lm -o wap2_generate.exe
wap1.exe: wap_sol1.cc
	g++ wap_sol1.cc -std=c++0x -I . -lm -o wap1.exe
wap2.exe: wap2_sol.cc
	g++ wap2_sol.cc -std=c++0x -I . -lm -DFLAT -o wap2.exe
clean:
	rm *.exe

