#include <stdio.h>
#define delayLine 3
#define signalSize 4

void arrayInput(double arr[], int arrSize);

int main(){
    //init
    double num[delayLine] = {1, 2, 3};
    int signal[signalSize] = {1, 2, 3, 4};
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
        Wn[0] = signal[i];
        
        double sum = 0;
        for(int j = 0; j < delayLine; j++)
        {
            sum += Wn[j] * num[j];
        }


        printf("%f", sum);
        printf("\n");
    }
}

// void arrayInput(double arr[], int arrSize){
//     printf("The array size is %d", arrSize);
//     for(int i = 0; i < arrSize; i++){
//         scanf("%d", &arr[i]);
//     }
// }