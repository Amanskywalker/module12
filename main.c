// lexer in c

// library headers
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <sys/types.h>
#include <unistd.h>

// user define functions
#include "vector.h"
#include "adv.h"

int main(int argc, char const *argv[])
{
  // displaying the license to the user
  system('clear');
  printf("Module12  Copyright (C) 2016  Aman Skywalker \nThis program comes with ABSOLUTELY NO WARRANTY; \nThis is free software, and you are welcome to redistribute it under certain conditions; type 'license' for details.\n");

  //a infinte while loop is called to read the input from the users

  char Command[100]; // a string to hold the command

  int ContinueWhile = 1; // true by default

  while (ContinueWhile)
  {
    vector V;
    vector_init(&V);
    printf("$ -> ");
    scanf("%s",Command);

    if (preg_match(Command, "[eE][xX][iI][tT]"))
    {
      printf("Thank You\n");
      ContinueWhile = 0;
    }
    else if (preg_match(Command, "[0-9][0-9]*[*/+-][0-9][0-9]*"))
    {
      printf("A airthmetic expression detected\n");
      if (preg_match(Command, "[+]"))
      {
        printf("Wow ! Its an Addition\n");
      }
      else if (preg_match(Command, "[-]"))
      {
        printf("Wow ! Its a Subtraction\n");
      }
      else if (preg_match(Command, "[*]"))
      {
        printf("Wow ! Its a Multiplication\n");
      }
      else if (preg_match(Command, "[/]"))
      {
        printf("Wow ! Its a Division\n");
      }
      else
      {
        printf("sorry sir i can't understand what you said\n");
      }
    }
    else
    {
      printf("Write something\n");
    }
  }
  return 0;
}
