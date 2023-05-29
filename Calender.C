#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int get_first_weekDay(int year)
{
    int day;
    day = (((year - 1)* 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;
}

int main()
{
	system("color 3F");
	//This declaration is for the case 1
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int date, mon, year, i, r, s = 0;
    char week[7][10],choice;
    strcpy(week[0], "Sunday");
    strcpy(week[1], "Monday");
    strcpy(week[2], "Tuesday");
    strcpy(week[3], "Wednesday");
    strcpy(week[4], "Thursday");
    strcpy(week[5], "Friday");
    strcpy(week[6], "Saturday");

    //This is the declaration for the case 2
    int day=0,dayInMonth,weekDay=0,startingDay,a;
    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
        int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};

    while(1) {
      printf("1. Find the day\n");
      printf("2. Print the calender of the desired year\n");
      printf("3. Check whether the year is a leap year\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("\n%c", &choice);
      switch(choice) {

        case '1':
           printf("Enter a valid date (dd/mm/yyyy) : ");
           scanf("%d / %d / %d", &date, &mon, &year);
           if( (year / 4 == 0) && (year % 400 == 0) && (year % 100 != 0))
           month[1] = 29;
           for(i = 0 ; i < mon - 1 ; i++)
           s = s + month[i];
           s = s + (date + year + (year / 4) - 2);
           s = s % 7;
           printf("\nThe day is : %s", week[s]);
           getch();
           break;

        case '2':
           printf("Enter your desired year: ");
           scanf("%d",&year);
           if((year%4==0&&year%100!=0)||year%400==0)
           {
            monthDays[1]=29;
           }
            startingDay=get_first_weekDay(year);
            for(a=0;a<12;a++)
           {
            dayInMonth=monthDays[a]+1;
            printf("\n\n------------------%s----------------",months[a]);
            printf("\n  Sun   Mon  Tue  Wed  Thurs Fri  Sat\n");
            for(weekDay=0;weekDay<startingDay;weekDay++)
            {
            printf("     ");
            }
            for(day=1;day<dayInMonth;day++)
            {
            printf("%5d",day);
            if(++weekDay>6)
            {
                printf("\n");
                weekDay=0;
            }
            startingDay=weekDay;
            }
           }


        case '3':
            printf("Enter a year: ");
            scanf("%d", &year);
            if (year % 400 == 0) {
             printf("%d is a leap year.", year);
            }
             else if (year % 100 == 0) {
             printf("%d is not a leap year.", year);
            }
             else if (year % 4 == 0) {
             printf("%d is a leap year.", year);
            }
             else {
             printf("%d is not a leap year.", year);
            }

   return 0;

        case '4':
            printf("Bye!!");
            exit(0);
            break;


         default:
        printf("Not a valid option\n");
        break;
      }
    }
    return 0;
}
