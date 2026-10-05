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

        cout << "Memory deallocated" << endl;
    }

    void()

    void display(){

        cout << title << endl;
        int count = 0;
        double total = 0;
        Node * current = head;

        while(current != nullptr){
            
            cout << "Review #" << count + 1;
            cout << current->rating << current->review << endl;

            total += current->rating;

            current = current->next;
            count++;
        }

        cout << "Average: " << total / count;
    }

    void prepend(string newReview, double newRating){
        Node * newNode = new Node;

        newNode->rating = newRating;
        newNode->review = newReview;

        newNode->next = head;

        head = newNode;

    }

};

double generateRating();

int main(){

    srand(time(0));

    vector<Movie> movies;

    ifstream file("input.txt");

    if(!file.is_open()){
        cout << "Error! File could not be opened!" << endl;
        return 1;
    }

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

    for(int i = 0; i < SIZE; i++){
        movies[i].display();
        cout << endl;
    }

    return 0;
}

double generateRating() {return (rand() % 41 + 10) / 10.0;};