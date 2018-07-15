#include <stdlib.h>
#include <stdio.h>
int main()
{
    int temprature_value;
    unsigned char uart_ctrl_set_buf[60];
    char json_value[] = "23.00000000000";

     /*get the target temprature value from the json vale. *10 to get the decimals.*/
    temprature_value = atof(json_value)*10;
    printf("json_valueing=%s, temprature_value=%d\n", json_value, temprature_value);

    int integer = temprature_value/10;
    int decimals = temprature_value%10;
    printf("integer=%d xiaoshu=%d\n", integer, decimals);

    if (decimals!=0) /* means we need to add 0.5C more */
    {
        uart_ctrl_set_buf[5]|=1;
        printf("need to add 0.5 for setting !\n");
    }
    system("pause");
    return 0;
}