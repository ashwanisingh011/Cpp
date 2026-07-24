#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}




// Inserting before the head of the DLL
Node* InsertBeforeHead(Node* head, int data){
    Node* temp = new Node(data, head, nullptr);
    head->back = temp;
    return temp;
}

// Inserting before the tail of the DLL
Node* InsertBeforeTail(Node* head, int data){
    if(head->next == nullptr){
        return InsertBeforeHead(head, data);
    }
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(data, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int data){
    if(k == 1){
        return InsertBeforeHead(head, data);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(data, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void print(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;  
    }
}


int main() {
    vector<int> arr = {10, 15, 20, 25};
    Node* head = convertArr2DLL(arr);
    head = InsertBeforeHead(head, 5);
    head = InsertBeforeTail(head, 30);
    head = insertBeforeKthElement(head, 3, 18);
    print(head); 

    return 0;
}

