/*
 * Top Interview 150 - 012 / 150
 * Problem: 380. Insert Delete GetRandom O(1)
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: HashMap + Vector (O(1))
 */
class RandomizedSet {
private:
    unordered_map<int, size_t> umap;
    vector<int> vec;
    mt19937 rng{random_device{}()};
public:
    RandomizedSet() {
        vec.reserve(1000);
        umap.reserve(1000);
    }
    
    bool insert(int val) {
        if(umap.contains(val)) return false;
        umap[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        //if(!umap.contains(val)) return false;
        auto it = umap.find(val);
        if(it == umap.end()) return false;
        size_t posi = it->second;
        umap[vec.back()] = posi;
        std::swap(vec[posi], vec.back());
        vec.pop_back();
        umap.erase(it);
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<int> dist(0, vec.size()-1);
        return vec[dist(rng)];
        //return vec[rand()%vec.size()];
    }
};