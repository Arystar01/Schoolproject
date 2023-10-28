#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a user
struct User {
    char username[50];
    char password[50];
    struct User* next;
};

// Global variable to keep track of the currently logged-in user
struct User* currentUser = NULL;

// Function to add a user to the linked list
struct User* addUser(struct User* head, char username[], char password[]) {
    struct User* newUser = (struct User*)malloc(sizeof(struct User));
    if (newUser == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->next = head;

    return newUser;
}

// Function to find a user by username
struct User* findUser(struct User* head, char username[]) {
    struct User* current = head;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // User not found
}

// Function to log out the currently logged-in user
void logOut() {
    currentUser = NULL;
}

int main() {
    struct User* userList = NULL;

    // Add a superuser
    userList = addUser(userList, "superuser", "password123");

    int choice;
    char username[50];
    char password[50];

    do {
        printf("1. Login as a user\n");
        printf("2. Add a new user (Superuser authentication required)\n");
        printf("3. Log Out\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (currentUser == NULL) {
                    printf("Enter your username: ");
                    scanf("%s", username);
                    printf("Enter your password: ");
                    scanf("%s", password);

                    struct User* user = findUser(userList, username);
                    if (user != NULL && strcmp(user->password, password) == 0) {
                        printf("Login successful for user: %s\n", username);
                        currentUser = user;
                    } else {
                        if (strcmp(username, "superuser") == 0 && strcmp(password, "password123") == 0) {
                            printf("Login successful as superuser.\n");
                            currentUser = user;
                        } else {
                            printf("Login failed. Invalid username or password.\n");
                        }
                    }
                } else {
                    printf("You are already logged in as %s. Log out to log in as a different user.\n", currentUser->username);
                }
                break;
            case 2:
                if (currentUser != NULL && strcmp(currentUser->username, "superuser") == 0) {
                    printf("Enter the username for the new user: ");
                    scanf("%s", username);
                    printf("Enter the password for the new user: ");
                    scanf("%s", password);
                    userList = addUser(userList, username, password);
                    printf("New user %s added.\n", username);
                } else {
                    printf("Superuser authentication required to add a new user.\n");
                }
                break;
            case 3:
                if (currentUser != NULL) {
                    printf("Logging out %s.\n", currentUser->username);
                    logOut();
                } else {
                    printf("You are not logged in. Log in to use this option.\n");
                }
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    // Free the allocated memory
    while (userList != NULL) {
        struct User* temp = userList;
        userList = userList->next;
        free(temp);
    }

    return 0;
}