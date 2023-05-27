#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define o printf
#define s scanf
#define MAX_INFO_SIZE 255
#define MAX_NAME_LENGTH 50
#define MAX_STUDENT_IDS 1000
  // File to store registered courses
    
const char* filename = "registered_courses.dat";
// Struct definition for student information
typedef struct {
    int ID;
    char name[MAX_NAME_LENGTH];
    char College[100];
    int Period;
    char Department[100];
    float Credits;
    float GPA;
    char FF;
    int PIN;

} Student;
typedef struct {
    int ID;
    char name[MAX_NAME_LENGTH];
    int seven;
    int twelve;
    int final;
    int total;
    char Status[100];
} Reg_Student;
typedef struct {
    char courseCode[10];
    char courseName[50];
} Course;
typedef struct {
    bool BA201_Calculus_III;
    bool BA203_Probability_and_Statistics;
    bool BA216_Advanced_Physics;
    bool CE216_Digital_Logic_Design;
    bool CS202_Discrete_Structures;
    bool CS243_Object_Oriented_Programming;
} Semester3;
Semester3 currentSemester;
void strToLower(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;  // Convert uppercase to lowercase
        }
    }
}

// Function to store student information in a binary file
// Function to store student information in a binary file
void save_Student_Info(Student student) {
    FILE *file = fopen("student_data.bin", "ab+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Student temp;
    int duplicate = 0;

    // Check for duplicate students
    while (fread(&temp, sizeof(Student), 1, file) == 1) {
        if (temp.ID == student.ID) {
            duplicate = 1;
            break;
        }
    }

    if (duplicate) {
        printf("Student with Roll Number %d already exists. Not added.\n", student.ID);
    } else {
        fwrite(&student, sizeof(Student), 1, file);
        printf("Student added successfully.\n");
    }

    fclose(file);
}
char* Get_Name(int id) {
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    Student student;
    char* name = NULL;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.ID == id ) {
            name = strdup(student.name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with  %d not found.\n",id );
    }

    fclose(file);
    return name;
}
char* Get_College(int id ) {
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    Student student;
    char* College = NULL;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.ID == id ) {
            College = strdup(student.College);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return College;
}
// Function to retrieve GPA by student 
int Get_Period(int id) {
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    Student student;
    int Period = -1;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.ID == id ) {
            Period = student.Period;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return Period;
}
char* Get_Department(int id ) {
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    Student student;
    char* Department = NULL;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.ID == id ) {
            Department = strdup(student.Department);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with  %d not found.\n", id);
    }

    fclose(file);
    return Department;
}
float Get_Credits(int id) {
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    Student student;
    float Credits = -1;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.ID == id ) {
            Credits = student.Credits;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with  %d not found.\n", id );
    }

    fclose(file);
    return Credits;
}
float Get_GPA(int id) {
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    Student student;
    float GPA = -1;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.ID == id) {
            GPA = student.GPA;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with  %d not found.\n", id );
    }

    fclose(file);
    return GPA;
}
char* Get_FF(int id ) {
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    Student student;
    char* FF = NULL;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.ID == id ) {
            FF = strdup(student.FF);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with  %d not found.\n", id );
    }

    fclose(file);
    return FF;
}
int Get_PIN(int id ) {
    FILE *file = fopen("student_data.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    Student student;
    int PIN = -1;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.ID == id ) {
            PIN = student.PIN;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with  %d not found.\n",id );
    }

    fclose(file);
    return PIN;
}
void add_Student_To_Course(const char* courseName, Reg_Student student) {
    char fileName[MAX_NAME_LENGTH];
    sprintf(fileName, "CS Courses\\%s.bin", courseName);

    FILE* file = fopen(fileName, "rb+");
    if (file == NULL) {
        printf("Failed to open file: %s\n", fileName);
        return;
    }

    // Move the file position to the end to append the student struct
    fseek(file, 0, SEEK_END);

    fwrite(&student, sizeof(Reg_Student), 1, file);

    fclose(file);
}
char* Get_Status_of(const char* courseName, int studentID) {
    char fileName[MAX_NAME_LENGTH];
    sprintf(fileName, "CS Courses\\%s.bin", courseName);

    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Failed to open file: %s\n", fileName);
        return NULL;
    }

    Reg_Student student;
    while (fread(&student, sizeof(Reg_Student), 1, file) == 1) {
        if (student.ID == studentID) {
            fclose(file);
            return strdup(student.Status);
        }
    }

    fclose(file);
    return NULL;
}
void Modify_GPA(int id, float newGPA) {
    FILE* file = fopen("student_data.bin", "r+b");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Student student;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.ID == id) {
            student.GPA = newGPA;
            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&student, sizeof(Student), 1, file);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }

    fclose(file);
}
void Modify_Credits(int id, float newCredits) {
    FILE* file = fopen("student_data.bin", "r+b");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Student student;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.ID == id) {
            student.Credits = newCredits;
            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&student, sizeof(Student), 1, file);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }

    fclose(file);
}

