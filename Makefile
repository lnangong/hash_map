

hash: test_main.cpp hash_map.h hash_map.cpp iterator.cpp
	g++ -o hash test_main.cpp

clean:
	rm -f hash
