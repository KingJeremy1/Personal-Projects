#include <iostream>
#include "musicList.h"

using namespace std;

void displayMenu() {
    cout << "\nMusic List Menu:" << endl;
    cout << "1. Add Music" << endl;
    cout << "2. Delete Music" << endl;
    cout << "3. Show All Music" << endl;
    cout << "4. Edit Music" << endl;
    cout << "5. Find Music" << endl;
    cout << "0. Quit" << endl;
}

int main() {
    musicList list1;
    int choice;
    string artist; 
    string name;  
    double duration;
    int rating;


    list1.addMusic("The Weeknd","Rolling Stone",10,3.4);
    list1.addMusic("The Weeknd", "The Birds PT.2",10,2.89);
    list1.addMusic("The Weeknd","House of Balloons",10,3.5);
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
    
        switch (choice) {
            case 1:
                cout << "Enter Artist name: ";
                getline(cin, artist);
                
                cout << "Enter song name: ";
                getline(cin, name);

                cout << "Enter song rating: ";
                cin >> rating;

                cout << "Enter song duration: ";
                cin >> duration;
                cin.ignore();

                list1.addMusic(artist, name, rating, duration);
                break;

            case 2: // Delete
                cout << "Enter the song name to delete: ";
                getline(cin, name);
                list1.deleteMusic(name);
                break;

            case 3: // Show all
                list1.displayMusic();
                break;

            case 4: 
                cout << "Enter the song name to edit: ";
                getline(cin, name);
                list1.editMusic(name,rating);
                break;

            case 5: // Find
                cout << "Enter the song name to find: ";
                getline(cin, name);
                list1.findMusic(name);
                break;

            case 0:
                cout << "Thank you, goodbye!" << endl;
                break;

            default:
                cout << "Wrong choice! Select 0-5." << endl;
        }
    } while (choice != 0);

    return 0;
}
