#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CURR_TOTAL 11

const char *currencies[CURR_TOTAL] = { "AUD", "CAD", "CHF", "CNY", "EUR", "GBP", "HKD", "ILS", "JPY", "MXN", "USD" };
const char *curr_fullnames[CURR_TOTAL] = {
	"Australian dollar",
	"Canadian dollar",
	"Swiss franc",
	"Chinese yuan",
	"Euro",
	"Pound Sterling",
	"Hong Kong dollar",
	"Israeli new shekel",
	"Japanese yen",
	"Mexican peso",
	"United States dollar",
};
const int denominations[CURR_TOTAL][16] = {
	{   10000,   5000,   2000,   1000,   500,   200,  100,   50,  20,  10,  5,  2,  1,  0, 0, 0 }, /* AUD */
	{   10000,   5000,   2000,   1000,   500,   200,  100,   25,  10,   5,  1,  0,  0,  0, 0, 0 }, /* CAD */
	{  100000,  20000,  10000,   5000,  2000,  1000,  500,  200, 100,  50, 20, 10,  5,  0, 0, 0 }, /* CHF */
	{   10000,   5000,   2000,   1000,   500,   100,   50,   20,  10,   5,  2,  1,  0,  0, 0, 0 }, /* CNY */
	{   50000,  20000,  10000,   5000,  2000,  1000,  500,  200, 100,  50, 20, 10,  5,  2, 1, 0 }, /* EUR */
	{    5000,   2000,   1000,    500,   200,   100,   50,   20,  10,   5,  2,  1,  0,  0, 0, 0 }, /* GBP */
	{  100000,  50000,  10000,   5000,  2000,  1000,  500,  200, 100,  50, 20, 10,  0,  0, 0, 0 }, /* HKD */
	{   20000,  10000,   5000,   2000,  1000,   500,  200,  100,  50,  10,  0,  0,  0,  0, 0, 0 }, /* ILS */
	{ 1000000, 500000, 200000, 100000, 50000, 10000, 5000, 1000, 500, 100,  0,  0,  0,  0, 0, 0 }, /* JPY */
	{  100000,  50000,  20000,  10000,  5000,  2000, 1000,  500, 200, 100, 50, 25, 20, 10, 5, 0 }, /* MXN */
	{   10000,   5000,   2000,   1000,   500,   200,  100,   50,  25,  10,  5,  1,  0,  0, 0, 0 }, /* USD */
};

void strupper(char *s)
{
	while(*s != '\0') {
		*s = toupper(*s);
		s++;
	}
}

int get_currency()
{
	int i;
	printf("Currencies: \n");
	for (i = 0; i < CURR_TOTAL; i++) {
		printf("%s: %s\n", currencies[i], curr_fullnames[i]);
	}

	while (1) {
		char input[512];
		int i;

		printf("Select currency ('q' to quit): ");
		fgets(input, 512, stdin);
		strtok(input, "\n"); /* remove newline */
		strupper(input);

		if (input[0] == 'Q') {
			printf("Quitting...\n");
			exit(EXIT_SUCCESS);
		}
		for (i = 0; i < CURR_TOTAL; i++) {
			if (strcmp(input, currencies[i]) == 0)
				return i;
		}
	}
}

int main() {
	int total = 0;
	int i;
	int curr = get_currency();

	printf("\n");
	for (i = 0; i < 16; i++) {
		char input[512];
		int number;

		if (denominations[curr][i] == 0) break;

		printf("%8.2f: ", denominations[curr][i] / 100.0);

		fgets(input, 512, stdin);
		number = atoi(input);

		total += number * denominations[curr][i];
		printf("               = %6.2f %s\n", total / 100.0, currencies[curr]);
	}

	return 0;
}