void createTranscript(int studentID) {
    char transcriptFileName[MAX_NAME_LENGTH];
    snprintf(transcriptFileName, sizeof(transcriptFileName), "transcript_%d.txt", studentID);

    FILE* transcriptFile = fopen(transcriptFileName, "w");
    if (transcriptFile == NULL) {
        printf("Failed to create transcript file for student ID: %d\n", studentID);
        return;
    }

    char courseNames[][MAX_NAME_LENGTH] = {
        // List all the course names here
        "BA003-Math-0",
        "BA101-Calculus-1",
        "BA113-Physics",
        "CS111-Introduction-to-Computers",
        "IS171-Introduction-to-Information-systems",
        "LH135-English-for-Specific-Purposes-I_ESP-I",
        "NC172-Fundamentals-of-Business",
        // semester 2
        "BA102-Calculus-2",
        "CS143-Introduction-to-Problem-Solving-and-Programming",
        "EC134-Fundamentals-of-Electronics",
        "LH136-English-for-Specific-Purposes-II_ESP-II",
        "NC133-Communication-Skills",
        // semester 3
        "BA201-Calculus-III",
        "BA203-Probability-and-Statistics",
        "BA216-Advanced-Physics",
        "CE216-Digital-Logic-Design",
        "CS202-Discrete-Structures",
        "CS243-Object-Oriented-Programming",
    };
    int numCourses = sizeof(courseNames) / sizeof(courseNames[0]);

    for (int i = 0; i < numCourses; i++) {
        char fileName[MAX_NAME_LENGTH];
        snprintf(fileName, sizeof(fileName), "CS Courses/%s.bin", courseNames[i]);

        FILE* courseFile = fopen(fileName, "rb");
        if (courseFile == NULL) {
            printf("Error opening course file: %s\n", fileName);
            continue;
        }

        Reg_Student student;
        int foundInCourse = 0;  // Flag to track if student is found in the current course

        while (fread(&student, sizeof(Reg_Student), 1, courseFile) == 1) {
            if (student.ID == studentID) {
                // Check if the student is already found in the current course
                if (foundInCourse) {
                    continue;  // Skip duplicate entries within the same course
                }

                fprintf(transcriptFile, "Course: %s\n", courseNames[i]);
                fprintf(transcriptFile, "Student ID: %d\n", student.ID);
                fprintf(transcriptFile, "Student Name: %s\n", student.name);
                fprintf(transcriptFile, "Grade: %d\n", student.final);
                fprintf(transcriptFile, "Status: %s\n", student.Status);
                fprintf(transcriptFile, "----------------------------------------\n");

                foundInCourse = 1;  // Set the flag indicating student is found in the current course
            }
        }

        fclose(courseFile);
    }

    fclose(transcriptFile);
    printf("Transcript created successfully!\n");
}
void printStudentInformation(int studentID) {
    printf("Registration Number: %d", studentID);
    printf("\nName: %s", Get_Name(studentID));
    printf("\nCollege: %s", Get_College(studentID));
    printf("\nPeriod: %d", Get_Period(studentID));
    printf("\nDepartment: %s", Get_Department(studentID));
    printf("\nTotal Achievement: %f", Get_Credits(studentID));
    printf("\nGPA: %f", Get_GPA(studentID));
    printf("\n\n");
}
// Function to save registered courses to a file
void Save_Registered_Courses(const char* filename, const Semester3* semester) {
    FILE* file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(semester, sizeof(Semester3), 1, file);
        fclose(file);
    }
}

