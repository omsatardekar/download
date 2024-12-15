#include <iostream> 
using namespace std; 
 
struct Node { 
    int roll; 
    Node* next; 
}; 
 
class Info { 
    Node *headVanila = nullptr, *headButterscotch = nullptr, *headAll = nullptr; 
 
public: 
    void addStudent(int roll, Node*& head); 
    void displayList(Node* head); 
    void allStudents(); 
    void vanila(); 
    void butterscotch(); 
    void bothLikes(); 
    void onlyVanila(); 
    void onlyButterscotch(); 
    void neitherLikes(); 
}; 
 
void Info::addStudent(int roll, Node*& head) { 
    Node* newNode = new Node; 
    newNode->roll = roll; 
    newNode->next = nullptr; 
 
    if (!head) { 
        head = newNode; 
    } else { 
        Node* temp = head; 
        while (temp->next) { 
            temp = temp->next; 
        } 
        temp->next = newNode; 
    } 
} 
 
void Info::displayList(Node* head) { 
    Node* temp = head; 
    while (temp) { 
        cout << temp->roll << " "; 
        temp = temp->next; 
    } 
    cout << endl; 
} 
 
void Info::allStudents() { 
    int n, roll; 
    cout << "Enter number of students: "; 
    cin >> n; 
 
    cout << "Enter roll numbers of all students:\n"; 
    for (int i = 0; i < n; ++i) { 
        cin >> roll; 
        addStudent(roll, headAll); 
    } 
 
    cout << "All students: "; 
    displayList(headAll); 
} 
 
void Info::vanila() { 
    int n, roll; 
    cout << "Enter number of students who like vanilla: "; 
    cin >> n; 
 
    cout << "Enter roll numbers of students who like vanilla:\n"; 
    for (int i = 0; i < n; ++i) { 
        cin >> roll; 
        addStudent(roll, headVanila); 
    } 
 
    cout << "Students who like vanilla: "; 
    displayList(headVanila); 
} 
 
void Info::butterscotch() { 
    int n, roll; 
    cout << "Enter number of students who like butterscotch: "; 
    cin >> n; 
 
    cout << "Enter roll numbers of students who like butterscotch:\n"; 
    for (int i = 0; i < n; ++i) { 
        cin >> roll; 
        addStudent(roll, headButterscotch); 
    } 
 
    cout << "Students who like butterscotch: "; 
    displayList(headButterscotch); 
} 
 
void Info::bothLikes() { 
    cout << "Students who like both vanilla and butterscotch: "; 
    Node* tempVanila = headVanila; 
    while (tempVanila) { 
        Node* tempButterscotch = headButterscotch; 
        while (tempButterscotch) { 
            if (tempVanila->roll == tempButterscotch->roll) { 
                cout << tempVanila->roll << " "; 
            } 
            tempButterscotch = tempButterscotch->next; 
        } 
        tempVanila = tempVanila->next; 
    } 
    cout << endl; 
} 
 
void Info::onlyVanila() { 
    cout << "Students who like only vanilla: "; 
    Node* tempVanila = headVanila; 
    while (tempVanila) { 
        Node* tempButterscotch = headButterscotch; 
        bool found = false; 
        while (tempButterscotch) { 
            if (tempVanila->roll == tempButterscotch->roll) { 
                found = true; 
                break; 
            } 
            tempButterscotch = tempButterscotch->next; 
        } 
        if (!found) { 
            cout << tempVanila->roll << " "; 
        } 
        tempVanila = tempVanila->next; 
    } 
    cout << endl; 
} 
 
void Info::onlyButterscotch() { 
    cout << "Students who like only butterscotch: "; 
    Node* tempButterscotch = headButterscotch; 
    while (tempButterscotch) { 
        Node* tempVanila = headVanila; 
        bool found = false; 
        while (tempVanila) { 
            if (tempButterscotch->roll == tempVanila->roll) { 
                found = true; 
                break; 
            } 
            tempVanila = tempVanila->next; 
        } 
        if (!found) { 
            cout << tempButterscotch->roll << " "; 
        } 
        tempButterscotch = tempButterscotch->next; 
    } 
    cout << endl; 
} 
 
void Info::neitherLikes() { 
    cout << "Students who like neither vanilla nor butterscotch: "; 
    Node* tempAll = headAll; 
    while (tempAll) { 
        bool found = false; 
        Node* tempVanila = headVanila; 
        while (tempVanila) { 
            if (tempAll->roll == tempVanila->roll) { 
                found = true; 
                break; 
            } 
            tempVanila = tempVanila->next; 
        } 
 
        Node* tempButterscotch = headButterscotch; 
        while (tempButterscotch) { 
            if (tempAll->roll == tempButterscotch->roll) { 
                found = true; 
                break; 
            } 
            tempButterscotch = tempButterscotch->next; 
        } 
 
        if (!found) { 
            cout << tempAll->roll << " "; 
        } 
        tempAll = tempAll->next; 
    } 
    cout << endl; 
} 
 
int main() { 
    Info info; 
    int choice; 
    char cont; 
 
    do { 
        cout << "\n1. Enter all students' roll numbers\n"; 
        cout << "2. Enter students who like vanilla\n"; 
        cout << "3. Enter students who like butterscotch\n"; 
        cout << "4. Display students who like both vanilla and butterscotch\n"; 
        cout << "5. Display students who like only vanilla\n"; 
        cout << "6. Display students who like only butterscotch\n"; 
        cout << "7. Display students who like neither vanilla nor butterscotch\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: info.allStudents(); break; 
            case 2: info.vanila(); break; 
            case 3: info.butterscotch(); break; 
            case 4: info.bothLikes(); break; 
            case 5: info.onlyVanila(); break; 
            case 6: info.onlyButterscotch(); break; 
            case 7: info.neitherLikes(); break; 
            default: cout << "Invalid choice!" << endl; 
        } 
 
        cout << "Do you want to continue (y/n)? "; 
        cin >> cont; 
    } while (cont == 'y' || cont == 'Y'); 
 
    return 0; 
} 