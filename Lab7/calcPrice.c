#include<stdio.h>
int main(){
int num;
double price;
int quant;
char date[12];
printf("Enter item number:");
scanf("%d",&num);
printf("Enter unit price:");
scanf("%lf",&price);
printf("Enter quantity:");
scanf("%d", &quant);
printf("Enter purchase date (mm/dd/yyyy):");
scanf("%s", date);
printf("\nItem\tUnit Price\tQTY\tPurchase Date\tTotal Amount\n");
printf("%d\t$%9.2f\t%d\t%s\t$%11.2f\n", num, price, quant, date, price * quant);
return 0;
}
