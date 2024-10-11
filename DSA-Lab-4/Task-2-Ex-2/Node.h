#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    void set_data(int);
    int get_data() const;
    void set_next(Node*);
    Node* get_next() const;

private:
    int data;
    Node* next;
};

#endif // NODE_H
