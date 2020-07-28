#include <stdio.h>
#include <stdlib.h>
#include "frequencytable.c"
#include "averagesandvariance.c"

int main(void)
{
    int userSelect;
    printf("Please select an option:\n0: Frequency Table\n1: Averages and Variance\n");
    scanf("%d", &userSelect);
    switch (userSelect) {
        case 0:
            freqtablemain();
            break;
        case 1:
            averagesandvariancemain();
            break;
        default:
            printf("Please select a listed option");
    }
    return 0;
}
