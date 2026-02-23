#include<stdio.h>

int main() {
    int marks;

printf("enter marks: ");
scanf("%d", &marks);
    while(marks<0 || marks>100){
        printf("invalid marks...");
     }

     switch(marks/10){
        case 10: printf("GRADE A+\n");
        break;
        case 9: printf("GRADE A\n");
        break;
        case 8: printf("GRADE A-\n");
        break;
        case 7: printf("GRADE B+\n");
        break;
        case 6: printf("GRADE B\n");
        break;
        case 5: printf("GRADE B-\n");
        break;
        case 4: printf("GRADE C");
        break;
        case 3: printf("GRADE D");
        break;
        default: printf("GRADE F\n");
     }
     return 0;
}