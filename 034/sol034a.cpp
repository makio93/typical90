// 034a 自力AC
// 自力解法: mapを持ってしゃくとり法
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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	map<int, int> cnt;
	int l = 0, res = 0;
	rep(r, n) {
		cnt[a[r]]++;
		while ((int)(cnt.size()) > k) {
			cnt[a[l]]--;
			if (cnt[a[l]] == 0) cnt.erase(a[l]);
			++l;
		}
		res = max(res, r-l+1);
	}
	cout << res << endl;
	return 0;
}
