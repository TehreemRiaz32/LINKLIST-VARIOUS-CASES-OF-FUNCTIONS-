#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void printEvenNodes() {
        Node* S = head;
        int index = 1;
        while (S != NULL) {
            if (index % 2 == 0) {
                cout << S->data << " ";
            }
            S = S->next;
            index++;
        }
        cout << endl;
    }

    void swapNodes(int data1, int data2) {
        Node* S1 = head;
        Node* node1 = NULL;
        Node* node2 = NULL;

        while (S1 != NULL) {
            if (S1->data == data1) {
                node1 = S1;
            }
            else if (S1->data == data2) {
                node2 = S1;
            }

            if (node1 != NULL && node2 != NULL) {
                int t = node1->data;
                node1->data = node2->data;
                node2->data = t;
                break;
            }

            S1 = S1->next;
        }
    }


    void deleteFirstHalf() {
        int count = 0;
        Node* S2 = head;
        while (S2 != NULL) {
            count++;
            S2 = S2->next;
        }

        int nodesToDelete = count / 2;

        S2 = head;

     
        for (int i = 0; i < nodesToDelete; i++) {
            Node* temp = S2;
            S2 = S2->next;
            delete temp;
        }

        head = S2; 
    }

    void insert_at_start(int value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
    }

    void display() {
        Node* d = head;
        while (d != NULL) {
            cout << d->data << " ";
            d = d->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insert_at_start(10);
    list.insert_at_start(20);
    list.insert_at_start(30);
    list.insert_at_start(40);
    list.insert_at_start(50);
    list.insert_at_start(60);

    cout << "LINK LIST : ";
    list.display();

    cout << "EVEN NODE : ";
    list.printEvenNodes();

    list.swapNodes(20, 50);
    cout << "Link List after swapping 20 and 50: ";
    list.display();

    list.deleteFirstHalf();
    cout << "Link List after deleting the first half: ";
    list.display();

    return 0;
}
