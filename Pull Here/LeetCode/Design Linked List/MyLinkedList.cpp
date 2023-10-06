struct Node {
    Node(int value, Node* next = nullptr) : value(value), next(next) {}
    int value;
	Node* next;
};

class MyLinkedList {
public:
    MyLinkedList() = default;
    MyLinkedList(const MyLinkedList&) = delete;
    MyLinkedList(MyLinkedList&&) = delete;

    int get(int index) {
        Node* cur = head;
        if (index >= size || index < 0) return -1;
        while (index--)
            cur = cur->next;

        return cur->value;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size || index < 0) return;
        Node** pcur = &head;
        while (index--)
            pcur = &((*pcur)->next);

        Node* new_node = new Node(val, *pcur);
        *pcur = new_node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        Node** pcur = &head;
        while (index--)
            pcur = &((*pcur)->next);

        Node* tmp = *pcur;
        *pcur = (*pcur)->next;
        delete tmp;
        size--;
    }
    
    ~MyLinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        } 
    }

private:
    Node* head = nullptr;
    int size = 0;
};