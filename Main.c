#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main() {

 

   //لازم تعرف اسم الماده ف استرينج بالشكل ده قبل ما تشغل الفانكشن
    const char* courseName = "BA101-Calculus-1";
    int studentID = 221008802;
   //وتعرف الستاتيو بالشكل ده برضو قبل ما تعمل اي عملية
    char* status = Get_Status_of(courseName, studentID);
    if (status != NULL) {
        printf("Student status: %s\n", status);
    //ضروري تحرر الذاكرة بعد ما تخلص من الاسترينج
        free(status);
    } else {
        printf("Student not found or file not accessible.\n");
    }

return 0;
    
}
   // Student student1 = {221008802, "Abdelrahman Mohammed Hussain","College of Computing and Information Technology", 2, "Computer Science South Valley",15,3.4, 'A',253856};
    // Student student2 = {221008720,"Zeyad hamdy Abdo Hussien","College of Computing and Information Technology",2,"Computer Science South Valley",15,2.5,'C',549784};
    // Student student3 = {221018151,"Mohamed Elhussein Mohamed Gad","College of Computing and Information Technology",2,"Computer Science South Valley",15,2.7,'A',956483};
    // Student student4 = {221008756,"Kareem Mohamed Youssef Ahmed","College of Computing and Information Technology",2,"Computer Science South Valley",15,3.3,'A',214365};
    // Student student5 = {221008565,"Martin Maged Fouad Gerges","College of Computing and Information Technology",2,"Computer Science South Valley",15,3.2,'A',759427};

    // saveStudentInfo(student1);
    // saveStudentInfo(student2);
    // saveStudentInfo(student3);
    // saveStudentInfo(student4);
    // saveStudentInfo(student5);
    
    // int id, PIN;
    // printf("Enter the ID of the student: \n");
    // scanf("%d", &id);
    // printf("Enter PIN: \n");
    // scanf("%d", &PIN);
    // int temp_PIN = Get_PIN(id);
    // if(temp_PIN == PIN){
    //     printf("PIN is correct\n");
    //     char* name = Get_Name(id);
    //     if (name != NULL) {
    //     printf("Name: %s\n", name);}
    //     char* College = Get_College(id);
    //     if (College != NULL) {
    //     printf("College: %s\n", College);
    //     }
    //     int Period = Get_Period(id);
    //     if (Period != -1) {
    //     printf("Period: %d\n", Period);
    //     }
    //     char* Department = Get_Department(id);
    //     if (Department != NULL) {
    //     printf("Department: %s\n", Department);
    //     }
    //     float Credits = Get_Credits(id);
    //     if (Credits != -1) {
    //     printf("Credits: %.2f\n", Credits);
    //     }
    //     float gpa = Get_GPA(id);
    //     if (gpa != -1) {
    //     printf("GPA: %.2f\n", gpa);
    //     }
    //     char* FF = Get_FF(id);
    //     if (FF != NULL) {
    //     printf("FF: %s\n", FF);
    //     }
    //     int PIN = Get_PIN(id);
    //     if (PIN != -1) {
    //     printf("PIN: %d\n", PIN);}

    //     }
        
    // // } else {
    // //     printf("Student with  %d not found.\n", id);
    // // }

    // else{
    //     printf("PIN is incorrect\n");
    // }
    // Reg_Student student1 = {221008802, "Abdelrahman Mohammed Hussain", 29,28, 36,93, "Passed" };
    // Reg_Student student2 = { 2, "Jane Smith", 75, 85, 95, 0, "Pass" };

    // add_Student_To_Course("BA101-Calculus-1", student1);
    // addStudentToCourse("CS111-Introduction-to-Computers", student2);
// void saveStudentInfo(Student student) {
//     FILE *file = fopen("student_data.bin", "ab");
//     if (file == NULL) {
//         printf("Error opening file.\n");
//         return;
//     }

//     fwrite(&student, sizeof(Student), 1, file);
//     fclose(file);
// }
