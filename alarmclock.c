#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct Alarm
{
    time_t setTime;
};

void setAlarm(struct Alarm alarms[], int *pos)
{

    char date[10];
    char timestamp[8];
    char str[20];


    printf("Schedule alarm at which date? ");
    scanf("%s", date);
    printf("and time? ");
    scanf("%s", timestamp);
    
    printf("Date: %s\n", date);
    printf("Time: %s\n", timestamp);

    strlcat(str, date, 10);
    strlcat(str, " ", 1);
    strlcat(str, timestamp, 8);

    printf("%s", str);

    struct tm t;
    strptime(str, "%Y-%m-%s %H:%M:%S", &t);

    alarms[*pos].setTime = mktime(&t);
    *pos += 1;

    // fork();
}

void listAlarms(struct Alarm *alarms) {
    for (int i = 0; i < 10; i++)
    {
        printf("");
    }
    
}

int main()
{
    char choice;
    time_t current_time;

    current_time = time(NULL);

    printf("Welcome to the alarm clock! It is currently %s", ctime(&current_time));
    printf("Please enter \"s\" (schedule), \"l\" (list), \"c\" (cancel), \"x\" (exit)\n");
    scanf("%c", &choice);

    struct Alarm alarms[10];
    int countAlarms = 0;

    if (!strcmp(&choice, "s"))
    {
        setAlarm(alarms, &countAlarms);
        printf("Num alarms: %d\n", countAlarms);
    }
    else if (!strcmp(&choice, "l"))
    {
        listAlarms(alarms);
    }
    else if (!strcmp(&choice, "c") || !strcmp(&choice, "x"))
    {
        // code here
    }

    return 0;
}