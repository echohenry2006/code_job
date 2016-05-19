all: wap1.exe wap2.exe wap1_generate wap2_generate

wap1_generate: wap1/wap1_generate.cc
	g++ wap1/wap1_generate.cc -std=c++0x -I . -lm -DFLAT -o wap1_generate.exe
wap2_generate: wap2/wap2_generate.cc
	g++ wap2/wap2_generate.cc -std=c++0x -I . -lm -o wap2_generate.exe
wap1.exe: wap1/wap_sol1.cc
	g++ wap1/wap_sol1.cc -std=c++0x -I . -lm -o wap1.exe
trie_test: BTrie.cc
	g++ BTrie.cc -std=c++0x -I . -lm -DFLAT -DTRIE__TEST -o trie_test.exe
xortrie_test: BTrie.cc
	g++ xortrie.cc -std=c++0x -I . -lm -DXORTRIE__TEST -o xortrie_test.exe
wap2.exe: wap2/wap2_sol.cc
	g++ wap2/wap2_sol.cc -std=c++0x -I . -lm -DFLAT -o wap2.exe
clean:
	rm *.exe

