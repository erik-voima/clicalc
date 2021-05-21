#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int exitcheck(char text[]) {
	if (strcmp(text, "EXIT\n") == 0) return 1;		// \n here because there is going to be a newline in the string produced by fgets()
	else return 0;
}

int main() {
	// declarations
	double x, y, z;						// number variables
	char buf[1024];						// used for number inputs (with fgets() and strtod())
	char *ptr;						// endpoint for strtod()
	char op[6];						// operator, will be used to figure out what to calculate
	
	// some "start-up" code
	printf("Command-Line Calculator\n");
	printf("-----------------------\n");
	printf("\"EXIT\" to quit (or CTRL-C, of course)\n");
	
	// actual code
	fgets(buf, 1024, stdin);				// first number input (x)
	if (exitcheck(buf) == 1) return 0;
	x = strtod(buf, &ptr);					// convert char* (buf) to double

	fgets(op, 6, stdin);
	if (exitcheck(op) == 1) return 0;

	if (strcmp(op, "sqrt\n") == 0) {
		z = sqrt(x);
	} else if (strcmp(op, "cbrt\n") == 0) {
		z = cbrt(x);
	} else {
		fgets(buf, 1024, stdin);			// second number input (y)
		if (exitcheck(buf) == 1) return 0;
		y = strtod(buf, &ptr);	

		if (strcmp(op, "+\n") == 0) {
			z = x + y;
		} else if (strcmp(op, "-\n") == 0) {
			z = x - y;
		} else if (strcmp(op, "x\n") == 0) {
			z = x * y;
		} else if (strcmp(op, "/\n") == 0) {
			z = x / y;
		} else if (strcmp(op, "^\n") == 0) {
			z = pow(x, y);
		} else {
			printf("ERROR Invalid input\n");
			return -1;
		}
	}
	while (1) {
		system("clear");
		x = z;
		printf("%f\n", x);

		fgets(op, 6, stdin);
		if (exitcheck(op) == 1) return 0;
		
		if (strcmp(op, "sqrt\n") == 0) {
			z = sqrt(x);
			printf("= %f\n", z);
		} else if (strcmp(op, "cbrt\n") == 0) {
			z = cbrt(x);
			printf("= %f\n", z);
		} else {
			fgets(buf, 1024, stdin);		
			if (exitcheck(buf) == 1) return 0;
			y = strtod(buf, &ptr);	
	
			if (strcmp(op, "+\n") == 0) {
				z = x + y;
			} else if (strcmp(op, "-\n") == 0) {
				z = x - y;
			} else if (strcmp(op, "x\n") == 0) {
				z = x * y;
			} else if (strcmp(op, "/\n") == 0) {
				z = x / y;
			} else if (strcmp(op, "^\n") == 0) {
				z = pow(x, y);
			} else {
				printf("ERROR Invalid input\n");
				return -1;
			}
		}
	}
}
