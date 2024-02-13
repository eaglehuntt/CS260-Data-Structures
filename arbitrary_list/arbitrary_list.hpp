#include "../node.hpp"

class ArbitraryList {
    private:
        int size;
        Node *head;
        Node *tail;
        void set_head(Node *new_head);
        void set_tail(Node *new_tail);

    public:
        ArbitraryList();
        void push(int value);
        void pop();
        void remove_at_index(int index);
        void insert_at_index(int index, int value);
        void update_value_at_index(int index, int value);
        int get_value_at_index(int index);
        int get_size();
        Node* get_head();
        Node* get_tail();
        void print();
};