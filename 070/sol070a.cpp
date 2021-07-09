// 070a 自力AC
// 自力解法: 次元ごとに中央値となる座標地点にする場合が最適
// 緑diff

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	sort(all(x)); sort(all(y));
	int cx, cy;
	if (n%2 == 0) {
		cx = (x[(n-1)/2] + x[(n-1)/2+1]) / 2;
		cy = (y[(n-1)/2] + y[(n-1)/2+1]) / 2;
	}
	else { cx = x[(n-1)/2]; cy = y[(n-1)/2]; }
	ll res = 0;
	rep(i, n) res += abs(cx-x[i]);
	rep(i, n) res += abs(cy-y[i]);
	cout << res << endl;
	return 0;
}
