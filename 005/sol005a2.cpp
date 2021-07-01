// 005a2 自力/小課題1まで/ACLなし
// 桁DP(小課題1)
// 黄diff

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
struct mint {
	ll x;
	mint(ll x=0) : x((x%mod+mod)%mod) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod-a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
		return a;
	}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int main() {
	ll n;
	int b, k;
	cin >> n >> b >> k;
	vector<int> c(k);
	rep(i, k) cin >> c[i];
	vector<vector<mint>> dp(2, vector<mint>(b));
	dp[0][0] = 1;
	for (ll i=0; i<n; ++i) {
		dp[1] = vector<mint>(b);
		rep(j, b) {
			int mval = j;
			rep(j2, k) {
				int mval2 = (mval * 10 + c[j2]) % b;
				dp[1][mval2] += dp[0][j];
			}
		}
		swap(dp[0], dp[1]);
	}
	cout << dp[0][0] << endl;
	return 0;
}
