#include <stdio.h>

//Nested structures practice.

struct person {
    char name[20];
    int salary;
};

// Nested structure

struct expertize {
    struct person info;
    int years;
} person1, person2, totalYears;

int main () {

    printf("\nEnter first person name: ");
    scanf("%s", person1.info.name);

    printf("Enter first person salary: ");
    scanf("%d", &person1.info.salary);

    printf("Enter first person experience: ");
    scanf("%d", &person1.years);

    printf("\nEnter second person name: ");
    scanf("%s", person2.info.name);

    printf("Enter second person salary: ");
    scanf("%d", &person2.info.salary);

    printf("Enter second person experience: ");
    scanf("%d", &person2.years);

    totalYears.years = person1.years + person2.years;

    if (totalYears.years > 0) {
        printf("\n%s and %s works together %d years\n", person1.info.name, person2.info.name, totalYears.years);
    }

    return 0;
}
