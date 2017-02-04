// custom file made to implement the advance functionalities

#ifndef ADV_H
#define ADV_H

// function to slpit the input
vector preg_split(const char *, char *);

// function to do string matching based on regular expression
int preg_match(const char *, char *);

// function to find out the operator used in airthmetic operation
char operator_match(const char*);

// function to execute airthmetic expression
int execute_expression(const char*);

#endif
