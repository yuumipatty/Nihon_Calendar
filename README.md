Nihon Calendar

This is a simple C program that generates a Japanese calendar for a given month and year. It calculates the start day of the week and prints a calendar for that month. The calendar is displayed with both Japanese and English month names, as well as the Japanese era (e.g., Heisei, Reiwa).
Features

    Displays Japanese calendar: The program prints a calendar for the selected month and year with Japanese month names.
    Supports leap years: The program correctly accounts for leap years, adjusting February to 29 days when necessary.
    Displays day of the week: The program calculates and displays the starting day of the week for the given month.
    Japanese Era: The program displays the Japanese era (e.g., Reiwa, Heisei) based on the input year.

How It Works

    The program takes the month and year as input from the user.
    It calculates the starting day of the week for the first day of the given month using a simple formula.
    It then prints the calendar, where:
        The first line shows the year in the Japanese era format.
        The second line shows the month name in both Japanese and English.
        The calendar is printed with the days of the week and corresponding dates.
    The calendar is printed with the days of the week in both English and Japanese (e.g., Sun/日, Mon/月, etc.).
    It accounts for leap years and adjusts the number of days in February.

Functions
dayOfWeek(int d, int m, int y)

This function calculates the day of the week for a given date. It returns a value between 0 (Sunday) and 6 (Saturday).

    Parameters:
        d: The day of the month.
        m: The month (1-12).
        y: The year.

    Returns: An integer corresponding to the day of the week (0-6).

getJapaneseEra(int year)

This function returns the Japanese era for a given year. Currently, it supports the Reiwa and Heisei eras.

    Parameters:
        year: The year for which to determine the Japanese era.

    Returns: A string representing the era (e.g., "令和", "平成").

main()

The main() function handles user input, calculates the day of the week, adjusts for leap years, and prints the calendar for the given month and year.
Leap Year Handling

The program checks if the year is a leap year using the following conditions:

    A year is a leap year if it is divisible by 4.
    However, if the year is divisible by 100, it must also be divisible by 400 to be a leap year.

For example:

    2020 is a leap year (because it is divisible by 4 but not by 100).
    2024 is also a leap year (divisible by 4, not divisible by 100).
    2023 is not a leap year.

License

This project is licensed under the MIT License - see the LICENSE file for details.
Contributing

##    Fork this repository.
##    Make your changes or improvements.
##    Submit a pull request.


 Getting Started

To use this program, you need to have a C compiler such as gcc installed on your system. Below are the steps to compile and run the program:
Prerequisites

Make sure you have a C compiler installed. On Linux, you can install GCC with the following command:
sudo apt install gcc
Running the Program

    Clone or download the repository to your local machine.

 #   Navigate to the folder containing the main.c file.

#    Compile the C program using gcc:
    gcc -o calendar main.c
#    Run the program:
    ./calendar
        Enter the month (1-12) and year when prompted, and the calendar for that month and year will be displayed.

Example Output

If you enter the month as 5 (May) and the year as 2024.
