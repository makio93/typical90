// 048a 自力AC
// 自力解法: 優先度付きキューを用いて貪欲に選ぶ
// 茶diff

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	priority_queue<pair<int, int>> que;
	rep(i, n) que.emplace(b[i], a[i]-b[i]);
	ll res = 0;
	rep(i, k) {
		auto p = que.top(); que.pop();
		res += p.first;
		que.emplace(p.second, 0);
	}
	cout << res << endl;
	return 0;
}
