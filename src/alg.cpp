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
  int L = 0, R = len - 1, middle, number = 0;
  while (L < R) {
    middle = (L + R) / 2;
    if (arr[middle] <= value)
      L = middle;
    else
      R = middle;
  }
  for (int i = R; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if ((arr[i] + arr[j]) == value)
        number++;
      if ((arr[i] + arr[j]) > value)
        break;
    }
  }
  return number;
}

int countPairs3(int *arr, int len, int value) {
  int L = 0, R = len - 1, middle, mid, number = 0;
  while (L < R - 1) {
    middle = (L + R) / 2;
    if (arr[middle] <= value)
      L = middle;
    else
      R = middle;
  }
  len = R - 1;
  for (int i = 0; i < len; i++) {
    L = i + 1;
    R = len - 1;
    int count = 0;
    while (L < R) {
      mid = (L + R) / 2;
      if (arr[mid] < (value - arr[i]))
        L = mid + 1;
      else
        R = mid;
    }
    while (arr[L] == (value - arr[i])) {
      count++;
      L++;
    }
    number += count;
  }
  return number;
}
