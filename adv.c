// implementation of the adv.h

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <regex.h>
#include <sys/types.h>

#include "vector.h"

vector preg_split(const char *string, char *pattern)
{
    int i = 0;
    char *p = strtok (string, pattern);
    vector temp;

    vector_init(&temp);

    while (p != NULL)
    {
        vector_add(&temp, p);
        p = strtok (NULL, string);
    }

    return temp;
}

int preg_match(const char *string, char *pattern)
{
    int status;
    regex_t re;
    regmatch_t match[2];

    if (regcomp(&re, pattern, REG_EXTENDED | REG_ICASE) != 0)
    {
        return(0);      // failed generating regx pattern
    }

    status = regexec(&re, string, 0, NULL, 0);

    if (status != 0)
    {
        return(0);      // failed matching pattern
    }

    regfree(&re);

    return(1);
}

char operator_match(const char *string)
{
  if (preg_match(string, "[+]"))
  {
    printf("Wow ! Its an Addition\n");
  }
  else if (preg_match(string, "[-]"))
  {
    printf("Wow ! Its a Subtraction\n");
  }
  else if (preg_match(string, "[*]"))
  {
    printf("Wow ! Its a Multiplication\n");
  }
  else if (preg_match(string, "[/]"))
  {
    printf("Wow ! Its a Division\n");
  }
  else
  {
    printf("sorry sir i can't understand what you said\n");
  }
}

int execute_expression(const char* string)
{
  FILE *p, *q;
  p = fopen("cal.sh", "w");
  q = fopen("cal_in", "w");
  fprintf(p, "%s | bc", string);
  fprintf(q, "%s | bc", string);
  system("sh cal.sh");
  p = fopen("cal_out", "r");
  fscanf(p, "%s", string);
  system("rm cal* cal.*");
  return atoi(string);
}
