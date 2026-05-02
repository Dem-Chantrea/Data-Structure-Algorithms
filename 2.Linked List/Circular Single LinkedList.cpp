/*
 * Circular Linked List Music Player
 * Features:
 * - Add Song
 * - Play Next Song
 * - Delete Song
 * - Display Playlist
 */

#include <iostream>
#include <string>
using namespace std;

// Song Node
struct Song {
    string name;
    Song* next;
};

// Add song to playlist
void addSong(Song*& head, string songName) {
    Song* newSong = new Song{songName, NULL};

    if (head == NULL) {
        head = newSong;
        newSong->next = head;
        return;
    }

    Song* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newSong;
    newSong->next = head;
}

// Display playlist
void display(Song* head) {
    if (head == NULL) {
        cout << "Playlist is empty\n";
        return;
    }

    Song* temp = head;
    cout << "\n?? Playlist:\n";

    do {
        cout << "- " << temp->name << endl;
        temp = temp->next;
    } while (temp != head);
}

// Play songs (simulate next)
void play(Song*& current) {
    if (current == NULL) {
        cout << "No songs to play\n";
        return;
    }

    cout << "Now Playing: " << current->name << endl;
    current = current->next; // move to next song
}

// Delete a song
void deleteSong(Song*& head, string songName) {
    if (head == NULL) return;

    Song *curr = head, *prev = NULL;

    // delete head
    if (head->name == songName) {
        Song* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        if (head == head->next) {
            delete head;
            head = NULL;
            return;
        }

        temp->next = head->next;
        head = head->next;
        delete curr;
        return;
    }

    do {
        prev = curr;
        curr = curr->next;

        if (curr->name == songName) {
            prev->next = curr->next;
            delete curr;
            return;
        }

    } while (curr != head);
}

// Main
int main() {
    Song* head = NULL;
    Song* current = NULL;

    int choice;
    string songName;

    do {
        cout << "\n===== MUSIC PLAYER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Show Playlist\n";
        cout << "3. Play Song & Next \n";
        cout << "4. Delete Song\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clear buffer

        switch (choice) {
            case 1: {
			    int n;
			    cout << "How many songs do you want to add? ";
			    cin >> n;
			    cin.ignore(); // clear buffer
			
			    for (int i = 0; i < n; i++) {
			        cout << "Enter song name " << i + 1 << ": ";
			        getline(cin, songName);
			        addSong(head, songName);
			    }
			
			    if (current == NULL) current = head;
			    break;
}

            case 2:
                display(head);
                break;

            case 3:
                play(current);
                break;

            case 4:
                cout << "Enter song name to delete: ";
                getline(cin, songName);
                deleteSong(head, songName);
                break;

            case 5:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
