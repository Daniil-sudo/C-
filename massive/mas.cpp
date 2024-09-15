#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum_negative_between_max_min(const vector<int>& A) {
  int N = A.size();
  if (N < 2) {
    return 0; // Если в массиве меньше двух элементов, то нет интервала
  }

  // Находим индексы максимального и минимального элементов
  auto max_it = max_element(A.begin(), A.end());
  auto min_it = min_element(A.begin(), A.end());

  int max_index = distance(A.begin(), max_it);
  int min_index = distance(A.begin(), min_it);

  // Определяем интервал между максимальным и минимальным
  int start, end;
  if (max_index < min_index) {
    start = max_index + 1;
    end = min_index;
  } else {
    start = min_index + 1;
    end = max_index;
  }

  // Суммируем отрицательные элементы в этом интервале
  int sum_negative = 0;
  for (int i = start; i < end; ++i) {
    if (A[i] < 0) {
      sum_negative += A[i];
    }
  }

  return sum_negative;
}

int main() {
  vector<int> A = {1, -2, 3, -4, 5, 6, -7, 8};
  int sum_negative = sum_negative_between_max_min(A);
  cout << "Сумма отрицательных элементов: " << sum_negative << endl; // Вывод: -4

  return 0;
}