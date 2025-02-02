#include<iostream>
using namespace std;

struct MYNODE{
    int data;
    MYNODE *next;
};

MYNODE *HEAD = NULL;

MYNODE* createNode(int v){
    MYNODE *NODE = new MYNODE();
    NODE->data = v;
    NODE->next = NULL;
    return NODE;
}

MYNODE* insert(int value, MYNODE *prev = NULL){
    MYNODE *NEWNODE = createNode(value);
    if (prev == NULL){// insert at head
        NEWNODE->next = HEAD;
        HEAD = NEWNODE;
    }
    else{// after a previous node
        NEWNODE->next = prev->next;
        prev->next = NEWNODE;
    }
    return NEWNODE;
}

void traverse(){
    MYNODE *curr = HEAD;
    while(curr){
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    cout<<endl;
}

MYNODE* searchElement(int v){
    //return address of the node
}
bool searchElement(int value, int key)
{
    MYNODE* curr = HEAD;

    while (curr != NULL)
    {
    if (curr->data == key) return true;
        curr = curr->next;
    }
    return false;
}

void deleteNode(int value, int key)
{
    MYNODE *temp = HEAD, *prev;

    if (temp != NULL && temp->data == key) {
    HEAD = temp->next;
    free(temp);
    return;
    }
    while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;

    free(temp);
}
void printList(MYNODE* node) {
  while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
  }
}


int main(){
    struct MYNODE *HEAD = NULL;
    MYNODE* curr = insert(3);
    curr =insert(5,curr);
    insert(9,curr);
    traverse();

    cout << "\nAfter deleting an element: ";
    deleteNode(5, 3);
    printList(HEAD);

    int item_to_find = 3;
    if (searchElement(3, item_to_find)) {
    cout << endl << item_to_find << " is found";
    }
    else {
    cout << endl << item_to_find << " is not found";
    }
}
