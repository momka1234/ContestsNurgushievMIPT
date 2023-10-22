#include <cmath>
#include <iostream>
#include <vector>

int main() {
  const int kAccuracy = 10;
  std::cout.precision(kAccuracy);
  int quantity;
  std::cin >> quantity;
  std::vector<long double> mandagors(quantity);
  long double mandagor;
  for (int i = 0; i < quantity; ++i) {
    std::cin >> mandagor;
    mandagors[i] = log(mandagor);
  }
  std::vector<long double> summs(quantity + 1, 0);
  for (int i = 1; i <= quantity; ++i) {
    summs[i] = summs[i - 1] + mandagors[i - 1];
  }
  int number_or_req;
  std::cin >> number_or_req;
  std::vector<long double> ans(number_or_req);
  int left;
  int right;
  for (int i = 0; i < number_or_req; ++i) {
    std::cin >> left >> right;
    ans[i] = exp((summs[right + 1] - summs[left]) / (right - left + 1));
  }
  for (int i = 0; i < number_or_req; ++i) {
    std::cout << std::fixed << ans[i] << '\n';
  }
  return 0;
}
