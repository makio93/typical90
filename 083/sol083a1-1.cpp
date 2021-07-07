// 083a1-1 自力解答/小課題1まで/クエリを逆から読んでみる
// 自力解法: グラフ全体の初期状態を構築し、クエリを順に愚直に処理
// 青diff

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, m, q;
	cin >> n >> m;
	vector<set<int>> g(n);
	rep(i, n) g[i].insert(i);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].insert(bi);
		g[bi].insert(ai);
	}
	cin >> q;
	vector<int> x(q), y(q);
	rep(i, q) {
		cin >> x[i] >> y[i];
		x[i]--;
	}
	vector<int> ans(q, 1);
	map<int, int> vlst;
	repr(i, q) {
		if (!vlst.empty()) {
			if ((int)(g[x[i]].size()) <= (int)(vlst.size())) {
				for (int t : g[x[i]]) {
					if (vlst.find(t) != vlst.end()) {
						ans[vlst[t]] = y[i];
						vlst.erase(t);
						if (vlst.empty()) break;
					}
				}
			}
			else {
				for (auto itr=vlst.begin(); itr!=vlst.end(); ) {
					if (g[x[i]].find(itr->first) != g[x[i]].end()) {
						ans[itr->second] = y[i];
						itr = vlst.erase(itr);
						if (vlst.empty()) break;
					}
					else ++itr;
				}
			}
		}
		vlst[x[i]] = i;
	}
	rep(i, q) cout << ans[i] << endl;
	return 0;
}
