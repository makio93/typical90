// 075a 自力AC
// 自力解法: 素因数分解
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
	ll n;
	cin >> n;
	int pcnt = 0;
	for (ll i=2; i*i<=n; ++i) {
		while (n%i == 0) {
			n /= i;
			++pcnt;
		}
	}
	if (n > 1) ++pcnt;
	int res = 0;
	while (pcnt > 1) {
		pcnt = (pcnt + 1) / 2;
		++res;
	}
	cout << res << endl;
	return 0;
}
