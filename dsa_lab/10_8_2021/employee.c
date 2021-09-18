#include <stdio.h>
#include <stdlib.h>
struct employee
{
    char name[20];
    char gender;
    char designation[10];
    char department[10];
    float basic_pay;
    float gross_pay;
};

void input(struct employee *em_ptr)
{
    printf("Enter the name : ");
    scanf("%19s", &(em_ptr->name));
    puts("");
    printf("Enter gender(f - female, m - male, o - others) : ");
    scanf(" %c", &(em_ptr->gender));
    puts("");
    printf("Enter the designation : ");
    scanf(" %9s", &(em_ptr->designation));
    puts("");
    printf("Enter the department : ");
    scanf(" %9s", &(em_ptr->department));
    puts("");
    printf("Enter the basic pay : ");
    scanf(" %f", &(em_ptr->basic_pay));
    puts("");
}

void calculate(struct employee *em_ptr)
{
    float HR, DA;
    HR = 0.25 * em_ptr->basic_pay;
    DA = 0.75 * em_ptr->basic_pay;
    em_ptr->gross_pay = em_ptr->basic_pay + HR + DA;
}
void display(struct employee *em_ptr)
{
    printf("Name : ");
    printf("%s", em_ptr->name);
    puts("");
    printf("Gender : ");
    printf("%c", em_ptr->gender);
    puts("");
    printf("Designation : ");
    printf("%s", em_ptr->designation);
    puts("");
    printf("Department : ");
    printf("%s", em_ptr->department);
    puts("");
    printf("Basic pay : ");
    printf("%.3f", em_ptr->basic_pay);
    puts("");
    printf("Gross pay : ");
    printf("%.3f", em_ptr->gross_pay);
    puts("");
}
int main()
{
    int n;
    puts("Enter number of employees");
    scanf("%d", &n);
    struct employee *arr[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = (struct employee *)malloc(sizeof(struct employee));

        input(arr[i]);
        calculate(arr[i]);
    }
    puts("-----------------------------------------------------------------");

    for (int i = 0; i < n; ++i)
    {
        display(arr[i]);
        puts(" ");
        free(arr[i]);
    }
    puts("Memory is successfully freed");
    return 0;
}