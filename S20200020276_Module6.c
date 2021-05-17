Q1)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void replaceAll(char *str, const char *bstring, const char *astring)
{
    char *pos, temp[1000];
    int a= 0;
    int b;
    b = strlen(bstring);
    while ((pos = strstr(str, bstring)) != NULL)
    {
        strcpy(temp, str);
        a= pos - str;
        str[a] = '\0'; 
        strcat(str, astring
  );
        strcat(str, temp + a+ b);
    }
}
int main()
{
    FILE * fp;
    FILE * ft;
    char s[100];
    char m[1000];
    char bstring[100], astring[100];
    printf("Enter path of source file: ");
    scanf("%s", s);
    printf("Enter word to replace: ");
    scanf("%s", bstring);
    printf("Replace %s with: ",bstring);
    scanf("%s", astring);
    fp  = fopen(s, "r");
    ft = fopen("replace.tmp", "w"); 
    if (fp == NULL || ft == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }
    while ((fgets(m, 1000, fp)) != NULL)
    {
        replaceAll(m, bstring, astring);
        fputs(m, ft);
    }
    fclose(fp);
    fclose(ft);
    remove(s);
    rename("replace.tmp", s);
    return 0;
}







Q5)


#include<stdio.h>
#include<string.h>
int main()
{
  FILE *fp;
  int j, x, o;
  char stringarray[500][50];
  char elament[50];
  char s[20];
  printf("enter file path");
  scanf("%s",s);
  fp = fopen(s,"r");
  if(fp == NULL)
    {
      printf("unable to open file\n");
      printf("please check you have read previleges\n");
      exit(1);
    }
  int a[500],i=0;
  for(i=0; i<500; i++)
    a[i] = 0;
  x = 0;
  while(fscanf(fp, "%s", elament) != EOF)
  {
    j = strlen(elament);
    if (ispunct(elament[j - 1]))
      elament[j-1] = '\0';
    o = 1;
    for(i=0; i<x && o; i++)
    {
      if(strcmp(stringarray[i],elament)==0)
      o = 0;
    } 
    if(o)
    {
      strcpy(stringarray[x],elament);
      a[x]++;
      x++;
    }
    else
    {
      a[i-1]++;
    }
  }  
  fclose(fp);
  for(i=0;i<x;i++)
    printf("%s repeated %d\n",stringarray[i],a[i]);
return 0;
}













