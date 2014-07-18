#include <iosteam>
#include "hash_map.h"

using namespace std;

size_t hash_map::hash (const Key& key);

iterator hash_map::begin(){
	/*Returns an iterator for the container ct that
	 points to the first data item in ct*/
}

iterator hash_map::end(){
	/*It is a flag and does NOT return the last element*/

}

                size_t size();

                iterator insert (const Key& key, const Value& value);

                void erase (Iterator pos);

                iterator find (const Key& key);

                Value operator[] (const Key& key);
