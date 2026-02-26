#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    int roll_num;
    char gender[10];
    char course[10];
    int semester;
    int phone_num;
};

void Search(struct Student *s, int i)
{
    int target_roll;
    int found = 0;
    printf("Enter Roll number\n");
    scanf("%d", &target_roll);
    for (int j = 0; j < i; j++)
    {
        if (s[j].roll_num == target_roll)
        {
            printf("Student Name: %s\n", s[j].name);
            printf("Student Roll number: %d\n", s[j].roll_num);
            printf("Student Gender: %s\n", s[j].gender);
            printf("Student Course: %s\n", s[j].course);
            printf("Student Semester: %d\n", s[j].semester);
            printf("Student Phone Number: %d\n", s[j].phone_num);

            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("No records found!\n");
    }
}
void add(struct Student *s)
{
    printf("Enter Student name:\n");
    scanf("%s", s->name);

    printf("Enter Student Roll number:\n");
    scanf("%d", &(s->roll_num));

    printf("Enter Student Gender:\n");
    scanf("%s", s->gender);

    printf("Enter Student Course:\n");
    scanf("%s", s->course);

    printf("Enter Student Semester:\n");
    scanf("%d", &(s->semester));

    printf("Enter Student Phone number:\n");
    scanf("%d", &(s->phone_num));

    printf("Student Record saved!\n\n");
}
void edit(struct Student *s, int i)
{
    int target_roll;
    int found = 0;
    printf("Enter Roll number:\n");
    scanf("%d", &target_roll);
    for (int j = 0; j < i; j++)
    {
        if (s[j].roll_num == target_roll)
        {
            printf("Enter Student name:\n");
            scanf("%s", s[j].name);

            printf("Enter Student Roll number:\n");
            scanf("%d", &(s[j].roll_num));

            printf("Enter Student Gender:\n");
            scanf("%s", s[j].gender);

            printf("Enter Student Course:\n");
            scanf("%s", s[j].course);

            printf("Enter Student Semester:\n");
            scanf("%d", &(s[j].semester));

            printf("Enter Student Phone number:\n");
            scanf("%d", &(s[j].phone_num));

            printf("Student Record Edited!\n\n");

            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Student Not found!");
    }
}

int deletestudent(struct Student *s, int i)
{
    int target_roll;
    int found = 0;
    printf("Enter Roll number:\n");
    scanf("%d", &target_roll);
    for (int j = 0; j < i; j++)
    {
        if (target_roll == s[j].roll_num)
        {
            for (int k = j; k < i - 1; k++)
            {
                s[k] = s[k + 1];
            }

            printf("Student deleted\n\n");
            found = 1;
            i--;
            break;
        }
    }
    if (found == 0)
    {
        printf("No Student found!");
    }
    return i;
}
void display(struct Student *s, int i)
{
    if (i == 0)
    {
        printf("No students in database.\n");
        return;
    }
    for (int j = 0; j < i; j++)
    {
        printf("Student Name: %s\n", s[j].name);
        printf("Student Roll number: %d\n", s[j].roll_num);
        printf("Student Gender: %s\n", s[j].gender);
        printf("Student Course: %s\n", s[j].course);
        printf("Student Semester: %d\n", s[j].semester);
        printf("Student Phone number: %d\n", s[j].phone_num);
    }
}
int main()
{
    int choice;
    int i = 0;
    struct Student s[100];
    FILE *ptr;
    ptr = fopen("strm.txt", "r");
    /*-------------------FILE LOAD-------------------*/
    if (ptr != NULL)
    {
        while (fscanf(ptr, "%s %d %s %s %d %d",
                      s[i].name, &s[i].roll_num, s[i].gender, s[i].course, &s[i].semester, &s[i].phone_num) != EOF)
        {
            i++;
        }
        fclose(ptr);
    }

    /*-------------------MENU LOOP------------------- */
    do
    {
        printf("\t----STUDENT RECORD MANAGEMENT SYSTEM----\n\n");
        printf("1.Add Student\n");
        printf("2.Search Student\n");
        printf("3.Edit Student\n");
        printf("4.Delete Student\n");
        printf("5.Display all Student\n");
        printf("6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        if (choice < 1 || choice > 6)
        {
            printf("Invalid choice\n");
            continue;
        }
        switch (choice)
        {
        case 1:
            if (i >= 100)
            {
                printf("Database is full!\n");
                printf("Return to menu\n\n");
                continue;
            }
            add(&s[i]);
            i++;
            break;

        case 2:
            if (i < 1)
            {
                printf("No Student added yet!\n");
                continue;
            }

            Search(s, i);
            break;

        case 3:
            edit(s, i);
            break;

        case 4:
            i = deletestudent(s, i);
            break;

        case 5:
            display(s, i);
            break;

        default:
            break;
        }
    } while (choice != 6);
    /*-------------------FILE SAVE BEFORE EXIT-------------------*/
    ptr = fopen("strm.txt", "w");
    if (ptr != NULL)
    {
        for (int j = 0; j < i; j++)
        {
            {
                fprintf(ptr, "%s %d %s %s %d %d \n",
                        s[j].name,
                        s[j].roll_num,
                        s[j].gender,
                        s[j].course,
                        s[j].semester,
                        s[j].phone_num);
            }
        }

        fclose(ptr);
    }
    return 0;
}