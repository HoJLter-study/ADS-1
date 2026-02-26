// Copyright 2022 NNTU-CS
#include "alg.h"
#include <math.h>
#include <cstdint>

bool checkPrime(uint64_t value) {
  bool flag = true;

  for (uint64_t i = 2; i <= sqrt(value); i++) {
    if (value % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}

uint64_t nPrime(uint64_t n) {
  uint64_t num = 1;
  uint64_t counter = 0;

  while (counter != n) {
    num++;
    if (checkPrime(num)) {
      counter++;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t prime_number = 0;
  while (!prime_number) {
    value++;
    if (checkPrime(value)) {
      prime_number = value;
    }
  }

  return prime_number;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t num = 2; num < hbound; num++) {
    if (checkPrime(num)) {
      sum += num;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t counter = 0;
  for (uint64_t i = lbound + 1; i + 2 < hbound; i++) {
    if (checkPrime(i) && (checkPrime(i + 2))) {
      counter += 1;
    }
  }
  return counter;
}
