// 046a 自力AC
// 自力解法: 各値を46で割った余りを前計算
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
	int n;
	cin >> n;
	vector<vector<int>> abc(3, vector<int>(n));
	rep(i, 3) rep(j, n) cin >> abc[i][j];
	vector<vector<int>> vmod(3, vector<int>(46));
	rep(i, 3) rep(j, n) vmod[i][abc[i][j]%46]++;
	ll res = 0;
	rep(i, 46) rep(j, 46) {
		int k = (46 - (i + j) % 46) % 46;
		ll val = (ll)vmod[0][i] * vmod[1][j] * vmod[2][k];
		res += val;
	}
	cout << res << endl;
	return 0;
}
