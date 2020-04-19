#include <stdio.h>
#include <iostream>
#include "wx_string.h"

/*
  so far for 100 000 000, wx::string takes 28% of the stl version version
*/



int main(int argc, char *argv[])
{
int status{};

//wx::string a=wx::string("test");
//wx::string b=wx::string("1234567890----56----1234567890----56----1234567890----56----1234567890----56----1234567890----56----1234567890----56----");

//wx::string a1="a",a2="a",a3="a",a4="a";
//wx::string a1="",a2="",a3="";
wx::string a1,a2,a3; 
//std::string a1="",a2="",a3="",a4="";  

  unsigned long int k{};
  printf("\n\nNew version\n");
  for(;k<100000000;++k)
  {
    a1="new value";
    a2="lorep isumd asjdh askjdh aksdj haskdjhakd jh";
    a3="sdf jkhsdfkjh23 234 8209sdflrfkjsdlfkj slkf jsl dkjfsdlkj";
  }
  printf("K: %lu\n",k);
  printf("last string %s\n\n",a1.c_str());
  printf("last string %s\n\n",a2.c_str());
  printf("last string %s\n\n",a3.c_str());
  return status;
}


