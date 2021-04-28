#include <stdio.h>

//setup a structure that has a char pointer and an integer.
struct dialing_code{
    char *country;
    int code;
};

//declaring an array of this structure that holds the country names and dialing codes.
const struct dialing_code country_codes[]= {{"Argentina",54}, {"Brazil",55}, {"China",86}, {"Ethiopia",251}, {"Germany",49}, {"Bangladesh",880}, {"Burma",95}, {"Columbia",57}, {"Egypt",20}, {"France",33},
                                                {"India",91}, {"Indonesia",62}, {"Italy",39}, {"Mexico",52}, {"Pakistan",92}, {"Poland",48}, {"Spain",34}, {"Thailand",66}, {"Ukraine",380}, {"United States",1}};

//initialize the search function
void search(int input);

//scans an integer from the user and calls the search function
int main(){
    
    int input;
    printf("Please enter an international dialing code: \n");
    scanf("%d", &input);
    search(input);
    return 0;
}

//takse an integer input and searches through the structure array to find a matching dialing code.
void search(int input){
    int i;
    //calculate the length of the array by dividing the total number of bytes by the number of bytes occupied by the first element.
    int length=sizeof(country_codes)/sizeof(country_codes[0]);
    for(i=0; i<length; i++){
        if(country_codes[i].code==input){
            printf("%s",country_codes[i].country);
            return;
        }
    }
    printf("No country found."); 
}

