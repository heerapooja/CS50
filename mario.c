#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int ht;

    do{
        ht = get_int("Height: ");
      }while(ht<=0||ht>8);
        int sp=ht-1, lhs=1, rhs=1;
        for(int row=0; row<ht; row++){
            for(int i=1; i<=sp; i++) printf(" ");
            for(int j=1; j<=lhs; j++) printf("#");
            printf("  ");
            for(int j=1; j<=rhs; j++) printf("#");
            sp--;
            lhs++;
            rhs++;
            printf("\n");
        }
}