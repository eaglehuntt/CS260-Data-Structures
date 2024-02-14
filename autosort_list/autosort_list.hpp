#include "../node.hpp"

class AutosortList {
    private:
        int size;
        Node *head;
        Node *tail;
        void set_head(Node *new_head);
        void set_tail(Node *new_tail);

    public:
        AutosortList();
        void push(int value);
        void pop();
        int get_value_at_index(int index);
        int get_size();
        Node* get_head();
        Node* get_tail();
        void print();
};