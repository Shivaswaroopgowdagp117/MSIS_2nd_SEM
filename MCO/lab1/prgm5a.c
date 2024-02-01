#include <stdio.h>
#include <time.h>
int main()
{
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    char formatted_time[80];
    strftime(formatted_time, sizeof(formatted_time), "%A, %B %d, %Y %H:%M:%S", local_time);
    printf("Current Time :%s\n",formatted_time);
    return 0;
}



/*

%a: Abbreviated weekday name (e.g., "Mon")
%A: Full weekday name (e.g., "Monday")
%b: Abbreviated month name (e.g., "Jan")
%B: Full month name (e.g., "January")
%C: Century as decimal number (e.g., 20)
%d: Day of the month (01-31)
%H: Hour in 24-hour format (00-23)
%I: Hour in 12-hour format (01-12)
%m: Month as a decimal number (01-12)
%M: Minute (00-59)
%p: AM/PM indicator (e.g., "AM")
%S: Second (00-59)
%Y: Year with century as a decimal number (e.g., 2024)

*/