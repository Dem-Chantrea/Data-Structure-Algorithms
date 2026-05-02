/*
 * Simple Undo/Redo System using Doubly Linked List
 */
#include <iostream>
using namespace std;

struct State {
    string text;
    State* next;
    State* prev;
};

void add(State*& current, string text) {
    State* newState = new State{text, NULL, NULL};

    if (!current) {
        current = newState;
        return;
    }

    current->next = newState;
    newState->prev = current;
    current = newState;
}

void undo(State*& current) {
    if (current && current->prev) {
        current = current->prev;
        cout << "Undo: " << current->text << endl;
    }
}

void redo(State*& current) {
    if (current && current->next) {
        current = current->next;
        cout << "Redo: " << current->text << endl;
    }
}

int main() {
    State* current = NULL;

    add(current, "A");
    add(current, "AB");
    add(current, "ABC");

    undo(current);
    redo(current);
}
