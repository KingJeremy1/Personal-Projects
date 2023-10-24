#ifndef S_LinkedListType
#define S_LinkedListType
   
#include <iostream>
#include <cassert>
 
using namespace std;

#include <iostream>
#include <string>
#include "linkedList.h"

using namespace std;

// A Music structure
struct Music {
    string artist;
    string name;
    int rating;
    double duration;
};

// A linked list type for Music records
class musicList : public linkedListType<Music> {

 // Member function to add a new Music to the list

    public:

        void addMusic(const string&artist, string name, int rating, double duration) {
        Music song;
        song.artist = artist;
        song.name = name;
        song.rating =  rating;
        song.duration = duration;
        insertLast(song);
    }
        // after this is my code that i wrote so it might get messy//
       
       void deleteMusic(string songName) {
        nodeType<Music>* current = first;
        nodeType<Music>* previous = nullptr;

          while (current != nullptr) {
              if (current->info.name == songName) {
            if (previous) {
                previous->link = current->link;
            } else {
                first = current->link;
            }
            
            nodeType<Music>* toDelete = current;
            current = current->link;
            delete toDelete;
        } else {
            previous = current;
            current = current->link;
        }
    }  }
        void findMusic(const string& songName){
            nodeType<Music>* current = first;

            while (current != nullptr){
                if (current->info.name == songName) {
                    cout << "Artist: " << current->info.artist <<endl;
                    cout << "Name: " << current->info.name <<endl;
                    cout << "Rating:" << current->info.rating <<endl;
                    cout << "Duration: " << current->info.duration <<endl;
                    cout << endl;
                    return; 
                }

                cout <<"Song with the name " << songName << " not found in the list." << endl;
            }

        }
        void showAllMusic(const string& songName){
        nodeType<Music>* current = first;

        while (current != nullptr){
            cout << "Artist" << current->info.artist << endl;
            cout << "Name" << current->info.name <<endl;
            cout << "Rating" << current->info.rating <<endl;
            cout << "Duration" << current->info.duration <<endl;
            cout << "--------------"<<endl;
        
            current = current ->link; 
        }

    }
        void editMusic(string songName, int newRating){
            nodeType<Music>* current = first; 

    

               /* cout << "Enter new artist (press enter to skip): ";
                getline(cin, newArtist);
                if (!newArtist.empty()) {
                    current->info.artist = newArtist;
                }

                cout << "Enter new song name (press enter to skip): ";
                getline(cin, newName);
                if (!newName.empty()){
                    current->info.artist = newArtist;
                }

                cout << "Enter new rating (enter -1 to skip): ";
                cin >> newDuration;
                if (newDuration != -1){
                    current ->info.duration = newDuration;
                }
                */
                cout << "Enter new rating (enter -1 to skip): "; 
                cin >> newRating;
                while (current->info.name != songName)

         current = current ->link;

                    current -> info.rating = newRating;
                     
                 cout << endl;
                
                
              
                
       }



// THIS THE code before i changed it 


        void displayMusic() {
        nodeType<Music>* current = first;
        while (current != nullptr) {
            cout << "Artist: " << current->info.artist << endl;
            cout << "Name: " << current->info.name << endl;
            cout << "rating: " << current->info.rating << endl;
            cout << "duration: " << current->info.duration << endl;
            cout << endl;
            current = current->link;
        }
    }
    };
    
    
		// Other member functions will be here also



#endif
