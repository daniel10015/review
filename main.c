#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define buf_size 1<<10

void remove_if_exist(char* str, char c)
{
  char* ptr = strchr(str, c);
  if(ptr) {
    *ptr = '\0';
  }
}

// return true if a subtr of str matches any char* in cond
int keep(char* str, char* cond[], int size)
{
  char* match = 0;
  for(int i=0; i<size && match==NULL; i++) {
    char* substr = cond[i];
    match = strstr(str, substr);
  }

  return match != NULL;
}

int main(int argc, char* argv[])
{
  assert(argc >= 2 && "Input file as cmd line arg");
  FILE* file = fopen(argv[1], "r");

  char buf[buf_size];

  char* cond[] = {" = "};
  // Why do we do this?
  int size_of_cond = sizeof(cond)/sizeof(char*);

  while(fgets(buf, buf_size, file)) {
    // filter buf 
    // It might also be a good idea to skip or halt when a comment reach
    strtok(buf, "//");
    if(keep(buf, cond, size_of_cond)) {
      remove_if_exist(buf, '\n');
      printf("line pulled in: %s\n", buf);
      // now let look at lvalue and expr
      // Thanks student in my 1030am T group for showing this to me
      char* lhs;
      char* rhs;
      char* tok = "=";

      lhs = strtok(buf, tok);
      //rhs = strtok(NULL, ";"); // why am I using a semi-colon? Is there a better way to do this?
      // Yes, there is! 
      rhs = lhs + strlen(lhs) + 2; // null term is only on first char in tok, we need to skip the entire tok though
      lhs = strtok(lhs, " "); // remove whitespace
      printf("lhs: %s\n", lhs);
      printf("rhs: %s\n", rhs);
      printf("----------\n");
    }
  }

  printf("Exiting program...\n");
  return 0;
}