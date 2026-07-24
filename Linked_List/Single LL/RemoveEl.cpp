#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* removeEl(Node* head, int el){
    if(head==NULL) return head;
    if(head->data==el){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
   
    Node* prev = NULL;
    Node* temp = head;
    while(temp!=NULL){
      
        if(temp->data==el){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

int main(){
    vector<int> arr = {5,8,12,9};
    Node* head = convertArr2LL(arr);
    head = removeEl(head, 8);
    print(head);
}