/*C++ program to find number of days in a month*/

#include <iostream>
#include<ios> //to get stream size
#include<limits> //to get numeric limits

using namespace std;

int main(void) {
  int month = 0, year = 0, days = 0;

  /* Use integer array & array of pointers to save
  total days (normal year) & name of the months in monthly order */
  int total_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  const char* month_name[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August", "September",
    "October", "November", "December"
    };
  
  /* Get inputs (month & year) from user
  Run loop if input fails (no input, input out of range)*/
  while ((cout << "Enter month in number (1 - 12): ")
        && (!(cin >> month) || (month < 1) || (month > 12)))
  {
    cin.clear(); // clear bad input flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore input
    cout << "Invalid input. Try again.\n";
  }

  while ((cout << "Enter year (1582 - 9999): ")
        && (!(cin >> year) || (year < 1582) || (year > 9999)))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Note: Leap years started from 1582.\n";
  }

  /* Total days is 29 if user input Feb & leap year
  Leap year: divisible by 4, but not by 100. Unless divisible by 400 */
  if ((month == 2) && ((year%4 == 0 && year%100 != 0)||(year%400 == 0)))
  {
    days = 29;
  }
  /* Else: Get total days of month from saved array (index = month - 1)*/
  else
  {
    days = total_days[month-1];
  }

  /* Print out result
  Get name of month from saved array (index = month - 1) */
  cout << month_name[month-1] << " " << year << " " << "has "
  << days << " "  << "days\n";

  return 0;
}
