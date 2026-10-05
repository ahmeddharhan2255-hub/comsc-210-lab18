// COMSC-210 | Lab 18 | Ahmad Dharhan

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 4;

string movieList[SIZE] = {"Lord Of the Rings","The Godfather","Star Wars","Jurassic Park"};

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
    Movie(string movieName){
        title = movieName; 
        head = nullptr;
    };

    ~Movie(){

        while(head != nullptr){
            Node *temp = head;
            head = head->next;
            delete temp;
        }

    }

    Movie(const Movie& otherfilm){
        title = otherfilm.title;
        head = nullptr;

        Node* tail = nullptr;
        Node* current = otherfilm.head;

        while(current != nullptr){

            Node * newNode = new Node;

            newNode->rating = current->rating;
            newNode->review = current->review;
            newNode->next = nullptr;

            if(head == nullptr){
                head = newNode;
            }

            else{
                tail->next = newNode;
            }

            tail = newNode;

            current = current->next;
            
        }

}
    Movie& operator=(const Movie& othermovie){

        if(this == &othermovie){
            return *this;
        }

        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        title = othermovie.title;
        head = nullptr;

        Node* current = othermovie.head;
        Node* tail = nullptr;

        while(current != nullptr){

            Node * newNode = new Node;

            newNode->rating = current->rating;
            newNode->review = current->review;
            newNode->next = nullptr;

            if(head==nullptr){
                head = newNode;
            }
            else{
                tail->next = newNode;
            }

            tail = newNode;

            current = current -> next;
        }

        return *this;
    }   

    //display function which shows linked lists and nodes 
    //arguments: none
    //returns nothing
    void display(){

        cout << title << endl;
        int count = 0;
        double total = 0;
        Node * current = head;

        while(current != nullptr){
            
            cout << "Review #" << count + 1;
            cout << " " << current->rating << " " << current->review << endl;

            total += current->rating;

            current = current->next;
            count++;
        }

        cout << "Average: " << total / count;

        cout << endl;

    }

    //Function prepends a node into each linked list in vector
    //arguments(Review and Rating)
    //Returns nothing
    void prepend(string newReview, double newRating){
        Node * newNode = new Node;

        newNode->rating = newRating;
        newNode->review = newReview;

        newNode->next = head;

        head = newNode;

    }

};

//Function Prototype
double generateRating();

int main(){

    srand(time(0));

    vector<Movie> movies;

    ifstream file("input.txt");

    if(!file.is_open()){
        cout << "Error! File could not be opened!" << endl;
        return 1;
    }

    //Goes through text file line by line and adds
    //reviews with respect to film
    for(int i = 0; i < SIZE; i++){

        movies.push_back(Movie(movieList[i]));

        for(int j = 0; j < SIZE - 1; j++){
            string tempMovie;
            double tempRating;

            getline(file,tempMovie);
            tempRating = generateRating();

            movies[i].prepend(tempMovie, tempRating);
        
        }
    }
    
    file.close();

    //Displays linked lists with respect to size
    for(int i = 0; i < SIZE; i++){
        movies[i].display();
        cout << endl;
    }

    return 0;
}

//Function: generateRating:
//arguments: none
//returns rand double between 1.0 and 5.0
double generateRating() {return (rand() % 41 + 10) / 10.0;};