// Function to load registered courses from a file
void Load_Registered_Courses(const char* filename, Semester3* semester) {
    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        fread(semester, sizeof(Semester3), 1, file);
        fclose(file);
    }
}
void Remove_Registered_Course(Semester3* semester) {
      char courseName[50];
    printf("Enter the course name to modify: ");
    scanf("%s", courseName);

    // Convert the input course name to lowercase for comparison
    strToLower(courseName);

    // Check if the course is already registered
    bool isCourseRegistered = false;

    if (strcmp(courseName, "ba201-calculus-iii") == 0) {
        isCourseRegistered = semester->BA201_Calculus_III;
    } else if (strcmp(courseName, "ba203-probability-and-statistics") == 0) {
        isCourseRegistered = semester->BA203_Probability_and_Statistics;
    } else if (strcmp(courseName, "ba216-advanced-physics") == 0) {
        isCourseRegistered = semester->BA216_Advanced_Physics;
    } else if (strcmp(courseName, "ce216-digital-logic-design") == 0) {
        isCourseRegistered = semester->CE216_Digital_Logic_Design;
    } else if (strcmp(courseName, "cs202-discrete-structures") == 0) {
        isCourseRegistered = semester->CS202_Discrete_Structures;
    } else if (strcmp(courseName, "cs243-object-oriented-programming") == 0) {
        isCourseRegistered = semester->CS243_Object_Oriented_Programming;
    } else {
        printf("Invalid course name!\n");
        return;
    }

    if (!isCourseRegistered) {
        printf("You have not registered for the course '%s'.\n", courseName);
        return;
    }

    // Modify the registered course based on the course name
    if (strcmp(courseName, "ba201-calculus-iii") == 0) {
        semester->BA201_Calculus_III = true;
    } else if (strcmp(courseName, "ba203-probability-and-statistics") == 0) {
        semester->BA203_Probability_and_Statistics = true;
    } else if (strcmp(courseName, "ba216-advanced-physics") == 0) {
        semester->BA216_Advanced_Physics = true;
    } else if (strcmp(courseName, "ce216-digital-logic-design") == 0) {
        semester->CE216_Digital_Logic_Design = true;
    } else if (strcmp(courseName, "cs202-discrete-structures") == 0) {
        semester->CS202_Discrete_Structures = true;
    } else if (strcmp(courseName, "cs243-object-oriented-programming") == 0) {
        semester->CS243_Object_Oriented_Programming = true;
    }
}
// void Add_Registered_Course(Semester3* semester) {
//     char courseName[50];
//     printf("Enter the course name to add: ");
//     scanf("%s", courseName);

//     // Convert the input course name to lowercase for comparison
//     strToLower(courseName);

//     // Check if the course is already registered
//     bool isCourseRegistered = false;

//     if (strcmp(courseName, "ba201-calculus-iii") == 0) {
//         isCourseRegistered = semester->BA201_Calculus_III;
//     } else if (strcmp(courseName, "ba203-probability-and-statistics") == 0) {
//         isCourseRegistered = semester->BA203_Probability_and_Statistics;
//     } else if (strcmp(courseName, "ba216-advanced-physics") == 0) {
//         isCourseRegistered = semester->BA216_Advanced_Physics;
//     } else if (strcmp(courseName, "ce216-digital-logic-design") == 0) {
//         isCourseRegistered = semester->CE216_Digital_Logic_Design;
//     } else if (strcmp(courseName, "cs202-discrete-structures") == 0) {
//         isCourseRegistered = semester->CS202_Discrete_Structures;
//     } else if (strcmp(courseName, "cs243-object-oriented-programming") == 0) {
//         isCourseRegistered = semester->CS243_Object_Oriented_Programming;
//     } else {
//         printf("Invalid course name!\n");
//         return;
//     }

//     if (isCourseRegistered) {
//         printf("You have already registered for the course '%s'.\n", courseName);
//         return;
//     }

