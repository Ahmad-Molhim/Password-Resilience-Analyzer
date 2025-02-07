// Function to print the menu and get user choice
int print_menu() {
    int choice = 0;

    printf("\nPassword Resilience Analyzer\n");
    printf("1. Test a new password\n");
    printf("2. View strength of the last tested password\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

// Functions to check password characteristics
int hasLowercase(char password[]) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

int hasUppercase(char password[]) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

int hasDigit(char password[]) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int hasSpecialChar(char password[]) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalpha(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to evaluate password strength
char* evaluateStrength(char password[]) {
    int score = 0;

    score += hasLowercase(password);
    score += hasUppercase(password);
    score += hasDigit(password);
    score += hasSpecialChar(password);

    if (strlen(password) >= 12) {
        score++;
    }

    if (score == 5) {
        return "Strong";
    } else if (score >= 3) {
        return "Moderate";
    } else {
        return "Weak";
    }
}

int main() {
    char password[101];
    char previous_strength[8];
    int choice = 0;

    // Main program loop
    while (choice != 3) {
        choice = print_menu();

        if (choice == 1) {
            // Option to test a new password
            printf("Enter the password: ");
            scanf("%s", password);

            if (strlen(password) >= 8) {
                printf("Password Strength: ");
                strcpy(previous_strength, evaluateStrength(password));
                printf("%s\n", previous_strength);
            } else {
                printf("Error: Password should be at least 8 characters long.\n");
            }
        } else if (choice == 2) {
            // Option to view the strength of the last tested password
            printf("Last tested password strength: ");
            printf("%s\n", previous_strength);
        } else if (choice == 3) {
            // Option to exit
            printf("Exiting...\n");
        } else {
            // Handling invalid choices
            printf("Choice invalid. Choose 1, 2, or 3\n");
        }
    }

    return 0;
}