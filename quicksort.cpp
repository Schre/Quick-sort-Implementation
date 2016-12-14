#include <iostream>
#include "header.h"
#include <stdlib.h>
#include <vector>

using std::vector;
int main(void)
{
  Quicksort<int> test;
  vector<int> list;
  srand((unsigned int) time (NULL));
  for (int i = 0; i < 1000; i++)
	list.push_back(rand() % 100);
  test.quicksort(list);
  //for (int i = 0; i < list.size(); i++)
  //std::cout << list[i] << std::endl;
  return 0;
}
