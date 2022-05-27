#include <stdio.h>
#include <stdlib.h>
/// Define a structure 'emp' to hold data about an employee
struct emp
{
    char name[48]; // Name of the employee
    int age;
    float bs; // Basic Salary as a floating point number.
};


    int write_records_to_file (struct emp * sptr, int num_records, FILE * fptr);
    int read_records_from_file(struct emp * sptr, int num_records, FILE * fptr);
    void print_records(struct emp * sptr, int num_records);

int main(void)
{
    struct emp employee;
    FILE *fp;
    int i,option,n;
    int w ;
    printf("Choose an Option: \n");
    printf("1.Write Data to File\n");
    printf("2.Print Data From File\n");
    printf("3.Exit\n");
    scanf("%d",&option);

    while(option != 3)
    {
        switch(option)
        {
        case 1:
            printf("Enter Number of records: \n");
            scanf("%d", &i);
            for(int j=0; j<i; j++)
                w = write_records_to_file(&employee, i, &fp);
            printf("Number of records written to file are: %d\n",w);
            break;
        case 2:
            print_records(&employee, i);
            break;
        case 3:
            return;
            break;
        }
        printf("\nSelect an option: \n");
        scanf("%d",&option);
    }
}

int write_records_to_file (struct emp * sptr, int num_records, FILE * fptr)
{
// Open the file for writing in the Binary Mode
    fptr = fopen ( "employees_records.dat", "wb" ) ;
    if ( fptr == NULL ){
        printf ( "Cannot open file\n" ) ;
        exit(0) ;
    }
        printf ( "\nEnter the name of the Employee: " ) ;
        //fgets (employee.name, 48, stdin);
        scanf("%s", sptr->name);
        printf ( "\nEnter the age of the Employee: " ) ;
        scanf("%d", &sptr->age);
        printf ( "\nEnter the Basic Salary of the Employee: " ) ;
        scanf("%f", &sptr->bs ) ;
        // Writing to file
        fwrite ( &sptr, sizeof ( struct emp ), 1, fptr );

        fclose(fptr);
        return num_records;
}


int read_records_from_file(struct emp * sptr, int num_records, FILE * fptr)
{
    char ch;
    fptr = fopen("employees_records.dat", "r");
    if(fptr == NULL)
    {
        printf("Not found");
        exit(1);
    }
    ch = fgetc(fptr);
    while(!feof(fptr))
    {
        printf("%c",ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
}

void print_records(struct emp * sptr, int num_records)
{
    FILE *fp;
    printf("%d",read_records_from_file(sptr, num_records,fp));

}
