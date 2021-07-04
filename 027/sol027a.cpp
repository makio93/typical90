// 027a 自力AC
// 自力解法: map型を使う
// 灰diff

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
	set<string> scnt;
	vector<int> res;
	rep3(i, 1, n+1) {
		string si;
		cin >> si;
		if (scnt.find(si) == scnt.end()) {
			scnt.insert(si);
			res.push_back(i);
		}
	}
	rep(i, (int)(res.size())) cout << res[i] << endl;
	return 0;
}
