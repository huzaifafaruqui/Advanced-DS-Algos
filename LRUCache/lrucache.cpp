// Least recently used cache
// Problem description - https://leetcode.com/problems/lru-cache/#/description

#include <unordered_map>
#include <queue>
#include <utility>

struct node {
    // doubly linked list node
    int data;
    node *next = nullptr;
    node *prev = nullptr;
    node(int key) : data(key) {}
};

class Linked_list {

    node *front = nullptr, *rear = nullptr;

public:
    node* push_front(int key) {
        //push new node in front

        node *temp = new node(key);

        if (!rear) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            temp->prev = rear;
            rear = rear->next;
        }

        return rear;
    }

    node* pop_back() {
        // pop node from back

        node *temp = front;
        if (front)
        {
            front = front->next;
            if (!front)
                rear = nullptr;
            else
                front->prev = nullptr;
        }

        return temp;
    }

    void update(node *p) {
        // Moves node p to end

        if (p == rear) {
            // if p is already at end
            return;
        }

        if (p == front) {
            // if p is at front, update front
            front = p->next;
            front->prev = nullptr;
        }

        else {
            // remove p from middle of linked list
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }

        //add p to rear
        p->prev = rear;
        p->next = nullptr;
        rear->next = p;
        rear = rear->next;
    }

};


class LRUCache {
    // LRU Cache class
    // get(key) --> O(1)
    // put(key, value) --> O(1)

    Linked_list L;
    size_t cache_capacity;
    std::unordered_map<int, std::pair<int, node*>> cache;
public:
    LRUCache(int sz) : cache_capacity(sz) {}
    ~LRUCache() {
        cache.clear();
    }

    void put(int key, int value)
    {
        // count occurences of key in cache 
        int count_key = cache.count(key);

        node *temp;

        //key not in cache
        if (!count_key) {
            // insert new key into linked list
            temp = L.push_front(key);
        }

        else {
            // get position in linked list of existing key in cache
            temp = cache[key].second;
            // update position
            L.update(temp);
        }

        // insert into cache value & address of node in linked list
        cache[key] = { value, temp };

        // if cache is full, remove from front of linked list 
        if (cache.size() > cache_capacity)
        {
            node *elem = L.pop_back();
            //std::cout << elem->data;
            cache.erase(elem->data);

        }
    }

    int get(int key)
    {
        int count_key = cache.count(key);

        //key not in cache
        if (!count_key)
            return -1;

        //update position of key in linked list
        L.update(cache[key].second);

        return cache[key].first;
    }
};

int main()
{
    LRUCache cache(2);

    cache.put(1, 3);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4

}
