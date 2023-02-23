#include <stdio.h>

// function prototype
int convert_day(int month, int day);
void print_remaining_days(int month, int day, int year);

int convert_day(int month, int day)
{
        switch (month)
        {
                case 2:
                        day = 31 + day;
                        break;
                case 3:
                        day = 59 + day;
                        break;
                case 4:
                        day = 90 + day;
                        break;
                case 5:
                        day = 120 + day;
                        break;
                case 6:
                        day = 151 + day;
                        break;
                case 7:
                        day = 181 + day;
                        break;
                case 8:
                        day = 212 + day;
                        break;
                case 9:
                        day = 243 + day;
                        break;
                case 10:
                        day = 273 + day;
                        break;
                case 11:
                        day = 304 + day;
                        break;
                case 12:
                        day = 334 + day;
                        break;
                default:
                        break;
        }
        return (day);
}

int main(void)
{
        int month;
        int day;
        int year;

        month = 2;
        day = 29;
        year = 2000;

        printf("Date: %02d/%02d/%04d\n", month, day, year);

        day = convert_day(month, day);

        print_remaining_days(month, day, year);

        return (0);
}
/*
void print_remaining_days(int month, int day, int year)
{
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // days in each month
    int days_left = 0;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // check if it's a leap year
    {
        days_in_month[2] = 29; // update number of days in February
    }

    // Calculate the number of days left in the year
    for (int i = month; i <= 12; i++)
    {
        if (i == month)
        {
            days_left += (days_in_month[i] - day + 1);
        }
        else
        {
            days_left += days_in_month[i];
        }
    }

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        if (month > 2)
        {
            days_left++; // add an extra day for leap years if we've passed Feb. 29th
        }
    }

    printf("Day of the year: %d\n", day);
    printf("Remaining days: %d\n", days_left);
}
*/

void print_remaining_days(int month, int day, int year)
{
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
                if (month > 2 && day >= 60)
                {
                        day++;
                }

                printf("Day of the year: %d\n", day);
                printf("Remaining days: %d\n", 366 - day);
        }
        else
        {
                if (month == 2 && day == 60)
                {
                        printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
                }
                else
                {
                        printf("Day of the year: %d\n", day);
                        printf("Remaining days: %d\n", 365 - day);
                }
        }
}
