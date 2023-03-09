#include <stdio.h>
#include <conio.h>
#include "graphics.h"
void DrawLine(int X, int Y, int heightLine, int lineColor){//?????????? ??????? ??? ????????? ??? ???????? ????????? ??? ????????? ?????
	setcolor(lineColor);//?????
	line(X, Y, X, Y-heightLine);//?????????? ??????? ?? ??????
}
int Filter1(int carretArraySize, int carretArray[], int testData[], int length, int counter, int result){
	initwindow(800,800);
    for (int currentPosition = 0; currentPosition < length; currentPosition++)
    {
        for (int i = 0; i < carretArraySize; i++)
        {
            int currentIndex = i + currentPosition;
            if (currentIndex >= length)
            {
                currentIndex = currentIndex - length;
            }
            carretArray[i] = testData[currentIndex];
        }
        for (int i = 0; i < carretArraySize; i++)
        {
            for (int j = 0; j < carretArraySize - 1; j++)
            {
                if (carretArray[j] > carretArray[i])
                {
                    carretArray[i] += carretArray[j];
                    carretArray[j] = carretArray[i] - carretArray[j];
                    carretArray[i] -= carretArray[j];
                }
            }
        }
        result = carretArray[carretArraySize / 2];
        printf("%d ", result);
    }
	return result;
}
int main()
{
	int result = 0;
	int resData[result];
    int testData[800];
    int counter = 800;
    for(int i = 0; i < 800; i++)
    {
    	testData[i]= rand() % 100;
	}
    int length = sizeof testData / sizeof testData[0];
    for(int i = 0; i <length; i++)
    {
        printf("%d ", testData[i]);
    }
    printf("\n");
    const int carretArraySize = 3;
    int carretArray[3];
    printf("Created an array of size %ld\n", sizeof(carretArray) / sizeof(carretArray[0]));
    Filter1(carretArraySize, carretArray, testData, length, counter, result);//?????? ???????
    for(int i = 0; i<=counter; i++)
   	{
   		DrawLine(1 + 1* i, 300-1,testData[i]*2, 2);
    	DrawLine(1 + 1* i, 600-1,resData[i]*2, 4);
	}
	getch();

}














