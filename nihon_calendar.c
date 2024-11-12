#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array to store Japanese month names and their English translations
char japaneseMonths[12][3][20] = {
    {"睦月", "Mutsuki", "Harmony"},
    {"如月", "Kisaragi", "Lunar"},
    {"弥生", "Yayoi", "Growth"},
    {"卯月", "Uzuki", "Plentiful"},
    {"皐月", "Satsuki", "Refreshing"},
    {"水無月", "Minazuki", "Dry"},
    {"文月", "Fumizuki", "Fragrant"},
    {"葉月", "Hazuki", "Autumn Leaves"},
    {"長月", "Nagatsuki", "Long"},
    {"神無月", "Kannazuki", "Godless"},
    {"霜月", "Shimotsuki", "Winter Solstice"},
    {"師走", "Shiwasu", "End-of-Year Prayers"}
};

// Array to store the number of days in each month (assuming a non-leap year)
int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to calculate the day of the week (0 = Sunday, 1 = Monday, ...)
int dayOfWeek(int d, int m, int y) {
    int t;
    int y0 = y - (m < 3);
    return (y0 + y0 / 4 - y0 / 100 + y0 / 400 + (13 * (m + 1)) / 5 + d) % 7;
}

// Function to get the Japanese era name for a given year
char* getJapaneseEra(int year) {
    if (year >= 2019) {
        return "令和"; // Reiwa
    } else if (year >= 1989) {
        return "平成"; // Heisei
    }
    return "Unknown Era";
}

int main() {
    int month, year;

    // Get user input for month and year
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    // Adjust for leap year
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        daysInMonth[1] = 29; // February has 29 days in a leap year
    }

    // Make sure month input is valid
    if (month < 1 || month > 12) {
        printf("Invalid month! Please enter a number between 1 and 12.\n");
        return 1;
    }

    // Calculate the starting day of the week for the given month and year
    int startingDayOfWeek = dayOfWeek(1, month, year);

    // Print the calendar header
    char* eraName = getJapaneseEra(year);
    printf("\n\t\t%s %d 年 (%s)\n", eraName, year, japaneseMonths[month - 1][1]);
    printf("\t\t----------------------------------------------------\n");
    printf("\t\tSun Mon Tue Wed Thu Fri Sat\n");
    printf("\t\t日 月 火 水 木 金 土\n");
    printf("\t\t----------------------------------------------------\n");

    // Print the calendar body
    int day = 1;
    for (int i = 0; i < startingDayOfWeek; i++) {
        printf("\t\t  "); // Print spaces until the first day
    }

    // Loop through each day of the month
    for (int i = 1; i <= daysInMonth[month - 1]; i++) {
        printf("\t\t%2d ", day++);
        
        // Start a new line after Saturday
        if (i % 7 == 0) {
            printf("\n");
        }
    }

    // If the last line of the calendar is not filled, print a newline
    if ((daysInMonth[month - 1] + startingDayOfWeek) % 7 != 0) {
        printf("\n");
    }

    printf("\n");
    return 0;
}