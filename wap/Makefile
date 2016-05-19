all: generate main
generate: wap1/map_test1.cc
	g++ wap1/map_test1.cc -std=c++0x -I . -lm -DFLAT -o generate.exe
main: wap1/wap_sol1.cc
	g++ wap1/wap_sol1.cc -std=c++0x -I . -lm -o main.exe
trie_test: BTrie.cc
	g++ BTrie.cc -std=c++0x -I . -lm -DFLAT -DTRIE__TEST -o trie_test.exe
clean:
	rm *.exe

