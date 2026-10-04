class MyHashSet {
private:
    static const int SIZE = 1009;
    vector<vector<int>> buckets;

    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        buckets.resize(SIZE);
    }

    void add(int key) {
        int index = hashFunction(key);

        for (int x : buckets[index]) {
            if (x == key)
                return;
        }

        buckets[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);

        for (auto it = buckets[index].begin();
             it != buckets[index].end();
             ++it) {

            if (*it == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int index = hashFunction(key);

        for (int x : buckets[index]) {
            if (x == key)
                return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */