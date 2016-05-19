all: generate main
generate: map_test1.cc
	g++ map_test1.cc -std=c++0x -I . -lm -DFLAT -o generate.exe
main: wap_sol1.cc
	g++ wap_sol1.cc -std=c++0x -I . -lm -o main.exe
trie_test: map_test1.cc
	g++ BTrie.cc -std=c++0x -I . -lm -DFLAT -DTRIE__TEST -o trie_test.exe
clean:
	rm *.exe

