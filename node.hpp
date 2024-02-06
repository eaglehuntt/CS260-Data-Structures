
class Node {
    private:
        int id;
        int value;
        Node *next;
        Node *previous;

        void set_id(int new_id);
        void set_value(int new_value);

        bool is_valid_value(int value);

    public:
        Node();
        Node(int new_id, int new_value);

        void new_value(int new_value);
        void set_next(Node* new_next);
        void set_previous(Node* new_prev);

        int get_value();
};