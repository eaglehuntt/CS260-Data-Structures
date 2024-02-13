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
        void remove(int index);
        void insert(int index, int value);
        void update(int index, int value);
        void peek(int index);
        int get_size();
        Node* get_head();
        Node* get_tail();
};