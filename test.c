#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
    float temprature_value=0;
    int integer = 0;
    int decimals = 0;
    unsigned char uart_ctrl_set_buf[60];
#if 0    
    char json_value[] = "23.00000000000";

     /*get the target temprature value from the json vale. *10 to get the decimals.*/
    temprature_value = atof(json_value)*10;
    printf("json_valueing=%s, temprature_value=%d\n", json_value, temprature_value);

     integer = temprature_value/10;
     decimals = temprature_value%10;
    printf("integer=%d xiaoshu=%d\n", integer, decimals);

    if (decimals!=0) /* means we need to add 0.5C more */
    {
        uart_ctrl_set_buf[5]|=1;
        printf("need to add 0.5 for setting !\n");
    }
#else
    char json_value[60] = {0};

    integer = 22;
    decimals = 0;
    /*temprature_value = integer + ((float)decimals/10);
    gcvt(temprature_value, 50, json_value);*/
    itoa(integer,json_value,10);
    if(decimals!=0)
    {
        strcat(json_value,".50");        
    }
    else
    {
        strcat(json_value,".00"); 
    }
    printf("json_value=%s, temprature_value=%lf \n", json_value, temprature_value);
#endif
    system("pause");
    return 0;
}