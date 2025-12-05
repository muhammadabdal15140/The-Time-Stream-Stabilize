#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct TimeCapsule {
    int year;
    string eventName;
    TimeCapsule* left;
    TimeCapsule* right;

    TimeCapsule(int y, string e) {
        year = y;
        eventName = e;
        left = right = nullptr;
    }
};

TimeCapsule* injectEvent(TimeCapsule* root, int year, string name) {
    if (root == nullptr) {
        cout << "> System: Injecting " << year << "... Timeline stable.\n";
        return new TimeCapsule(year, name);
    }

    if (year < root->year)
        root->left = injectEvent(root->left, year, name);
    else if (year > root->year)
        root->right = injectEvent(root->right, year, name);

    return root;
}

void searchEvent(TimeCapsule* root, int year) {
    cout << "\n> Query: Searching for " << year << "...\n";

    TimeCapsule* curr = root;
    while (curr != nullptr) {
        if (year == curr->year) {
            cout << "> Result: Event Found! [" << curr->year 
                 << ": " << curr->eventName << "]\n";
            return;
        }
        else if (year < curr->year)
            curr = curr->left;
        else
            curr = curr->right;
    }

    cout << "> Result: Year " << year << " not found in current timeline.\n";
}

TimeCapsule* findMin(TimeCapsule* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

TimeCapsule* deleteEvent(TimeCapsule* root, int year) {
    if (root == nullptr)
        return nullptr;

    if (year < root->year)
        root->left = deleteEvent(root->left, year);
    else if (year > root->year)
        root->right = deleteEvent(root->right, year);
    else {
        cout << "\n> Alert: Paradox detected at " << year << "!\n";
        cout << "> System: Year " << year << " removed. Timeline stabilized.\n";

        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr) {
            TimeCapsule* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TimeCapsule* temp = root->left;
            delete root;
            return temp;
        }
        else {
            TimeCapsule* succ = findMin(root->right);
            root->year = succ->year;
            root->eventName = succ->eventName;
            root->right = deleteEvent(root->right, succ->year);
        }
    }

    return root;
}

void report(TimeCapsule* root) {
    if (!root) return;
    report(root->left);
    cout << root->year << ": " << root->eventName << "\n";
    report(root->right);
}

int main() {
    TimeCapsule* root = nullptr;

    // ---------------- AUTOMATIC SAMPLE INPUT ----------------
    cout << "\n>>> Running Automatic Sample Test Case...\n\n";

    root = injectEvent(root, 2050, "Mars Colony Established");
    root = injectEvent(root, 1969, "Moon Landing");
    root = injectEvent(root, 2100, "Warp Drive Invented");
    root = injectEvent(root, 2000, "Y2K Bug");

    cout << "\n";

    searchEvent(root, 1969);

    cout << "\n";

    root = injectEvent(root, 1990, "World Wide Web");

    cout << "\n";

    root = deleteEvent(root, 2000);

    cout << "\n> COMMAND: CHRONOLOGICAL REPORT\n";
    cout << "-------------------------------\n";
    report(root);
    cout << "-------------------------------\n";

    cout << "\n";
    searchEvent(root, 2000);

    cout << "\n>>> End of Automatic Test.\n";

    return 0;
}
