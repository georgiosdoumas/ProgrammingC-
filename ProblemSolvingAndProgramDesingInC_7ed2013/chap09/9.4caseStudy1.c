#include<stdio.h>
#include<ctype.h>
#define STRSIZ 50
char * find_caps(char *caps, const char *str)
{
  char restcaps[STRSIZ]; /* caps from reststr */
  if (str[0] == '\0')
    caps[0] = '\0'; /* no letters in str => no caps in str */
  else if (isupper(str[0]))
    sprintf(caps, "%c%s", str[0], find_caps(restcaps, &str[1]));
  else
    find_caps(caps, &str[1]);
  return (caps);
}

int main()
{
  char caps[STRSIZ];
  char * morecaps;
  char text[STRSIZ] = "How Many CapiTal LettErs do I have?";
  printf("Capital letters in JoJo are %s\n", find_caps(caps, "JoJo"));
  morecaps = find_caps(caps, text);
  printf(" and in \n %s \n  are %s \n", text, morecaps );
  printf(" Just to be sure we have the modified string : %s \n", caps);
  return 0;
}
// gcc -Wall -o 9.4caseStudy1  9.4caseStudy1.c
