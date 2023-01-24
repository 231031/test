#include <ctype.h>
#include <stdio.h>
#include <string.h>
// Validate the license plate according to the following format
//     A-Z  A-Z  -  0-9  0-9  0-9  0-9
// Parameter: str - the string to validate the format
// Return: 1 if the format of str is valid
//         0 if the format of str is not valid
int validateLicensePlate(char str[])
{
    printf("%c",str[6]);
    if (strlen(str) != 8) // str[8] = '\n'
    {
        return 0;
    }
    if (str[7] != '\n')
    {
        return 0;
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (i == 0 || i == 1)
        {
            if (isupper(str[0]) == 0 || isupper(str[1]) == 0)
            {
                return 0;
            }
        }
        else if (i == 2)
        {
            if (str[2] != '-')
            {
                return 0;
            }
        }
        else if (i == 3 || i == 4 || i == 5 || i == 6 ) 
        {
            if (isdigit(str[3] == 0) || isdigit(str[3]) == 0 || isdigit(str[4] == 0) || isdigit(str[5]) == 0 || isdigit(str[6]) == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main(void)
{
    char str[32];

    // รับค่าจากผู้ใช้เก็บในตัวแปร str
    fgets(str, 32, stdin);

    // ตรวจสอบเลขทะเบียน
    if (validateLicensePlate(str))
    {
        printf("Correct format");
    }
    else
    {
        printf("Invalid format");
    }

    return 0;
}