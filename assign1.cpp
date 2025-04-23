//main.cpp:
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>   // for getpid(), fork(), etc.
#include <sys/wait.h> // for wait()
#include <cstdlib>    // for exit()

using namespace std;

void performCp(const string& source, const string& dest) {
    ifstream srcFile(source);
    ofstream destFile(dest);

    if (!srcFile) {
        cerr << "Error opening source file!" << endl;
        exit(1);
    }

    if (!destFile) {
        cerr << "Error creating destination file!" << endl;
        exit(1);
    }

    string line;
    while (getline(srcFile, line)) {
        destFile << line << endl;
    }

    cout << "File copied successfully by process with PID: " << getpid() << endl;

    srcFile.close();
    destFile.close();
    exit(0);
}

void performGrep(const string& word, const string& filename) {
    char* args[] = {(char*)"./grep_logic", (char*)word.c_str(), (char*)filename.c_str(), NULL};
    
    /*
    char *args[] = {(char*)"grep", (char*)word.c_str(), (char*)filename.c_str(), NULL};
    cout << "Running grep using exec by process PID: " << getpid() << endl;
    execvp("grep", args);  // This will replace the current process
    */

    execvp(args[0], args); // Call exec() to replace the process with grep_logic
    perror("exec failed");  // In case exec fails
    exit(1);
}

int main() {
    int choice;
    cout << "Choose a command to simulate:\n1. cp\n2. grep\nEnter choice: ";
    cin >> choice;

    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        if (choice == 1) {
            string source, dest;
            cout << "Enter source file name: ";
            cin >> source;
            cout << "Enter destination file name: ";
            cin >> dest;
            performCp(source, dest);
        } else if (choice == 2) {
            string word, filename;
            cout << "Enter word to search: ";
            cin >> word;
            cout << "Enter filename to search in: ";
            cin >> filename;
            performGrep(word, filename);
        } else {
            cerr << "Invalid choice!" << endl;
            exit(1);
        }
    } else {
        // Parent process
        wait(NULL); // Wait for child to finish
        cout << "Parent process (PID: " << getpid() << ") finished waiting." << endl;
    }

    return 0;
}


//grep_logic.cpp:
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: ./grep_logic <word_to_search> <filename>" << endl;
        return 1;
    }

    string word = argv[1];
    string filename = argv[2];

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    string line;
    int line_count = 0;

    while (getline(file, line)) {
        line_count++;
        if (line.find(word) != string::npos) { // Check if word is in line
            cout << "Line " << line_count << ": " << line << endl;
        }
    }

    cout << "Search completed by process with PID: " << getpid() << endl;
    file.close();
    return 0;
}
