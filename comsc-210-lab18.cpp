// COMSC-210 | Lab 18 | Ahmad Dharhan

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <iomanip>

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

    void display();
    void prepend(string movie, double rating){
        Node * newRating = new Node;

        

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

            prepend(tempMovie, tempRating);
            
        }
    }
    
    file.close();

    return 0;
}

double generateRating() {return (rand() % 41 + 10) / 10.0;};