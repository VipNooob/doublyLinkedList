#include <iostream>
using namespace std;


struct Node {
    Node* next;
    Node* prev;
    int data;

};

class DoublyLinkedList {
private:
    Node* head;

    int size;

public:
    DoublyLinkedList() {
        head = NULL;
        size = 0;
    }

    void add_front(int data) {
      
        Node* newNode = new Node;
        newNode->data = data;

        if (head == NULL) {
            newNode->prev = NULL;
            newNode->next = NULL;
            head = newNode;
        }
        else {
            // HEAD  --> [prev1|data1|next1] <--> .....
            // NULL <-- prev1
            // HEAD --> [prevNEW|dataNEW|nextNEW] <--> [prev1|data1|next1] <--> .....
            // NULL <-- prevNEW

            // NULL <-- prevNEW
            newNode->prev = NULL;
            // newNODE <-- prev1
            (head)->prev = newNode;
            // nextNew --> NODE1
            newNode->next = head;
            // HEAD --> newNODE
            head = newNode;
         
            
        }
        size++;

    }

    void insert_between(int pos, int data) {
        
        // pos > 1 ---> because zero position is the front insertion
        // if pos > size -> back insertion
        if (pos == 0) {
            add_front(data); return;
        }
        
        else if (pos <= size && pos > 1) {
            Node* temp = head;
            
            Node* newNode = new Node;
            newNode->data = data;

            for (int i = 1; i < pos; i++) {
                temp = temp->next;
            }
            newNode->prev = temp->prev;
            newNode->next = temp->prev->next;
            temp->prev->next = newNode;
            temp->prev = newNode;

        }
        else if (pos > size) {
            cout << "Position cannot be more then size of the list!\n"; return;
        }
        size++;

    }

    void add_back(int data) {

        if (head == NULL) {
            add_front(data); return;
        }

        Node* newNode = new Node;
        newNode->data = data;
        
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->next = NULL;
        temp->next = newNode;
        newNode->prev = temp;

        size++;

    }

    void del_front() {
        Node* newNode = new Node;
        newNode = head;

        head = newNode->next;
        newNode->next->prev = head;

        delete newNode;
        newNode = NULL;
        size--;
    }

    void del_between(int pos) {
        Node* temp = new Node;
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        temp = NULL;
        size--;
    }

    void del_back() {
        if (head != NULL) {
            Node* temp = new Node;
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
            temp = NULL;
        }
        else {
            cout << "List is empty!\n";
        }
    }

    void show() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << ' ';
            temp = temp->next;
        }

    }

};


int main()
{
    DoublyLinkedList List;
    
    List.add_back(1);
    List.add_back(2);
    
    cout << "After add to back: "; List.show(); cout << endl;

    List.add_front(0);
    List.add_front(-1);

    cout << "After add to front: "; List.show(); cout << endl;
    // 0|-1| 1| 2
    List.insert_between(2, 555);
    cout << "After add to the middle of the list: "; List.show(); cout << endl;
    List.insert_between(3, 777);
    cout << "After add to the middle of the list: "; List.show(); cout << endl;

    List.del_back();
    cout << "After deletion an element from  the back of the list: "; List.show(); cout << endl;

    List.del_between(2);
    cout << "After deletion the second element: "; List.show(); cout << endl;

    List.del_front();
    cout << "After deletion from the beginning of the list: "; List.show(); cout << endl;
}

