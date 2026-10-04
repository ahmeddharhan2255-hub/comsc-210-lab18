// COMSC-210 | Lab 18 | Ahmad Dharhan

#include <iostream>
#include <string>
using namespace std;

struct Node{
    double rating;
    string review;
    Node* next;
};

class Movie {
private:
    string title;
    Node* head;

public:
    void display();
    void prepend();
};

int main(){


    return 0;
}

