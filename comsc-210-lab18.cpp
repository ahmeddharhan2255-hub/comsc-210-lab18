// COMSC-210 | Lab 18 | Ahmad Dharhan

#include <iostream>
#include <string>
using namespace std;

class Node{
    int rating;
    string review;
};

class Movie {
private:
    string title;
    struct Node* next;

public:
    void display();
    void prepend();
};

int main(){


    return 0;
}