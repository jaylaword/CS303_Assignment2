#include <cstddef> 

using namespace std;

// Template class for a single linked list
template <typename Item_Type>
class Single_Linked_List {
private:
    // Template class for a single linked list
    struct Node {
        Item_Type data;
        Node* next;
        // Constructor to initialize data and next pointer
        Node(const Item_Type& data_item, Node* next_ptr = nullptr) 
            : data(data_item), next(next_ptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List();
    ~Single_Linked_List();

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type& front();
    Item_Type& back();
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
};
