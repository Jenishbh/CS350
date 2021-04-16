#include <stdio.h>
#include <string.h>
void displayDifferentName(char* name)
{
name = ("Jimmy");
//printf("%s", name);
}
int main() {
char name[32];
displayDifferentName(name);
printf("%s", name);
//name = ("Tommy");
//printf("%s", name);
return 0;
}