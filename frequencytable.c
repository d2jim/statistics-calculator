#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Data {
    float ucl;          //upper class limit
    float lcl;          //lower class limit
    float relativefreq; //holds/calculates relative frequency
    float classWidth;   //class width   (ucl - lcl / classnum)
    int datapts;        //number of datapts
    int classfreq;      //placeholder/tallies class frequency
    int classNum;       //number of classes
};

void freqtablemain() {
    struct Data table_1;
    int i;                      //interval holder
    int j;                      //interval holder
    int r;                      //interval holder
    int classWidth2;            //rounded up class width
    float userNum;              //input placeholder
    float placeholder = 1.0;

    table_1.ucl = -5000000;
    table_1.lcl = 5000000;
    system("cls");

    printf("****FREQUENCY TABLE****\n\nNumber of data points inputting: ");
    scanf("%d", &table_1.datapts);
    printf("Number of classes (between 5 & 15): ");
    scanf("%d", &table_1.classNum);
    float userNums[table_1.datapts - 1];                // initialize array that holds data points
    printf("Begin entering data points: \n");
    fflush(stdin);

    for (i = 0;i < table_1.datapts;i++) {
        scanf("%f ", &userNum);                         //grabs user input
        userNums[i] = userNum;                          //saves user input to array
        if (userNum > table_1.ucl) {                    //determines if point is the highest data pt
            table_1.ucl = userNum;
        }
        if (userNum < table_1.lcl) {                    //determines if point is the lowest data pt
            table_1.lcl = userNum;
        }
    }

    table_1.classWidth = (table_1.ucl - table_1.lcl) / table_1.classNum;        //calculates class width
    classWidth2 = ceil(table_1.classWidth);                                     //rounds class width up
    printf("\n\nClass width is: %d", classWidth2);

    float midpoint[table_1.classNum];                   // initialize array that holds class midpoints
    float classArray[table_1.classNum][2];              // initialize array that holds class parameters
    int classfreqArray[table_1.classNum - 1];           // initialize array that holds class frequency

    classArray[0][0] = table_1.lcl - 0.5;               // establishes first lower class parameter
    classArray[0][1] = classArray[0][0] + classWidth2;  // establishes first upper class parameter

    printf("\n\n****Class Boundaries****    ****Frequency****\n      %.2f --  %.2f", classArray[0][0], classArray[0][1]);
    table_1.classfreq = 0;
    for (r = 0;r < table_1.datapts; r++) {
        if (userNums[r] > classArray[0][0] && userNums[r] < classArray[0][1]) {
            table_1.classfreq++;
        }
    }
    printf("             %d", table_1.classfreq);
    classfreqArray[0] = table_1.classfreq;

    for (i = 1;i < table_1.classNum;i++) {          //sets class boundaries
        for (j = 0;j < 2; j++){
            if (j == 0) {
                classArray[i][j] = classArray[i - 1][j + 1];
                printf("\n      %.2f --", classArray[i][j]);
            }
            else {
                classArray[i][j] = classArray[i][j - 1] + table_1.classWidth;
                printf("  %.2f ", classArray[i][j]);
                table_1.classfreq = 0;
                for (r = 0;r < table_1.datapts; r++) {          //tallies frequencies
                    if (userNums[r] < classArray[i][j] && userNums[r] > classArray[i][j - 1]) {
                        table_1.classfreq++;
                    }
                }
                printf("            %d", table_1.classfreq);
                classfreqArray[i] = table_1.classfreq;          //places frequency in array after it's finished being tallied
            }
        }
    }

    printf("\n\n****Class Midpoints****     ****Relative Frequency****\n");
    for (i = 0;i < table_1.classNum;i++) {
        midpoint[i] = (classArray[i][0] + classArray[i][1]) / 2;                    //midpoint equation
        printf("        %.2f    ", midpoint[i]);
        table_1.relativefreq = classfreqArray[i] / (table_1.datapts * placeholder); //relative frequency equation
        printf("               %.2f\n", table_1.relativefreq);
    }

    return;
}
