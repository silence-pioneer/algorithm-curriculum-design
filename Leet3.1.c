#include <stdio.h>
#include <stdlib.h>
int maxProfit(int* prices, int pricesSize) {
    int min = 0;
    int* maxprices;
    maxprices = (int*)malloc(sizeof(int) * pricesSize);
    maxprices[0]=0;
    for(int i = 1; i < pricesSize; i++){
        int a=prices[i]-prices[min];
        if(a>maxprices[i-1]) 
            maxprices[i] = a;
        else maxprices[i] = maxprices[i-1];
        if(a<0) min = i;
    }
    int result = maxprices[pricesSize-1];
    free(maxprices);
    return result;
}   
int main(){
    int prices[] = {7,1,5,3,6,4};
    int size = sizeof(prices)/sizeof(prices[0]);
    printf("%d",maxProfit(prices,size));
    return 0;
}