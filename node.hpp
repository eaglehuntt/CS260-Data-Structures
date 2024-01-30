template<typename value_type> 

class Node {
    private:
        int id;
        value_type value;
        Node *next;
        Node *previous;

        void set_id();
        void set_next();
        void set_previous();

    public:
        void get_value();
};