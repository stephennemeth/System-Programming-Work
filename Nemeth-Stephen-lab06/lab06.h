#ifndef LAB06_H
#define LAB06_H

/*
 * Bubble sort a vector x by swapping
 * all neighboring elements in x 
 * whenever f(x[j - 1], x[j]) returns true.
 * If f(x[j - 1], x[j]) returns false, then 
 * do not swap the neighboring elements in x.
 */
template<typename T> 
void bubbleSort(std::vector<T> &x, bool (* f)(T, T)){
  for (unsigned int i = 0; i < x.size(); i++) {
    for (unsigned int j = 1; j < x.size(); j++) {
      if (f(x[j - 1], x[j])) {
        T temp = x[j - 1];
        x[j - 1] = x[j];
        x[j] = temp;
      }
    }
  }
}

/*
 * Bubble sort a C++ array x by swapping
 * all neighboring elements in x 
 * whenever f(x[j - 1], x[j]) returns true.
 * If f(x[j - 1], x[j]) returns false, then 
 * do not swap the neighboring elements in x.
 */
template<typename T, size_t n> 
void bubbleSort(std::array<T, n> &x, bool (* f)(T, T)){
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 1; j < n; j++) {
      if (f(x[j - 1], x[j])) {
        T temp = x[j - 1];
        x[j - 1] = x[j];
        x[j] = temp;
      }
    }
  }
}

/*
 * Bubble sort a built-in array x by swapping
 * all neighboring elements in x 
 * whenever f(x[j - 1], x[j]) returns true.
 * If f(x[j - 1], x[j]) returns false, then 
 * do not swap the neighboring elements in x.
 */
template<typename T, size_t n> 
void bubbleSort(T (&x) [n], bool (* f)(T, T)){
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 1; j < n; j++) {
      if (f(x[j - 1], x[j])) {
        T temp = x[j - 1];
        x[j - 1] = x[j];
        x[j] = temp;
      }
    }
  }
}

#endif

