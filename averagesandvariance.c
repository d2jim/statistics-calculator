#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Data2 {
    int datapts;        //number of datapts
};

void computeMean(float a[], int n);
void computeMedian(float a[],int n);
void computeMode(float a[],int n);
void swap(float *p,float *q);
void computeVarStdDev(float a[],int n);

void averagesandvariancemain() {
    struct Data2 userInput;
    int i;

    system("cls");
    printf("****AVERAGES AND VARIANCE****\n\nNumber of data points inputting: ");
    scanf("%d", &userInput.datapts);
    printf("\nBegin entering data points: \n");
    float dataArray[userInput.datapts - 1];     //data point array
    for (i = 0;i < userInput.datapts;i++) {
            scanf("%f", &dataArray[i]);
    }

    printf("\n\nMean:                ");
    computeMean(dataArray, userInput.datapts);
    printf("\nMedian:              ");
    computeMedian(dataArray, userInput.datapts);
    printf("\nMode:                ");
    computeMode(dataArray, userInput.datapts);
    computeVarStdDev(dataArray,userInput.datapts);
}

void computeMean(float a[], int n) {
    float sum = 0,mean;
    int i;

    for (i = 0;i < n;i++) {
        sum = sum + a[i];
    }
    mean = sum / n;
    printf("%.2f", mean);
    printf("\nSum:                 %.2f", sum);
    return;
}

void computeMedian(float a[],int n) {
    int i,j, median;
    float temp = 2.00, range;

    for(i = 0;i < n-1;i++) {
        for(j = 0;j < n-i-1;j++) {
            if(a[j] > a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }

    if (n % 2 == 0) {
        median = (n+1) / 2 - 1;      // -1 as array indexing in C starts from 0
        temp = (a[median] + a[median+1]) / temp;
        printf("%.2f", temp);
    }
    else {
        median = (n+1) / 2 - 1;      // -1 as array indexing in C starts from 0
        printf("%.2f", a[median]);
    }
    range = a[n-1] - a[0];
    printf("\nRange:               %.2f", range);
}

void swap(float *p,float *q) {
   int t;

   t=*p;
   *p=*q;
   *q=t;
}

void computeMode(float a[],int n) {
   float maxValue = 0;
   int maxCount = 0, i, j;

   for (i = 0; i < n; ++i) {
      int count = 0;

      for (j = 0; j < n; ++j) {
         if (a[j] == a[i])
         ++count;
      }
      if (count > maxCount) {
         maxCount = count;
         maxValue = a[i];
      }
   }
   printf("%.2f\n", maxValue);
   return;
}

void computeVarStdDev(float a[],int n) {
    int  i;
    float average, variance, std_deviation,cv,  sum = 0, sum1 = 0;

    for (i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    average = sum / (float)n;
    /*  Compute  variance  and standard deviation  */
    for (i = 0; i < n; i++)
    {
        sum1 = sum1 + pow((a[i] - average), 2);
    }
    variance = sum1 / (float)n;
    cv = (variance / (sum / n));
    std_deviation = sqrt(variance);
    printf("SumSq:               %.2f\n", sum * sum);
    printf("Variance:            %.2f\n", variance);
    printf("CV:                  %f\n",  cv);
    printf("Standard Deviation:  %.2f\n", std_deviation);
    return;
}


