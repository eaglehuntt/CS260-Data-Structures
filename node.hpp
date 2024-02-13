#pragma once

class Node {
    private:
        int index;
        int value;
        Node *next;
        Node *previous;

        void set_value(int new_value);

        bool is_valid_value(int value);

    public:
        Node();
        Node(int new_value);

        void set_id(int new_id);
        void new_value(int new_value);
        void set_next(Node* new_next);
        void set_previous(Node* new_prev);

        // Wrapper methods for set_next & set_previous
        void set_right(Node* new_right);
        void set_left(Node* new_left);

        int get_value();
        Node* get_next();
        Node* get_previous();
};