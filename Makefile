

hash: test.cpp hash_map.h hash_map.cpp iterator.cpp
	g++ -o hash test.cpp

clean:
	rm -f hash
