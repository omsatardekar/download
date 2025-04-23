#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

using namespace std;

void usePipe() {
    int pipe1[2]; // Parent to Child
    int pipe2[2]; // Child to Parent

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        cerr << "Pipe creation failed." << endl;
        return;
    }

    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Fork failed." << endl;
        return;
    }

    if (pid == 0) {
        // Child Process
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2

        char buffer[100];
        read(pipe1[0], buffer, sizeof(buffer)); // Read message from parent
        cout << "Child received: " << buffer << endl;

        string reply = "Hello from Child!";
        write(pipe2[1], reply.c_str(), reply.length() + 1); // Send reply to parent

        close(pipe1[0]);
        close(pipe2[1]);
    } else {
        // Parent Process
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2

        string message = "Hello from Parent!";
        write(pipe1[1], message.c_str(), message.length() + 1); // Send message to child

        char buffer[100];
        read(pipe2[0], buffer, sizeof(buffer)); // Read reply from child
        cout << "Parent received: " << buffer << endl;

        close(pipe1[1]);
        close(pipe2[0]);

        wait(NULL); // Wait for child to finish
    }
}


// Function to simulate I/O redirection
void useRedirection() {
    int inFD = open("input.txt", O_RDONLY);
    int outFD = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (inFD < 0 || outFD < 0) {
        cerr << "Error opening files." << endl;
        return;
    }

    // Redirect stdin and stdout
    dup2(inFD, STDIN_FILENO);
    dup2(outFD, STDOUT_FILENO);

    int n1, n2;
    cin >> n1 >> n2;

    if (n2 == 0) {
        cout << "Error: Division by zero not allowed." << endl;
    } else {
        int result = n1 / n2;
        cout << "Result of " << n1 << " / " << n2 << " = " << result << endl;
    }

    close(inFD);
    close(outFD);
}

int main() {
    int choice;

    cout << "Menu:\n";
    cout << "1. Two-Way Pipe Communication\n";
    cout << "2. Input/Output Redirection using dup2\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
        usePipe();
    else if (choice == 2)
        useRedirection();
    else
        cout << "Invalid choice!" << endl;

    return 0;
}
