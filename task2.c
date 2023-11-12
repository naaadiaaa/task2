#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct users
{
    char username[50];
    char password[50];
    int activeFlag;
};

int linearSearch(struct users arr[], int size, char valName[20], char valPassword[20])
{
    for (int i = 0; i < size; i++)
        if ((strcmp(arr[i].username, valName) == 0) && (strcmp(arr[i].password, valPassword) == 0))
        {
            if (arr[i].activeFlag == 1)
            {
                return i;
            }
            else
            {
                return -2;
            }
        }

    return -1;
}

int main()
{

    struct users arrUsers[20];
    char name[50];
    char pass[50];
    static int arrCount = 0;
    int choise;

    while (1)
    {

        printf("\n\n\t\t.................... Choose an Order Please .................  \n");
        printf("\n\t\t\t\twe have  %d Acounts \n", arrCount);

        printf("1- Registration \n");
        printf("2- Login \n");
        printf("3- Exit \n");

        scanf("%d", &choise);

        // For  Registration

        if (choise == 1)
        {
            printf("\n\n\t\t\t For Registration \n\n");

            printf("Please Enter Your Name :");
            scanf("%s", arrUsers[arrCount].username);

            printf("Please Enter Your Password :");
            scanf("%s", arrUsers[arrCount].password);

            printf("For Activate Your Account Enter '1' else Enter '0':");
            scanf("%d", &(arrUsers[arrCount].activeFlag));

            if ((arrUsers[arrCount].activeFlag) == 1)
            {
                printf("\n\n\t\t  Registration Is Done  and your Account is Active \n\n ");
            }
            else if ((arrUsers[arrCount].activeFlag) == 0)
            {
                printf("\n\n\t\t  Registration Is Done  and your Account is Not Active  \n\n ");
            }
            arrCount++;
        }
        // For Login

        else if (choise == 2)
        {
            printf("\n\n\t\t For Login   \n\n");

            printf("Please Enter Your Name :");
            scanf("%s", name);

            printf("Please Enter Your Password :");
            scanf("%s", pass);

            long searchResult = linearSearch(arrUsers, arrCount, name, pass);
            // long resultPass = linear_password(arrUsers, arrCount, pass);

            if (searchResult != -1 && searchResult != -2)
            {
                printf("\n\t this Account is Active , Login Successfuly !!");
            }

            else if (searchResult == -2)
            {
                printf("\n\tthis Account is not Active So Login process Not Completed  !!");
            }

            else if (searchResult == -1)
            {
                printf("\n\tusernsme or password is Wrong !!");
            }
        }

        else
        {
            break;
        }
    }

    return 0;
}
