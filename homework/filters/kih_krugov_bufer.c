#include <stdio.h>
#define delayLine 3
#define signalSize 4

void arrayInput(double arr[], int arrSize);
struct delay
{
    struct delay *previous;
    double weight;
    struct delay *next;
};


int main(){
    //init
    double num[delayLine] = {1, 2, 3};
    int signal[signalSize] = {1, 2, 3, 4};
    
    
    // delay line init
    struct delay Wn[delayLine];
    Wn[0].previous = &Wn[delayLine-1];
    Wn[0].weight = 0;
    Wn[0].next = &Wn[1];

    for(int i = 1; i < delayLine-1; i++){
        Wn[i].previous = &Wn[i-1];
        Wn[i].weight = 0;
        Wn[i].next = &Wn[i+1];
    }
    Wn[delayLine-1].previous = &Wn[delayLine-2];
    Wn[delayLine-1].weight = 0;
    Wn[delayLine-1].next = &Wn[0];
    
    struct delay *head = &Wn[0];


    for(int i = 0; i < signalSize; i++){
        //delay line
        head = head->previous;
        head->weight = signal[i];
        
        double sum = 0;
        struct delay *temp = head;
        for(int j = 0; j < delayLine; j++)
        {
            sum += temp->weight * num[j];
            temp = temp->next;
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