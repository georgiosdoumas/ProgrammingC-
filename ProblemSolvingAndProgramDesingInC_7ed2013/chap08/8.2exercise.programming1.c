/* Write a program to take a product code from Millie’s Mail-Order Catalog
(MMOC) and separate it into its component parts. An MMOC product code
begins with one or more letters identifying the warehouse where the product
is stored. Next come the one or more digits that are the product ID. The final
field of the string starts with a capital letter and represents qualifiers such as
size, color, and so on. For example, ATL1203S14 stands for product 1203,
size 14, in the Atlanta warehouse. Write a program that takes a code, finds the
position of the first digit and of the first letter after the digits, and uses strcpy
and strncpy to display a report such as the following:

Warehouse: ATL
Product: 1203
Qualifiers: S14 ************/

#include <stdio.h>
#include <string.h>
#define N 20  /* length of product codes */
int main(void)
{
  int first = 0, next; /* indexes to run through the whole productCode[] */
  char productCode[N];
  /* Assuming that the max length of the separate field can be up to 8 characters */
  char wareHouse[8];
  char product[8];
  char qualifiers[18];  /* give enough room for the last one so that it will not over-qrite product[] */
  printf("Enter product code (example: ATL1203S14 ) :");
  scanf("%19s", productCode);   // 19 comes form N-1
  for(next = 1; next < strlen(productCode); ++next)
  {
    if( productCode[next] >= '0' && productCode[next] <= '9')
    {
      strncpy(wareHouse, &productCode[first], next - first);
      wareHouse[next-first] = '\0';
      first = next;
      break;
    }
  }
  for(; next < strlen(productCode); ++next)
  {
    if( (productCode[next] >= 'A' && productCode[next] <= 'Z') || (productCode[next] >= 'a' && productCode[next] <= 'z') )
    {
      strncpy(product, &productCode[first], next - first);
      product[next-first] = '\0';
      first = next;
      break;
    }
  }
  strcpy(qualifiers, &productCode[first]);
  printf("Warehouse: %11s \n", wareHouse);
  printf("Product  : %11s \n", product);
  printf("Qualifiers: %10s \n", qualifiers);
  return 0;
}
// gcc -Wall -o 8.2exercise.programming1  8.2exercise.programming1.c
