//
// Created by Oskar on 26.02.2025.
//

#include <stdio.h>
#include <string.h>

char compress[50];

int main()
{
    printf("Enter a String that you want to compress: ");
    scanf("%s",compress);
    printf("The length of the Word is: %llu \n",strlen(compress));
    printf("The Word befor compress is: %s \n",compress);

    for (int j = 0; j < strlen(compress);)
    {
        //printf("%c",compress[j]);
        int k=1;
        while (compress[j] == compress[j+1])
        {
          j++;
          k++;
        }
        if (k == 1) {printf("%c",compress[j]);}
        else {printf("%d%c",k,compress[j]);}
        j++;
    }

}