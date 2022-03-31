#include <stdio.h>
#include <math.h>

float datax[] = {};
float datay[] = {};
float n =0;

float dis(float x, float y, float a, float b) {
    return abs(a * x - y + b) / sqrt(a * a + b * b);
}

float f(float a, float b) {
    float sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += dis(datax[i], datay[i], a, b);
    }
    return sum / n;
}

float dfxydx(float x, float y, float d) {
    return (f(x + d, y) - f(x, y)) / d;
}

float dfxydy(float x, float y, float d) {
    return (f(x, y-d) - f(x, y)) / d;
}

int main()
{
    
    for (int i = 0; i <= 40; i++)
    {
        datax[i] = i-0.3;
        datay[i] = i+0.3;
        n += i;
        printf("%f %f\n", datax[i], datay[i]);
    }

    float da = 0.01;
    float db = 0.01;
    float psi  = 0.05;
    float a0 = 0;
    float b0 = 0;
    float a1 = 1;
    float b1 = 1;

    for(int i = 0; i<500; i++) {
        a0 = a1;
        b0 = b1;
        a1 -= psi  * dfxydx(a0,b0,da);
        b1 -= psi  * dfxydy(a0,b0,db);
    }

    printf("y = %fx + %f\n", a1, b1);

    return 0;
}
