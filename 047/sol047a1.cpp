// 047a1 自力解答/小課題1まで
// 自力解法: 愚直に判定する
// 黄diff

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
	string s, t;
	cin >> s >> t;
	map<int, char> lcnt;
	rep(i, n) rep(j, n) {
		int val = i - j;
		char col = (s[i]==t[j]) ? s[i] : 'N';
		if (col == 'N') for (char c : string("RGB")) if (s[i]!=c && t[j]!=c) col = c;
		if (lcnt.find(val) == lcnt.end()) lcnt[val] = col;
		else if (lcnt[val]!='N' && col!=lcnt[val]) lcnt[val] = 'N';
	}
	int res = 0;
	for (auto p : lcnt) if (p.second != 'N') ++res;
	cout << res << endl;
	return 0;
}
