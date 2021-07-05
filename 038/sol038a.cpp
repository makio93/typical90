// 038a 自力AC
// 自力解法: 条件判定を工夫してオーバーフローを回避
// 茶diff

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

ll gcd(ll a, ll b) { return (a < b) ? gcd(b, a) : ((b > 0) ? gcd(a%b, b) : a); }

int main() {
	ll a, b;
	cin >> a >> b;
	ll g = gcd(a, b);
	if (a/g > (ll)(1e18)/b) cout << "Large" << endl;
	else cout << (a/g*b) << endl;
	return 0;
}
