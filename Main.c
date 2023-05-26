#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define o printf
#define s scanf
#define MAX_INFO_SIZE 255
#define MAX_NAME_LENGTH 50

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

// void createTranscript(int studentID) {
//     char transcriptFileName[MAX_NAME_LENGTH];
//     sprintf(transcriptFileName, "transcript_%d.txt", studentID);

//     FILE* transcriptFile = fopen(transcriptFileName, "w");
//     if (transcriptFile == NULL) {
//         printf("Failed to create transcript file for student ID: %d\n", studentID);
//         return;
//     }

//     char courseNames[56][MAX_NAME_LENGTH] = {
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
//         // ... Add more course names for other semesters
//     };

//     int i;
//     for (i = 0; i < 56; i++) {
//     char fileName[MAX_NAME_LENGTH];
//     sprintf(fileName, "CS Courses\\%s.bin", courseNames[i]);

//     FILE* file = fopen(fileName, "rb+");
//         if (fileName == NULL) {
//             printf("Failed to open file for course: %s\n", courseNames[i]);
//             continue;
//         }

//         Reg_Student student;
//         while (fread(&student, sizeof(Reg_Student), 1, fileName) == 1) {
//             if (student.ID == studentID) {
//                 fprintf(transcriptFile, "Course: %s\n", courseNames[i]);
//                 // fprintf(transcriptFile, "Name: %s\n", student.name);
//                 fprintf(transcriptFile, "ID: %d\n", student.ID);
//                 fprintf(transcriptFile, "Grade: %d\n", student.final);
//                 fprintf(transcriptFile, "\n");
//             }
//         }

//         fclose(fileName);
//     }

//     fclose(transcriptFile);
//     printf("Transcript created successfully for student ID: %d\n", studentID);
// }

int main() {
    int PASS, studentID, k = 0, choice, c, x;
    int Current_semester = 0;

// assigning current semester variable.
    int period = Get_Period(studentID);
    if (period != NULL) {
        int semester = period;
        Current_semester = semester + 1;
    } 
    printf("\t\tWelcome to AAST Registration Program\n");
    printf("1-Student\t\t2-Admin\n");
    scanf("%d",&c);
    if(c==1){
        printf("1-Old Student\t\t2-New student\n");
        s("%d",&x);
    }
    switch (x)
    {
        case 1:
        o("Enter your Regisration Number: \n");
        l:s("%d", &studentID);
        o("Enter your pin: \n");
        m:s("%d", &PASS);
        system("cls");
        FILE *fptr;
        fptr = fopen("Students.txt", "r");
        if (Get_PIN(studentID) == NULL)
        {
            o("Registration Number and Pin Code dose not matched.\nPlease type them correctly.\nPlease try to enter pin again");
            goto m;
        }
        printf("Registration Number: %d", studentID);
        printf("\nName: %s", Get_Name(studentID));
        printf("\nCollege: %s", Get_College(studentID));
        printf("\nPeriod: %d", Get_Period(studentID));
        printf("\nDepartment: %s", Get_Department(studentID));
        printf("\nTotal Achivement: %f", Get_Credits(studentID));
        printf("\nGPA: %f", Get_GPA(studentID));

        printf("\n\n");
        printf("1-Register\t\t2-GPA Calculator\t\t3-View Registered Courses\t\t4-View/Print Transcript\n");
        n:s("%d", &choice);}

int sem = Get_Period(studentID) + 1;
switch (choice) {
    case 1:
        if (sem == 3) {
            printf("Current Semester: %d\n", sem);
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
        break;
    // Add cases for other choices as needed
    case 2:
}

return 0;
    
    }
   