//     // Register the course based on the course name
//     if (strcmp(courseName, "ba201-calculus-iii") == 0) {
//         semester->BA201_Calculus_III = true;
//     } else if (strcmp(courseName, "ba203-probability-and-statistics") == 0) {
//         semester->BA203_Probability_and_Statistics = true;
//     } else if (strcmp(courseName, "ba216-advanced-physics") == 0) {
//         semester->BA216_Advanced_Physics = true;
//     } else if (strcmp(courseName, "ce216-digital-logic-design") == 0) {
//         semester->CE216_Digital_Logic_Design = true;
//     } else if (strcmp(courseName, "cs202-discrete-structures") == 0) {
//         semester->CS202_Discrete_Structures = true;
//     } else if (strcmp(courseName, "cs243-object-oriented-programming") == 0) {
//         semester->CS243_Object_Oriented_Programming = true;
//     }

//     printf("Course '%s' has been added to your registered courses.\n", courseName);
// }

void Print_Semester_Courses_7(int semester, int studentID) {
                      int choice;  
    if (semester == 3) {
        printf("Current Semester: %d\n", semester);
        
        char* status = Get_Status_of("BA101-Calculus-1", studentID);
        printf("\n%s\n", status);
        if (strcmp(status, "Passed") == 0) {
            printf("1-BA201-Calculus-III\n");
                printf("Enter 1 to add 1-BA201-Calculus-III or 0 to skip: ");
                scanf("%d", &choice);
                if (choice == 1) {
                currentSemester.BA201_Calculus_III = true;
                }
            printf("2-BA203-Probability-and-Statistics\n");
                printf("Enter 1 to add BA203-Probability-and-Statistics or 0 to skip: ");
                scanf("%d", &choice);
                if (choice == 1) {
                currentSemester.BA203_Probability_and_Statistics = true;
                }
            free(status);
        }
        
        status = Get_Status_of("BA113-Physics", studentID);
        printf("\n%s\n", status);
        if (strcmp(status, "Passed") == 0) {
            printf("3-BA216-Advanced-Physics\n");
                printf("Enter 1 to add BA216-Advanced-Physics or 0 to skip: ");
                scanf("%d", &choice);
                if (choice == 1) {
                currentSemester.BA216_Advanced_Physics = true;
                }
            free(status);
        }
        
        status = Get_Status_of("CS111-Introduction-to-Computers", studentID);
        printf("\n%s\n", status);
        if (strcmp(status, "Passed") == 0) {
            printf("4-CE216-Digital Logic Design\n");
                printf("Enter 1 to add CE216-Digital Logic Design or 0 to skip: ");
                scanf("%d", &choice);
                if (choice == 1) {
                currentSemester.CE216_Digital_Logic_Design = true;
                }
            printf("5-CS202-Discrete Structures\n");
                printf("Enter 1 to add CS202-Discrete Structures or 0 to skip: ");
                scanf("%d", &choice);
                if (choice == 1) {
                currentSemester.CS202_Discrete_Structures = true;
                }
            free(status);
        }
        
        status = Get_Status_of("CS143-Introduction-to-Problem-Solving-and-Programming", studentID);
        printf("\n%s\n", status);
        if (strcmp(status, "Passed") == 0) {
            printf("6-CS243-Object Oriented Programming\n");
                printf("Enter 1 to add CS243-Object Oriented Programming or 0 to skip: ");
                scanf("%d", &choice);
                if (choice == 1) {
                currentSemester.CS243_Object_Oriented_Programming = true;
                }
            free(status);
        }
    }
         Save_Registered_Courses(filename, &currentSemester);
    }
    
void Print_Semester_Courses_4(int semester, int studentID) {
    Course registeredCourses[10];
    int numRegisteredCourses = 0;  // Keeps track of the number of registered courses

    if (semester == 3) {
        printf("Current Semester: %d\n", semester);
        
        char* status = Get_Status_of("BA101-Calculus-1", studentID);
        printf("\n%s\n", status);
        if (strcmp(status, "Passed") == 0) {
            printf("1-BA201-Calculus-III\n2-BA203-Probability-and-Statistics\n");
            free(status);
        }
        
        status = Get_Status_of("BA113-Physics", studentID);
        printf("\n%s\n", status);
        if (strcmp(status, "Passed") == 0) {
            printf("3-BA216-Advanced-Physics\n");
            free(status);
        }
        
        status = Get_Status_of("CS111-Introduction-to-Computers", studentID);
        printf("\n%s\n", status);
        if (strcmp(status, "Passed") == 0) {
            printf("4-CE216-Digital Logic Design\n5-CS202-Discrete Structures\n");
            free(status);
        }
        
        status = Get_Status_of("CS143-Introduction-to-Problem-Solving-and-Programming", studentID);
        printf("\n%s\n", status);
        if (strcmp(status, "Passed") == 0) {
            printf("6-CS243-Object Oriented Programming\n");
            free(status);
        }
    }
}

