#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const int iINF = 1e9 + 7;
const long double PI = acos(-1.0L);

P step[4] = {
    P(1, 0),
    P(0, 1),
    P(-1, 0),
    P(0, -1),
};

int N, M;

int bfs(vector<vector<char>> map, vector<vector<int>> note, P start) {
  queue<P> q;

  // スタート地点登録
  q.push(start);
  note[start.first][start.second] = 0;

  int cnt = 0;
  while (!q.empty()) {
    P p = q.front();
    q.pop();
    int y = p.first;
    int x = p.second;
    REP(i, 4) {
      int nx, ny;
      ny = y + step[i].first;
      nx = x + step[i].second;
      if (nx < 0 || ny < 0 || nx >= N || ny >= M)
        continue;

      // 壁の場合
      if (map[ny][nx] == '1')
        continue;

      // 既に通った道
      if (note[ny][nx] != iINF)
        continue;

      // ゴール
      if (map[ny][nx] == 'g') {
        cout << note[y][x] + 1 << endl;
        return 0;
      }
      note[ny][nx] = note[y][x] + 1;
      q.push(P(ny, nx));
    }
    cnt++;
  }
  cout << "Fail" << endl;
  return 0;
}

int main() {
  int ans = 1e9;
  cin >> N >> M;
  vector<vector<char>> map(M, vector<char>(N));
  vector<vector<int>> note(M, vector<int>(N, iINF));
  P start;
  REP(i, M) REP(j, N) {
    char po;
    cin >> po;
    if (po == 's')
      start = P(i, j);
    map[i][j] = po;
  }
  bfs(map, note, start);

  return 0;
}