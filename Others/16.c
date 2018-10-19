#include <stdio.h>

// Structure practice

// Declaring a structure variable

struct person {
    char name[50];
    char citizenship[2];
    float salary;
};

int main() {
    struct person person1, person2, totalSalary;


    // Accessing members of a structure
    printf("\nEnter first person name: ");
    scanf("%s", person1.name);

    printf("\nEnter first person citizenship: ");
    scanf("%s", person1.citizenship);

    printf("\nEnter first person salary: ");
    scanf("%f", &person1.salary);

    printf("\nEnter second person name: ");
    scanf("%s", person2.name);

    printf("\nEnter second person citizenship: ");
    scanf("%s", person2.citizenship);

    printf("\nEnter second person salary: ");
    scanf("%f", &person2.salary);

    totalSalary.salary = person1.salary + person2.salary;

    if (totalSalary.salary > 0) {
        printf("\n%s and %s salaries are %f\n", person1.name, person2.name, totalSalary.salary);
    }

    return 0;
}
