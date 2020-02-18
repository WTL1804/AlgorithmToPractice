//
//  main.c
//  买卖股票的最佳时机2
//
//  Created by 王天亮 on 2020/2/17.
//  Copyright © 2020 王天亮. All rights reserved.
//

#include <stdio.h>
int maxProfit(int* prices, int pricesSize){
    int sum = 0, temp = -1;
        for (int j = 0; j < pricesSize - 1; j++) {
            if (j == 0 && prices[j + 1] >= prices[j]) {
                temp = prices[j];
                printf("temp1:%d\n", temp);
                continue;
             } else if (j != 0 && prices[j - 1] >= prices[j] && prices[j + 1] >= prices[j]) {
                temp = prices[j];
                 printf("temp2:%d\n", temp);
                continue;
            }
            if (temp != -1 && prices[j + 1] <= prices[j] && prices[j - 1] < prices[j]) {
                sum = sum + prices[j] - temp;
                temp = -1;
                printf("sum1:%d\n", sum);
                continue;
            }
            if (temp != -1 && j == pricesSize - 2 && prices[j + 1] > prices[j]) {
                sum = sum + prices[j + 1] - temp;
                temp = -1;
                printf("sum2:%d\n", sum);
                continue;
            }
        }
    if (temp != -1 && prices[pricesSize - 1] > temp) {
        sum = sum + prices[pricesSize - 1] - temp;
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
