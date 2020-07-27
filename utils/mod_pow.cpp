// ABC 110
#include <bits/stdc++.h>
using namespace std;

long MOD = 1000000007;

// aのp乗を求めるアルゴリズム
// p=62の時、pの変化は、62->31->30->15->14->7->6->3->2->1->0
//と、半分半分になっていく
//よって、計算量はO(logp)になる
long modpow(long a, int p) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    // pが偶数の時
    int halfP = p / 2;
    long half = modpow(a, halfP);
    // a^(p/2) をhalfとして、half*halfを計算
    return half * half % MOD;
  } else {
    // pが奇数の時は、
    // pを偶数にするために1減らす
    return a * modpow(a, p - 1) % MOD;
  }
}

//(10*9*8)/(3*2*1);
// 10*9*8 -> ansMul
// 3*2*1 -> ansDiv
long calcComb(int a, int b) {
  if (b > a - b) return calcComb(a, a - b);

  long ansMul = 1;
  long ansDiv = 1;
  for (int i = 0; i < b; i++) {
    ansMul *= (a - i);
    ansDiv *= (i + 1);
    ansMul %= MOD;
    ansDiv %= MOD;
  }
  // ansMul / ansDivをやりたい
  // ansDivの逆元を使って求めよう！

  // フェルマーの小定理
  // b/a 合同 b * a^p-2 (mod p)
  long ans = ansMul * modpow(ansDiv, MOD - 2) % MOD;
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;

  int MNokori = M;
  long ans = 1;
  for (int i = 2; i * i <= MNokori; i++) {
    if (MNokori % i == 0) {
      int cnt = 0;
      while (MNokori % i == 0) {
        cnt++;
        MNokori /= i;
      }
      // cntが2^Xとか3^XのXの部分
      // cnt + N 素数の数
      // -1で分割点を選択
      ans *= calcComb(cnt + N - 1, N - 1);
      ans %= MOD;
    }
  }
  if (MNokori != 1) {
    //最後に素数が残ってる分を処理する
    ans *= calcComb(1 + N - 1, N - 1);  // N-1はcntと同じ
    ans %= MOD;
  }

  cout << ans << endl;
}
