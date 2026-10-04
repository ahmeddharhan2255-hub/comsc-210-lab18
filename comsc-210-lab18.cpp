// COMSC-210 | Lab 18 | Ahmad Dharhan

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const int SIZE = 4;

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
    Movie(){ 
        head = nullptr;
    }


    void display();
    void prepend();

    double rating()            {return (rand()  (5.0)) + 1.0;}
};

int main(){
    srand(time(0));

    vector<Movie> movies(SIZE);

    ifstream file("input.txt");

    if(!file.is_open()){
        cout << "Error! File could not be opened!" << endl;
        return 1;
    }

    for(int i = 0; i < SIZE; i++){

    }
    
    file.close();

    return 0;
}

