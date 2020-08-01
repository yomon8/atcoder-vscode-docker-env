
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> eratosthenes(long long n) {
  vector<ll> is_prime(n + 1, true);
  for (ll i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (ll j = i + i; j <= n + 1; j += i) {
        is_prime[j] = false;
      }
    }
  }
  vector<ll> P;
  for (ll i = 2; i < is_prime.size(); i++) {
    if (is_prime[i]) P.push_back(i);
  }
  return P;
}

int main() {
  ll n;
  cin >> n;
  for (auto e : eratosthenes(n)) cout << e << endl;

  return 0;
}