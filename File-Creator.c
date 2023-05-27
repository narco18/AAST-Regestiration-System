#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 100
#define MAX_NAME_LENGTH 100

int main() {
    char courseNames[MAX_COURSES][MAX_NAME_LENGTH] = {
        // semester 1
        "BA003-Math-0",
        "BA101-Calculus-1",
        "BA113-Physics",
        "CS111-Introduction-to-Computers",
        "IS171-Introduction-to-Information-systems",
        "LH135-English-for-Specific-Purposes-I(ESP-I)",
        "NC172-Fundamentals-of-Business",
        // semester 2
        "BA102-Calculus-2",
        "CS143-Introduction-to-Problem-Solving-and-Programming",
        "EC134-Fundamentals-of-Electronics",
        "LH136-English-for-Specific-Purposes-II(ESP-II)",
        "NC133-Communication-Skills",
        // semester 3
        "BA201-Calculus-III",
        "BA203-Probability-and-Statistics",
        "BA216-Advanced-Physics",
        "CE216-Digital-Logic-Design",
        "CS202-Discrete-Structures",
        "CS243-Object-Oriented-Programming",
        // semester 4
        "Introduction-to-Networks",
        "CE243-Intro.-to-Computer-Architecture",
        "CS212-Data-Structures-and-Algorithms",
        "CS24-Advanced-Programming-Applications",
        "IS273-Database-Systems",
        "IT291-Professional-Training-in-Entrepreneurship",
        "SE291-Introduction-to-Software-Engineering",
        // semester 5
        "BA301-Advanced-Statistics",
        "BA304-Linear-Algebra",
        "CS311-Theory-of-Computation",
        "CS321-Systems-Programming",
        "CS333-Web-Programming",
        "CS352-Computer-Graphics",
        "IT321-Professional-Training-in-Programming-I(.Net-1)",
        // semester 6
        "CS301-Numerical-Methods",
        "CS305-System-Modeling-and-Simulation",
        "CS312-Computing-Algorithms",
        "CS322-Operating-Systems",
        "CS366Introduction-to-Artificial-Intelligence",
        // minor semester 6
        "IS467-Big-Data-Analytics",
        "IT371-Professional-Training-in-Databases-1",
        // semester 7
        "CS401-Project-1",
        "CS445-Structure-of-Programming-Languages",
        "CS481-Computers-&-Society",
        // minor semester 7
        "CS428-Cloud-Computing",
        "CS441-Compilers",
        "SE496-Software-Engineering-Process",
        "IT411-Professional-Training-in-Software-Testing-2",
        // semester 8
        "CS402-Project-2",
        "CS421-Computer-System-Security",
        "CS451-Human-Computer-Interaction",
        // minor semester 8
        "CS432-Network-Protocols-&-Programming",
        "CS460_Deep-Learning",
        "SE496-Software-Engineering-Process",
        "IT412-Professional-Training-in-Software-Testing-3"
    };

    int i;

    // Create binary files for each course
    for (i = 0; i < MAX_COURSES; i++) {
        char fileName[MAX_NAME_LENGTH];
        sprintf(fileName, "%s.bin", courseNames[i]);
        
        FILE* file = fopen(fileName, "a");
        if (file == NULL) {
            printf("Failed to open file for course: %s\n", courseNames[i]);
            return 1;
        }

        fclose(file);
    }

    printf("Binary files created successfully!\n");
    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX_COURSES 100
// #define MAX_NAME_LENGTH 100
// typedef struct {
//     int ID;
//     char name[MAX_NAME_LENGTH];
//     int seven;
//     int twelve;
//     int final;
//     int total;
//     char Status[100];
// } Reg_Student;

// void addStudentInfo(const char* courseName, const Reg_Student* students, int numStudents) {
//     char filename[100];
//     sprintf(filename, "%s.bin", courseName);
//     FILE* file = fopen(filename, "ab");
//     if (file == NULL) {
//         printf("Error opening file: %s\n", filename);
//         return;
//     }
//     fwrite(students, sizeof(Reg_Student), numStudents, file);
//     fclose(file);
// }

// int main() {
//     // Array of course names
//     const char* courseNames[] = {
//         // semester 1
//         // semester 1
//         "BA003-Math-0",
//         "BA101-Calculus-1",
//         "BA113-Physics",
//         "CS111-Introduction-to-Computers",
//         "IS171-Introduction-to-Information-systems",
//         "LH135-English-for-Specific-Purposes-I(ESP-I)",
//         "NC172-Fundamentals-of-Business",
//         // semester 2
//         "BA102-Calculus-2",
//         "CS143-Introduction-to-Problem-Solving-and-Programming",
//         "EC134-Fundamentals-of-Electronics",
//         "LH136-English-for-Specific-Purposes-II(ESP-II)",
//         "NC133-Communication-Skills",
//         // semester 3
//         "BA201-Calculus-III",
//         "BA203-Probability-and-Statistics",
//         "BA216-Advanced-Physics",
//         "CE216-Digital-Logic-Design",
//         "CS202-Discrete-Structures",
//         "CS243-Object-Oriented-Programming",
//         // semester 4
//         "Introduction-to-Networks",
//         "CE243-Intro.-to-Computer-Architecture",
//         "CS212-Data-Structures-and-Algorithms",
//         "CS24-Advanced-Programming-Applications",
//         "IS273-Database-Systems",
//         "IT291-Professional-Training-in-Entrepreneurship",
//         "SE291-Introduction-to-Software-Engineering",
//         // semester 5
//         "BA301-Advanced-Statistics",
//         "BA304-Linear-Algebra",
//         "CS311-Theory-of-Computation",
//         "CS321-Systems-Programming",
//         "CS333-Web-Programming",
//         "CS352-Computer-Graphics",
//         "IT321-Professional-Training-in-Programming-I(.Net-1)",
//         // semester 6
//         "CS301-Numerical-Methods",
//         "CS305-System-Modeling-and-Simulation",
//         "CS312-Computing-Algorithms",
//         "CS322-Operating-Systems",
//         "CS366Introduction-to-Artificial-Intelligence",
//         // minor semester 6
//         "IS467-Big-Data-Analytics",
//         "IT371-Professional-Training-in-Databases-1",
//         // semester 7
//         "CS401-Project-1",
//         "CS445-Structure-of-Programming-Languages",
//         "CS481-Computers-&-Society",
//         // minor semester 7
//         "CS428-Cloud-Computing",
//         "CS441-Compilers",
//         "SE496-Software-Engineering-Process",
//         "IT411-Professional-Training-in-Software-Testing-2",
//         // semester 8
//         "CS402-Project-2",
//         "CS421-Computer-System-Security",
//         "CS451-Human-Computer-Interaction",
//         // minor semester 8
//         "CS432-Network-Protocols-&-Programming",
//         "CS460_Deep-Learning",
//         "SE496-Software-Engineering-Process",
//         "IT412-Professional-Training-in-Software-Testing-3"
//         // ... and so on
//     };
//     int numCourses = sizeof(courseNames) / sizeof(courseNames[0]);

//     // Array of students' information
//     Reg_Student students[] = {
// {221008802,"Abdelrahman Mohammed Hussain", 26, 29, 35, 90, "Passed"},
// {221018505, "Youssef Hassan Ibrahim", 24, 25, 37, 86, "Failed"},
// {221008720, "Zeyad hamdy Abdo Hussien", 27, 26, 38, 91, "Passed"},
// {211037804, "Hala Mahmoud Khalid", 30, 29, 39, 98, "Passed"},
// {221018151, "Mohamed Elhussein Mohamed Gad", 25, 26, 36, 87, "Passed"},
// {201034811, "Nour Ahmed Mohamed", 28, 30, 37, 95, "Passed"},
// {221008756, "Kareem Mohamed Youssef Ahmed", 28, 24, 40, 92, "Passed"},
// {221008565, "Martin Maged Fouad Gergesn", 29, 30, 38, 97, "Passed"},
// {221036406, "Mohammed Ali Ahmed", 27, 29, 35, 91, "Passed"},
// {221011710, "Aya Mahmoud Hassan", 30, 30, 36, 96, "Passed"},
// {221025111, "Sara Omar Khalid", 23, 27, 37, 87, "Failed"},
// {201030312, "Khaled Youssef Ali", 28, 28, 39, 95, "Passed"},
// {221016713, "Lina Ahmed Mahmoud", 25, 29, 40, 94, "Passed"},
// {201026614, "Ahmed Hassan Mohammed", 26, 25, 38, 89, "Failed"},
// {201039915, "Mona Youssef Ahmed", 30, 26, 37, 93, "Passed"},
// {201031216, "Hassan Ali Hassan", 27, 27, 36, 90, "Passed"},
// {201026517, "Youssef Ahmed Mohamed", 28, 28, 35, 91, "Passed"},

//         // Add more students as needed
//     };
//     int numStudents = sizeof(students) / sizeof(students[0]);

//     // Add student information to all courses
//     for (int i = 0; i < numCourses; i++) {
//         addStudentInfo(courseNames[i], students, numStudents);
//     }

//     return 0;
// }



// #include <stdio.h>

// #define MAX_COURSES 100
// #define MAX_NAME_LENGTH 50

// void deleteFileContents(const char* fileName) {
//     FILE* file = fopen(fileName, "w");
//     if (file == NULL) {
//         printf("Failed to open file: %s\n", fileName);
//         return;
//     }
//     fclose(file);
// }

// int main() {
//     char courseNames[MAX_COURSES][MAX_NAME_LENGTH] = {
//         // semester 1
//         "BA003-Math-0",
//         "BA101-Calculus-1",
//         "BA113-Physics",
//         "CS111-Introduction-to-Computers",
//         "IS171-Introduction-to-Information-systems",
//         "LH135-English-for-Specific-Purposes-I(ESP-I)",
//         "NC172-Fundamentals-of-Business",
//         // semester 2
//         "BA102-Calculus-2",
//         "CS143-Introduction-to-Problem-Solving-and-Programming",
//         "EC134-Fundamentals-of-Electronics",
//         "LH136-English-for-Specific-Purposes-II(ESP-II)",
//         "NC133-Communication-Skills",
//         // semester 3
//         "BA201-Calculus-III",
//         "BA203-Probability-and-Statistics",
//         "BA216-Advanced-Physics",
//         "CE216-Digital-Logic-Design",
//         "CS202-Discrete-Structures",
//         "CS243-Object-Oriented-Programming",
//         // semester 4
//         "Introduction-to-Networks",
//         "CE243-Intro.-to-Computer-Architecture",
//         "CS212-Data-Structures-and-Algorithms",
//         "CS24-Advanced-Programming-Applications",
//         "IS273-Database-Systems",
//         "IT291-Professional-Training-in-Entrepreneurship",
//         "SE291-Introduction-to-Software-Engineering",
//         // semester 5
//         "BA301-Advanced-Statistics",
//         "BA304-Linear-Algebra",
//         "CS311-Theory-of-Computation",
//         "CS321-Systems-Programming",
//         "CS333-Web-Programming",
//         "CS352-Computer-Graphics",
//         "IT321-Professional-Training-in-Programming-I(.Net-1)",
//         // semester 6
//         "CS301-Numerical-Methods",
//         "CS305-System-Modeling-and-Simulation",
//         "CS312-Computing-Algorithms",
//         "CS322-Operating-Systems",
//         "CS366Introduction-to-Artificial-Intelligence",
//         // minor semester 6
//         "IS467-Big-Data-Analytics",
//         "IT371-Professional-Training-in-Databases-1",
//         // semester 7
//         "CS401-Project-1",
//         "CS445-Structure-of-Programming-Languages",
//         "CS481-Computers-&-Society",
//         // minor semester 7
//         "CS428-Cloud-Computing",
//         "CS441-Compilers",
//         "SE496-Software-Engineering-Process",
//         "IT411-Professional-Training-in-Software-Testing-2",
//         // semester 8
//         "CS402-Project-2",
//         "CS421-Computer-System-Security",
//         "CS451-Human-Computer-Interaction",
//         // minor semester 8
//         "CS432-Network-Protocols-&-Programming",
//         "CS460_Deep-Learning",
//         "SE496-Software-Engineering-Process",
//         "IT412-Professional-Training-in-Software-Testing-3"
//         // Add more course names here
//     };

//     for (int i = 0; i < MAX_COURSES; i++) {
//         char fileName[MAX_NAME_LENGTH];
//         sprintf(fileName, "%s.bin", courseNames[i]);

//         deleteFileContents(fileName);
//     }

//     return 0;
// }


