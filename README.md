# simple example program
Filters a file lhs and rhs expression

## Clone
```
git clone https://github.com/daniel10015/review.git
```

## Build
```
gcc main.c -o a.out
```

## Run
```
./a.out [file]
```
e.g.
```
./a.out main.c
```

## Example output
```
line pulled in:   char* ptr = strchr(str, c);
lhs: char* ptr 
rhs: strchr(str, c);
----------
line pulled in:     *ptr = '\0';
lhs: *ptr 
rhs: '\0';
----------
line pulled in:     *str = '\0';
lhs: *str 
rhs: '\0';
----------
line pulled in:   char* match = 0;
lhs: char* match 
rhs: 0;
----------
line pulled in:     char* substr = cond[i];
lhs: char* substr 
rhs: cond[i];
----------
line pulled in:     match = strstr(str, substr);
lhs: match 
rhs: strstr(str, substr);
----------
line pulled in:   FILE* file = fopen(argv[1], "r");
lhs: FILE* file 
rhs: fopen(argv[1], "r");
----------
line pulled in:   char* cond[] = {" = "};
lhs: char* cond[] 
rhs: {" = "};
----------
line pulled in:   int size_of_cond = sizeof(cond)
lhs: int size_of_cond 
rhs: sizeof(cond)
----------
line pulled in:       char* tok = "=";
lhs: char* tok 
rhs: "=";
----------
line pulled in:       lhs = strtok(buf, tok);
lhs: lhs 
rhs: strtok(buf, tok);
----------
line pulled in:       rhs = lhs + strlen(lhs) + 2; 
lhs: rhs 
rhs: lhs + strlen(lhs) + 2; 
----------
Exiting program...
```