// 086a 自力AC
// 自力解法: ビットごとにbit全探索
// 水diff

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;

int main() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> b(q, vector<int>(3));
	vector<ll> w(q);
	rep(i, q) {
		rep(j, 3) {
			cin >> b[i][j];
			b[i][j]--;
		}
		cin >> w[i];
	}
	ll res = 1;
	rep(i1, 60) {
		int cnt = 0;
		rep(i, (1<<n)) {
			bool ok = true;
			rep(j, q) {
				int bi = 0;
				rep(j2, 3) bi |= (i>>b[j][j2]) & 1;
				if ((int)((w[j]>>i1)&1LL) != bi) ok = false;
			}
			if (ok) ++cnt;
		}
		res = res * cnt % mod;
	}
	cout << res << endl;
	return 0;
}
