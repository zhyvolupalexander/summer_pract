// summerpract.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#define Pi 3.14

double find_area(double *x1, double *y1, double *r1, double *x2, double *y2, double *r2);

int main(void)
{
	double S, x1, y1, r1, x2, y2, r2;
	printf("Input x1:");
	scanf_s("%lf", &x1);
	printf("Input y1:");
	scanf_s("%lf", &y1);
	printf("Input r1:");
	scanf_s("%lf", &r1);
	printf("Input x2:");
	scanf_s("%lf", &x2);
	printf("Input y2:");
	scanf_s("%lf", &y2);
	printf("Input r2:");
	scanf_s("%lf", &r2);
	
	S=find_area(&x1, &y1, &r1, &x2, &y2, &r2);
	printf("S=%lf\n", S);
    return 0;
}
 

double find_area(double *x1, double *y1, double *r1, double *x2, double *y2, double *r2) {

	// Расстояние между центрами окружностей
	double distance = sqrt((*x1 - *x2) * (*x1 - *x2) + (*y1 - *y2) * (*y1 - *y2));
	double f1, f2;
	double s1, s2;
	if (distance >= *r1 + *r2) {
		// Если не пересекаются 
		printf("circles do not intersect\n");
		return 0;
	}
	else if (distance <= fabs(*r1 - *r2)) {
		// Если круг внутри другого круга
		if (*r1 >= *r2)
		{
			printf("circle 2 is inside circle 1\n");
			return 0;
		}
		else
		{
			printf("circle 1 is inside circle 2\n");
			return 0;
		}
	}
	else {
		// Если пересекаются
		f1 = 2 * acos((*r1*(*r1) - *r2*(*r2) + distance*distance) / (2 * (*r1) * distance));
		f2 = 2 * acos((*r2*(*r2) - *r1*(*r1) + distance*distance) / (2 * (*r2) * distance));
		s1 = (*r1*(*r1) * (f1 - sin(f1))) / 2;
		s2 = (*r2*(*r2) * (f2 - sin(f2))) / 2;
		return  s1 + s2;
	}
	return 0;
}
