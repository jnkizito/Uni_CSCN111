// Joseph. K
// 27/10/25

#include <iostream>
#include <string>
#include <algorithm> // for transform (lowercasing user input). Saw on stack overflow.

using namespace std;

enum Course {
    SSH_FOR_BEGINNERS,
    LINUX_SHELL_USAGE,
    ENVIRONMENT_VARIABLES,
    DAEMONS_AND_SERVICES,
    LINUX_NETWORKING_FOR_BEGINNERS,
    BASH_SCRIPTING_FOR_BEGINNERS,
    DOCKER_FOR_BEGINNERS,
    ADVANCED_LINUX_NETWORKING,
    ADVANCED_SSH,
    ADVANCED_BASH_SCRIPTING,
    DEFAULT
};

void displayCourses() {
    cout << "\n=== Joseph's Wacky Linux Centre ===\n";
    cout << "Available courses:\n";
    cout << "  - ssh for beginners\n";
    cout << "  - linux shell usage\n";
    cout << "  - environment variables\n";
    cout << "  - daemons and services\n";
    cout << "  - linux networking for beginners\n";
    cout << "  - bash scripting for beginners\n";
    cout << "  - docker for beginners\n";
    cout << "  - advanced linux networking\n";
    cout << "  - advanced ssh\n";
    cout << "  - advanced bash scripting\n";
    cout << "-----------------------------------\n";
    cout << "Type a course name exactly as shown (or 'quit' to exit).\n\n";
}


Course getCourseEnum(string userInput) {
    // make input lowercase for comparison
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

    if (userInput == "ssh for beginners") return SSH_FOR_BEGINNERS;
    else if (userInput == "linux shell usage") return LINUX_SHELL_USAGE;
    else if (userInput == "environment variables") return ENVIRONMENT_VARIABLES;
    else if (userInput == "daemons and services") return DAEMONS_AND_SERVICES;
    else if (userInput == "linux networking for beginners") return LINUX_NETWORKING_FOR_BEGINNERS;
    else if (userInput == "bash scripting for beginners") return BASH_SCRIPTING_FOR_BEGINNERS;
    else if (userInput == "docker for beginners") return DOCKER_FOR_BEGINNERS;
    else if (userInput == "advanced linux networking") return ADVANCED_LINUX_NETWORKING;
    else if (userInput == "advanced ssh") return ADVANCED_SSH;
    else if (userInput == "advanced bash scripting") return ADVANCED_BASH_SCRIPTING;
    else return DEFAULT;
}

double getCoursePrice(Course course) {
    switch (course) {
        case SSH_FOR_BEGINNERS: return 4.0;
        case LINUX_SHELL_USAGE: return 5.0;
        case ENVIRONMENT_VARIABLES: return 3.0;
        case DAEMONS_AND_SERVICES: return 3.0;
        case LINUX_NETWORKING_FOR_BEGINNERS: return 4.0;
        case BASH_SCRIPTING_FOR_BEGINNERS: return 4.0;
        case DOCKER_FOR_BEGINNERS: return 4.0;
        case ADVANCED_LINUX_NETWORKING: return 6.0;
        case ADVANCED_SSH: return 6.0;
        case ADVANCED_BASH_SCRIPTING: return 6.0;
        case DEFAULT: default: return 0.0;
    }
}

int main() {
    bool running = true;

    while (running) {
        string userInput;
        displayCourses();

        cout << "Enter a course name (or type 'quit' to exit): ";
        getline(cin, userInput);

        if (userInput == "quit") {
            running = false;
            break;
        }

        Course userCourse = getCourseEnum(userInput);
        double price = getCoursePrice(userCourse);

        if (userCourse == DEFAULT)
            cout << "Invalid course. Try again.\n";
        else
            cout << "Price for " << userInput << " is $" << price << endl;
    }

    return 0;
}

