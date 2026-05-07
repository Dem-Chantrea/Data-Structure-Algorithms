/*
 * Circular Doubly Linked List - Browser Navigator
 * Features:
 * - Visit page
 * - Next page
 * - Previous page
 * - Delete page
 * - Show all pages
 */
#include <iostream>
#include <string>
using namespace std;

// Node
struct Page {
    string url;
    Page* next;
    Page* prev;
};



// visit page (at end)
void visit(Page*& head, Page*& current, string url, bool moveToNew = true) {
    Page* newPage = new Page{url, NULL, NULL};

    if (!head) {
        head = newPage;
        head->next = head;
        head->prev = head;
        current = head;
        return;
    }

    Page* tail = head->prev;

    tail->next = newPage;
    newPage->prev = tail;
    newPage->next = head;
    head->prev = newPage;

    if (moveToNew) {
        current = newPage;
    }
}


void addMultiplePages(Page*& head, Page*& current) {
    string url;

    cout << "Enter URLs (type 'done' to finish):\n";

    while (true) {
        cout << "URL: ";
        getline(cin, url);

        if (url == "done") break;

        visit(head, current, url );
    }
}


// Next page
void nextPage(Page*& current) {
    if (!current) {
        cout << "No pages\n";
        return;
    }

    current = current->next;
	cout << current->url;
}

// Previous page
void prevPage(Page*& current) {
    if (!current) {
        cout << "No pages\n";
        return;
    }

    current = current->prev;
    cout << "Previous at: " << current->url << endl;
}

// Show all pages
void showAll(Page* head) {
    if (!head) {
        cout << "No pages\n";
        return;
    }

    Page* temp = head;
    cout << "\n?? All Pages:\n";

    do {
        cout << temp->url << endl;
        temp = temp->next;
    } while (temp != head);
}

// Show current page
void showCurrent(Page* current) {
    if (!current) {
        cout << "No current page\n";
        return;
    }

    cout << "Current Page: " << current->url << endl;
}

// Delete page
void deletePage(Page*& head, Page*& current, string url) {
    if (!head) return;

    Page* temp = head;

    do {
        if (temp->url == url) {

            // Only one node
            if (temp->next == head && temp->prev == head) {
                delete temp;
                head = NULL;
                current = NULL;
                return;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            // update head
            if (temp == head) {
                head = temp->next;
            }

            // update current
            if (temp == current) {
                current = temp->next;
            }

            delete temp;
            cout << "Deleted\n";
            return;
        }

        temp = temp->next;
    } while (temp != head);

    cout << "Page not found\n";
}

// Main
int main() {
    Page* head = NULL;
    Page* current = NULL;

    int choice;
    string url;

    do {
        cout << "\n===== PAGE NAVIGATOR (CDLL) =====\n";
        cout << "1. Add Multiple Pages\n";
		cout << "2. Visit Page\n";
		cout << "3. Next Page\n";
		cout << "4. Previous Page\n";
		cout << "5. Show Current\n";
		cout << "6. Show All Pages\n";
		cout << "7. Delete Page\n";
		cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
		    case 1:
		        addMultiplePages(head, current);
		        break;
		
		    case 2:
		        cout << "Enter URL: ";
		        getline(cin, url);
		        visit(head, current, url);
		        break;
		
		    case 3:
		        nextPage(current);
		        break;
		
		    case 4:
		        prevPage(current);
		        break;
		
		    case 5:
		        showCurrent(current);
		        break;
		
		    case 6:
		        showAll(head);
		        break;
		
		    case 7:
		        cout << "Enter URL to delete: ";
		        getline(cin, url);
		        deletePage(head, current, url);
		        break;
		
		    case 8:
		        cout << "Exit\n";
		        break;
		
		    default:
		        cout << "Invalid\n";
		}

    } while (choice != 8);

    return 0;
}
