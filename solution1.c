// Solution for Date in String format to Structure conversion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_DATE_LENGTH 10 // Maximum length of the date string in DD/MM/YYYY format

typedef struct my_date_t{
 uint8_t date; // date
 uint8_t month; // month
 uint16_t year; // year
}my_date_t;

typedef enum status_t
{
    SUCCESS, // Function has successfully converted the string to structure
    NULL_PTR, // Function is given NULL pointers to work with
    INCORRECT // Incorrect values for date or month or year
}status_t;

// Function to convert string of the format DD/MM/YYYY to my_date_t structure
status_t string_to_date_converter(char* input_string, my_date_t* res_date) {
  // Check if the input pointers are valid
  if (input_string == NULL || res_date == NULL) {
    return NULL_PTR; // Return NULL_PTR status code
  }

  // Check if the input string has the correct length and format
  if (strlen(input_string) != MAX_DATE_LENGTH  || input_string[2] != '/' || input_string[5] != '/') {
    return INCORRECT; // Return INCORRECT status code
  }

  // Extract the date, month and year values from the input string using sscanf function
  int date, month, year;
  if (sscanf(input_string, "%d/%d/%d", &date, &month, &year) != 3) {
    return INCORRECT; // Return INCORRECT status code if sscanf fails
  }

  // Check if the date, month and year values are valid
  if (date < 1 || date > 31 || month < 1 || month > 12 || year < 0) {
    return INCORRECT; // Return INCORRECT status code if values are out of range
  }

  // Assign the date, month and year values to the result structure fields using type casting
  res_date->date = (uint8_t)date;
  res_date->month = (uint8_t)month;
  res_date->year = (uint16_t)year;

  return SUCCESS; // Return SUCCESS status code if conversion is done successfully
}

// A sample main function to test the string_to_date_converter function
int main() {
  char input_string[MAX_DATE_LENGTH] = "26/12/2021"; // A sample input string
  my_date_t res_date; // A variable to hold the result structure

  status_t status = string_to_date_converter(input_string, &res_date); // Call the function and store the status

  // Print different messages based on the status value
  switch (status) { 
    case SUCCESS:
      printf("Conversion successful!\n");
      printf("Date: %u\n", res_date.date);
      printf("Month: %u\n", res_date.month);
      printf("Year: %u\n", res_date.year);
      break;
    case NULL_PTR:
      printf("Conversion failed! Null pointers given.\n");
      break;
    case INCORRECT:
      printf("Conversion failed! Incorrect input string.\n");
      break;
    default:
      printf("Conversion failed! Unknown error.\n");
      break;
  }

}
