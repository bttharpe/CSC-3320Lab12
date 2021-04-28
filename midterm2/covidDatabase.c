#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX_USERS 100
#define NAME_LEN 25

//defines the database structure to hold each individual user's information.
struct database {
    char *firstName[NAME_LEN+1];
    char *lastName[NAME_LEN+1];
    char *DOB[NAME_LEN+1];
    char *sex[NAME_LEN+1];
    int doseNumber;
    char *DOD[NAME_LEN+1];
    char *vaccine[NAME_LEN+1];
    int zipcode;
    char *code[NAME_LEN+1];
    int age;
}; 

//initializes the covidbase database struct.
struct database covidbase[MAX_USERS];

//keep track of the totoal number of users to be able to index database info.
int numUsers = 0;
void reg(void);
void generate_code(void);
void search(void);
int read_line(char str[], int n);

//give user menu options to search or register. call necessary functions.
int main(){
    char operation;
    for (;;) {
        printf("Enter operation: 's' for search or  'r' for register. ");
        scanf (" %c", &operation);
        while (getchar() != '\n')
            ;
        switch (operation){
            case 's' : 
                search();
                break;
            case 'r' : 
                reg();
                break;
            default : printf("Unrecognized operation code.");
        }
        printf("\n");
    }
    
}

//search the database by 8 digit unique alphanumeric code.
void search(void){
    bool match = false;
    char input[9];
    printf("Enter your 8-digit alphanumeric code: ");
    scanf("%s", input);
    int i;
    int k;
    int index = 0;
    //go through each character in the code and compare to each code in the database until a match is found.
    for(i = 0; i < numUsers; i++){
        for(k = 0; k < 8; k++){
            if(covidbase[i].code[k] = input[k]){
                match = true;
                index = i;
            }
            else match = false;
        }
        //if a match is found, output all of the user's info.
        if(match){
            printf("Name: %s", covidbase[index].firstName);
            printf(" %s", covidbase[index].lastName);
            printf("\n");
            printf("DOB: %s", covidbase[index].DOB);
            printf("\n");
            printf("Sex: %s", covidbase[index].sex);
            printf("\n");
            printf("Dose number: %d", covidbase[index].doseNumber);
            printf("\n");
            printf("Date of previous dose: %s", covidbase[index].DOD);
            printf("\n");
            printf("Type of vaccine: %s", covidbase[index].vaccine);
            printf("\n");
            printf("Age: %d", covidbase[index].age);
            printf("\n");
            printf("Zip code: %d", covidbase[index].zipcode);
            return;
        }
    }
    printf("User not found.");
}

//use the user's info to generate a unique 8 digit alphanumeric code and print the code to console.
void generate_code(void){
    char age[NAME_LEN+1];
    sprintf(age, "%d", covidbase[numUsers].age);
    char zipcode[NAME_LEN+1];
    sprintf(zipcode, "%d", covidbase[numUsers].zipcode);
    char firstFromFirst = covidbase[numUsers].firstName[0];
    char firstFromLast = covidbase[numUsers].lastName[0];
    char firstOfVaccine = covidbase[numUsers].vaccine[0];
    char threeOfZipcode = zipcode[4];
    char twoOfZipcode = zipcode[3];
    char oneOfZipcode = zipcode[2];
    covidbase[numUsers].code[0] = firstFromFirst;
    covidbase[numUsers].code[1] = firstFromLast;
    covidbase[numUsers].code[2] = age[0];
    covidbase[numUsers].code[3] = age[1];
    covidbase[numUsers].code[4] = firstOfVaccine;
    covidbase[numUsers].code[7] = threeOfZipcode;
    covidbase[numUsers].code[6] = twoOfZipcode;
    covidbase[numUsers].code[5] = oneOfZipcode;
    int k;
    printf("\n");
    printf("Your code is: ");
    int i;
    for(i = 0; i < 8; i++){
        printf("%c", covidbase[numUsers].code[i]);
    }
}

//register a user by collecting the necessary info and assigning it to a database member.
void reg(void){
    int dn;
    int zc;
    int a;
    if(numUsers == MAX_USERS){
        printf("Database is full.");
        return;
    }
    printf("Enter first name: ");
    read_line(covidbase[numUsers].firstName, NAME_LEN);
    printf("\n");
    printf("Enter last name: ");
    read_line(covidbase[numUsers].lastName, NAME_LEN);
    printf("\n");
    printf("Enter date of birth in the form /mm/dd/yyyy: ");
    read_line(covidbase[numUsers].DOB, NAME_LEN);
    printf("\n");
    printf("Enter sex (Male, Female or NA): ");
    read_line(covidbase[numUsers].sex, NAME_LEN);
    printf("\n");
    printf("Enter date of previous dose in the form /mm/dd/yyyy: ");
    read_line(covidbase[numUsers].DOD, NAME_LEN);
    printf("\n");
    printf("Enter type of vaccine (Pfizer, Moderna, or Johnson&Johnson): ");
    read_line(covidbase[numUsers].vaccine, NAME_LEN);
    printf("\n");
    printf("Enter dose number (1 or 2): ");
    scanf("%d", &dn);
    covidbase[numUsers].doseNumber = dn;
    printf("\n");
    printf("Enter residential zipcode in the form 99999: ");
    scanf("%d", &zc);
    covidbase[numUsers].zipcode = zc;
    printf("\n");
    printf("Enter current age in years: ");
    scanf("%d", &a);
    covidbase[numUsers].age = a;
    
    //call the function to generate the unique 8 digit alphanumeric code.
    generate_code();
    
    numUsers++;
}

//skip leading white-space chars and read the input line, storing it in an array of chars. return the number of characters stored.
int read_line(char str[], int n){
    int ch, i = 0;
    while(isspace(ch = getchar()))
        ;
    while (ch != '\n' && ch != EOF){
        if (i < n){
            str[i++] = ch;
        }
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}

