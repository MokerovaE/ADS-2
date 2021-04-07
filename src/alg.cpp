// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int number = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        number++;
    }
  }
  return number;
}

int countPairs2(int *arr, int len, int value) {
  int number = 0, L = 0, R = len - 1, midde;
  while (L < R) {
    middle = (L + R) / 2;
    if (arr[middle] < value)
      L = mid;
    else
      R = mid;
  }
  for (int i = R; i >= 0; i--)
    for (int j = 0; j < i; j++)
      if (arr[i] + arr[j] == value)
        number++;
  return number;
}

int countPairs3(int *arr, int len, int value) {
  int number = 0, L = 0, R = len - 1;
  while (L < R - 1) {
    int middle = (L + R) / 2;
    if (arr[middle] <= value)
      L = middle;
    else
      R = middle;
  }
  for (int i = 0; i < L; i++) {
  int left = i + 1, right = L, mid;
    while (left < right) {
      mid = (left + right) / 2;
      if (arr[mid] < (value - arr[i]))
        left = mid + 1;
      else
        right = mid;
    }
    while (arr[left] == (value - arr[i])) {
      number++;
      left++;
    }
  }
  return number;
}
