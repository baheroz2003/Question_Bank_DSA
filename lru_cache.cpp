class LRUCache {
public:
    list<int> dll;
    unordered_map<int,pair<int,list<int>::iterator>> cache;
    int n;
    LRUCache(int capacity){n=capacity;}
    int get(int key){
        if(cache.find(key)==cache.end())return -1;
        dll.erase(cache[key].second);
        dll.push_front(key);
        cache[key].second=dll.begin();
        return cache[key].first;
    }
    void put(int key,int value){
        if(cache.find(key)!=cache.end())dll.erase(cache[key].second);
        else if(dll.size()==n){
            int lru=dll.back();
            dll.pop_back();
            cache.erase(lru);
        }
        dll.push_front(key);
        cache[key]={value,dll.begin()};
    }
};
