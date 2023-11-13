#include <stdio.h>
#define delayLine 3
#define signalSize 4

void arrayInput(double arr[], int arrSize);
\
int main(){
    //init
    double num[delayLine] = {2, 2, 3};
    double den[delayLine] = {1, 3, 4};
    int signal[signalSize] = {5, 6, 7, 8};
    int Wn [delayLine];
    for( int i = 0; i < delayLine; i++){
        Wn[i] = 0;
    }
    

    for(int i = 0; i < signalSize; i++){
        //delay line
        for(int j = delayLine-1; j > 0; j--)
        {
            Wn[j] = Wn[j-1];
        }
        
        double sumLeft = 0;
        for(int j = 1; j < delayLine; j++)
        {
            sumLeft += Wn[j] * (-den[j]);
        }
        Wn[0] = signal[i] + sumLeft;

        double sumRight = 0;
        for(int j = 0; j < delayLine; j++)
        {
            sumRight += Wn[j] * num[j];
        }
        printf("%f", sumRight);
        printf("\n");
    }
}

// void arrayInput(double arr[], int arrSize){
//     printf("The array size is %d", arrSize);
//     for(int i = 0; i < arrSize; i++){
//         scanf("%d", &arr[i]);
//     }
// }