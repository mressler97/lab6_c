/* Name:       Michael Ressler
 * Class:      CSCI112 C
 * Assignment: lab 6
 * Date:       3/13/2019
*/

#include <stdio.h>
#include <string.h>

//declarations
int is_empty(const char *);
char *two_ele_subs(char *, int, int);
char *three_ele_subs(char *, int, int, int);
void print(const char *);
void print_set(const char*);

int main(void) {

	int c_count1 = 0; //first element spot holder
	int c_count2 = 1; //second element spot holder
	int c_count3 = 2; //third element spot holder
	char string[99];
	char *ptr;

string[0] = '\0';
putchar('\n');
printf("Enter 4-character string: ");
scanf("%[^\n]s", string);
ptr = string;
putchar('\n');

if (string[0] == '\0' || strlen(string) != 4) {
 //catches if a string was not entered and if it was not 4 characters
	printf("Invalid Entry\n");
	putchar('\n');
	return 0;
	}
else {
putchar('\n');
printf("one_ele_subs\n");
printf("{\"%s\"}\n", string);

while(*ptr != '\0') {
	printf("{");
	printf("%c", *ptr++);
	printf("}\n");
	}

putchar('\n');
putchar('\n');

printf("two_ele_subs\n");
printf("{\"%s\"}\n", string);
two_ele_subs(string,c_count1, c_count2);
//sends string and two element counters to function

putchar('\n');
putchar('\n');

printf("three_ele_subs\n");
printf("{\"%s\"}\n", string);
three_ele_subs(string, c_count1, c_count2, c_count3);
//sends string and 3 element counters to function

putchar('\n');

	}
}

int is_empty(const char *set) {
	return (set[0] == '\0');
}

//recursive function for three element subsets
char *three_ele_subs(char *set, int char_count1, int char_count2, int char_count3) {

	char sub[65];

	if (is_empty(set)) {
	printf("There is no set\n");
	}
	else {
	if (char_count1 < strlen(set)- 2) {
	 if (char_count2 < strlen(set)) {
	  if (char_count3 < strlen(set)) {
		strncpy(&sub[0], &set[char_count1], 1);
		strncpy(&sub[1], &set[char_count2], 1);
		strncpy(&sub[2], &set[char_count3], 1);
		sub[strlen(set) - 1] = '\0';
		print_set(sub);

		three_ele_subs(set, char_count1, char_count2, char_count3 + 1);
	}
	else if (char_count3 == 4 && char_count2 == 1) {
		char_count2 = char_count2 + 1;
		char_count3 = char_count3 - 1;
		three_ele_subs(set, char_count1, char_count2, char_count3);
	  }
	else if (char_count3 == 4 && char_count2 == 2) {
		char_count1 = char_count1 + 1;
		char_count3 = char_count3 - 1;
		three_ele_subs(set,char_count1, char_count2, char_count3);
	  }
	else {
	return 0;
       	  }
	 }
	}
     }
	return 0;
}

//recursive function for two element subsets
char *two_ele_subs(char *set, int char_count1, int char_count2) {

	char sub[65];

	if (is_empty(set)) {
	 printf("\nThere is no set for testing.");
	 }
	else {
	 if (char_count1 < strlen(set) -1) {
	  if (char_count2 < strlen(set)) {
		strncpy(&sub[0], &set[char_count1], 1);
		strncpy(&sub[1], &set[char_count2], 1);
		sub[strlen(set) - 2] = '\0';
		print_set(sub);
		//putchar('n');

		two_ele_subs(set, char_count1, char_count2 + 1);
	}
	else {
		char_count2 = char_count1 + 2;
		two_ele_subs(set, char_count1 + 1, char_count2);
	}
       }
      }
	return 0;
}

//prints subsets to console with a comma
void print(const char *str) {

	if (strlen(str) == 1) {
		putchar(str[0]);
	 }
	else {
		printf("%c, ", str[0]);
		print(&str[1]);
	}
}

//prints brackets around the subsets
void print_set(const char *set) {

	putchar('{');

	if (!is_empty(set)) {
	 	print(set);
		putchar('}');
		printf("\n");
	}
}
