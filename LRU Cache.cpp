/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/
class LRUCache {
  public:
    unordered_map<int, list<pair<int, int>>::iterator> reference_map; 
    list<pair<int, int>> cache;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
    }
    
    int get(int key) {
        if(reference_map.find(key)==reference_map.end()){
            return-1;
        }
        int temp=reference_map[key]->second;
        cache.erase(reference_map[key]);
        cache.push_front({key,temp});
        reference_map[key]=cache.begin();
        return temp;
    }
    
    void put(int key, int value){
        if(reference_map.find(key)!=reference_map.end()){
            cache.erase(reference_map[key]);
            cache.push_front({key,value});
            reference_map[key]=cache.begin();
        }
        else{
            if(cache.size()<capacity){
                cache.push_front({key,value});
                reference_map[key]=cache.begin();
            }
            else{
                int evict=cache.back().first;
                reference_map.erase(evict);
                cache.pop_back();
                cache.push_front({key,value});
                reference_map[key]=cache.begin();
            }
        }
    }  
};
