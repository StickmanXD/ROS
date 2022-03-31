#include <stdio.h>
#include <math.h>

float x[4] = {1, 4, 7, 10};
float y[4] = {81, 93, 91, 97};

float aver(float arr[]);
float fx1(float a[], float b[], float aa, float ab);
float fx2(float a, float b, float c);

int main()
{
    float aver_x = aver(x);
    float aver_y = aver(y);
    printf("Average x = %f\n",aver_x);
    printf("Average y = %f\n",aver_y);
    float incline = fx1(x, y, aver_x, aver_y);
    float y_intercept = fx2(aver_x, aver_y, incline);

    printf("y = %fx + %f\n", incline, y_intercept);

    return 0;
}

float aver(float arr[]) {
	int i = 0;
    float sum = 0;
    float average = 0;
    int size = sizeof(arr)/2;
    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    average = sum / i;
    return average;
}

float fx1(float a[], float b[], float aa, float ab) {
    float sum1, sum2, sum_x, sum_y;
    float x1, y1;
    for (int i = 0; i < (sizeof(a) / sizeof(float)); i++)
    {
        x1 = a[i] - aa;
        y1 = b[i] - ab;

        sum1 += x1 * y1;

        sum2 += x1 * x1;
    }

    return sum1 / sum2;
}

float fx2(float a, float b, float c) {
    return b - (a * c);
}
