#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//macros
#define PRINTV if(params.verbose) printf
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(*x))

//help message, PROGNAME should be defined atm at xidlescripts.h
#define PROGNAME "test"
#define HELPMSG \
	"executes script after specified X11 idle times"                              "\n" \
	"the script should be located at ~/." PROGNAME "rc and have to be named as:"  "\n" \
	"   <minutes>.sh (without leading zeros)"                                     "\n" \
	"notice: scripts without executable flag are ignored"                         "\n"

//help
typedef struct parameter parameter;
struct parameter {
	const char *desc;
	const char option;
	const int argc;
	const bool required;
	bool set;
	char *args[];
};


//inline functions
static void displayHelpMessage(parameter paramss[], const int numberOfOptions);
static inline void displayVersion();

int main(int argc, char* argv[]) {
	parameter params[4]={
		{.option='1', .desc="test1", .required=true},
		{.option='2', .desc="test2"},
		{.option='3', .desc="test3"},
		{.option='4', .desc="test4"}
	};
	displayHelpMessage(params, ARRAY_SIZE(params));
}

static void displayHelpMessage(parameter params[], const int numberOfOptions) {
	printf("USAGE: %s ", "testApp");
	for(int i=0; i<numberOfOptions; i++) {
		if(params[i].required) printf("-%c ", params[i].option);
		else                   printf("[-%c] ", params[i].option);
	}
	printf("\n\n");
	for(int i=0; i<numberOfOptions; i++) {
		printf("  -%c\n     %s\n", params[i].option, params[i].desc);
	}
	printf("\n"HELPMSG);
}
