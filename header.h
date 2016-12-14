#include <string>
#include <vector>

using std::vector;
using std::string;

template <class T>
class Quicksort
{
 public:
  static void quicksort(vector<T> & _list)
  {
    quicksort(_list, 0, _list.size());
  }
 private:
  static void quicksort(vector<T> & _list, int left, int right)
  {
    if (left + 20 <= right)
    {
      int i = left, j = right-1;
      T pivot = median3(_list, left, right);
      for (;;)
      {
      while (_list[++i] < pivot){}
      while (_list[--j] > pivot){}
      if (i <= j)
	std::swap(_list[i], _list[j]);
      else
	break;
      }
      // restore pivot
      std::swap(_list[i], _list[right - 1]);
      quicksort(_list, left, i-1);
      quicksort(_list, i + 1, right);
    }
    else
      insertionSort(_list, left, right);
    
  }
  static void insertionSort(vector<T> & _list, int left, int right)
  {
    for (int i = left + 1; i <= right; i++)
      {
	T toSort = _list[i];
	int j;
	for (j = i; j > left && _list[j-1] > toSort; j--)
	  _list[j] = _list[j - 1];
	_list[j] = toSort;
      }
  }
  static T median3(vector<T> & _list, int left, int right)

  {
    int mid = left/2 + right/2;
    if (_list[left] > _list[mid])
      std::swap(_list[left], _list[mid]);
    if (_list[left] > _list[right])
      std::swap(_list[left], _list[right]);
    if (_list[mid] > _list[right])
      std::swap(_list[mid], _list[right]);
    std::swap(_list[mid], _list[right - 1]);
    return _list[right - 1]; // pivot
  }
};
