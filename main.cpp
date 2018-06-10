//
//  main.cpp
//  Hash_Table
//
//  Created by Ruban Rengaraju on 6/9/18.
//  Copyright © 2018 Ruban Rengaraju. All rights reserved.
//

#include <iostream>
using namespace std;

int hash_func(int key){
    int x = key%100;
    return x;
}


class hashTable{
public:
    hashTable(){
        for(int i = 0; i<100; i++){
            array[i] = nullptr;
        }
    }
    
    void insert(int k, string v){
        int x = hash_func(k);
        node* p = array[x];
        node* n = new node;
        if(p == nullptr){
            array[x] = n;
            n->next = nullptr;
            n->key = k;
            n->value = v;
            cout<<v<<" was added to the table!"<< endl;
            return;
        }
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = n;
        n->next = nullptr;
        n->key = k;
        n->value = v;
        cout<<v<<" was added to the table!"<< endl;
        return;
    }
    
    void searchNode(int k, string v){
        int x = hash_func(k);
        node* p = array[x];
        if(p == nullptr){
            cout<<"Empty table"<< endl;
            return;
        }
        if(p->value == v && p->next == nullptr){
            cout<<v<<" was found!"<<endl;
            return;
        }
        while (p->value != v && p->next != nullptr) {
            p = p->next;
        }
        if(p->value == v){
            cout<<v<<" was found!"<<endl;
            return;
        }
        if(p->next == nullptr && p->value != v){
            cout<<v<<" couldn't be found"<<endl;
            return;
        }
        
    }
    
    void deleteNode(int k, string v){
        int x = hash_func(k);
        node* p = array[x];
        if(p==nullptr){
            cout<<"No nodes to delte!"<<endl;
            return;
        }
        
        if(p->value == v){
            array[x] = nullptr;
            delete p;
            cout<<v<<" was deleted!"<<endl;
            return;
        }
        while (p->next->next != nullptr && p->next->value != v) {
            p = p->next;
        }
        node* n = p->next;
        p->next = p->next->next;
        delete n;
        cout<<v<<" was deleted!"<<endl;
    }
    
private:
    struct node{
        node* next;
        int key;
        string value;
    };
    node* array[100];
    
    
    
};

int main() {
   
    
    
}