int main() {
    int PASS, studentID, k = 0, choice, c, x;
    int Current_semester = 0;
        Semester3 currentSemester;  // Semester structure to store registered courses
    char filename[50];  // File name to store registered courses
    sprintf(filename, "registered_courses_%s.dat", studentID);  // Generate file name with student ID
    int period = Get_Period(studentID);
    if (period != NULL) {
        int semester = period;
        Current_semester = semester + 1;
    } 
    printf("\t\tWelcome to AAST Registration Program\n");
    printf("1-Student\t\t2-Admin\n");
    scanf("%d",&c);
    // system("cls");
    if(c==1){
        printf("1-Old Student\t\t2-New student\n");
        s("%d",&x);
    }
    // system("cls");
    switch (x)
    {
        case 1:
        o("Enter your Regisration Number: \n");
        l:s("%d", &studentID);
        o("Enter your pin: \n");
        m:s("%d", &PASS);
        // system("cls");
        FILE *fptr;
        fptr = fopen("Students.txt", "r");
        if (Get_PIN(studentID) != PASS)
        {
            o("Registration Number and Pin Code dose not matched.\nPlease type them correctly.\nPlease try to enter pin again\n");
            goto m;
        }
        // system("cls");
        printStudentInformation(studentID);
        r:
        printf("1-Register\t2-GPA Calculator\t3-View Registered Courses\t4-Create Transcript\t\t5-Remove Registered Course\t6-Add Registered Course\t\t7-Exit\n");
        n:s("%d", &choice);}

int sem = Get_Period(studentID) + 1;
switch (choice) {
        // Semester3 currentSemester = { false, false, false, false, false, false, false };
    case 1:
            Load_Registered_Courses(filename, &currentSemester);
            if (currentSemester.BA201_Calculus_III ||
                currentSemester.BA203_Probability_and_Statistics ||
                currentSemester.BA216_Advanced_Physics ||
                currentSemester.CE216_Digital_Logic_Design ||
                currentSemester.CS202_Discrete_Structures ||
                currentSemester.CS243_Object_Oriented_Programming) {
                printf("You are already registered for courses. Do you want to Remove course? (Y/N)\n");
                char response;
                scanf(" %c", &response);
                if (response == 'Y' || response == 'y') {
                    Remove_Registered_Course(&currentSemester);
                    Save_Registered_Courses(filename, &currentSemester);
                }
                goto r;
            break;
    // Add cases for other choices as needed

    case 3:
      // Accessing the registered courses
    Load_Registered_Courses(filename, &currentSemester);  // Load registered courses from file 
        printf("\nRegistered Courses:\n");
        if (currentSemester.BA201_Calculus_III) {
            printf("BA201-Calculus-III\n");
        }
        if (currentSemester.BA203_Probability_and_Statistics) {
            printf("BA203-Probability-and-Statistics\n");
        }
        if (currentSemester.BA216_Advanced_Physics) {
            printf("BA216-Advanced-Physics\n");
        }
        if (currentSemester.CE216_Digital_Logic_Design) {
            printf("CE216-Digital-Logic-Design\n");
        }
        if (currentSemester.CS202_Discrete_Structures) {
            printf("CS202-Discrete-Structures\n");
        }
        if (currentSemester.CS243_Object_Oriented_Programming) {
            printf("CS243-Object-Oriented-Programming\n");
        }
        goto r;
        break;
    case 4:
    createTranscript(studentID);
    break;
    case 5:
            Remove_Registered_Course(&currentSemester);
            Save_Registered_Courses(filename, &currentSemester);
            goto r;
            break;
    case 6:
            // Add_Registered_Course(&currentSemester);
            Save_Registered_Courses(filename, &currentSemester);
            goto r;
            break;
    case 7:
            printf("Exiting the program.\n");
            return 0;
    default:
        printf("Invalid choice!\n");
        goto n;
}

        goto r;
}


return 0;
    
    }
   