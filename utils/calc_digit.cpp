int calc_digit(long long N) {
  int res = 0;
  while (N) {
    ++res;
    N /= 10;
  }
  return res;
}