// 031b-1 解説AC/必要な数値をその都度計算
// 想定解法: Grundy数の考え方を用いる,メモ化再帰
// 青diff

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

map<pair<int, int>, int> memo;
int grundy(int wi, int bi) {
	if (memo.find({wi,bi}) != memo.end()) return memo[{wi,bi}];
	if (wi==0 && bi==0) return (memo[{wi,bi}] = 0);
	set<int> mex;
	if (wi >= 1) mex.insert(grundy(wi-1, bi+wi));
	if (bi >= 2) rep3(k, 1, bi/2+1) mex.insert(grundy(wi, bi-k));
	int res = 0;
	for (int m : mex) {
		if (m == res) ++res;
		else break;
	}
	return (memo[{wi,bi}] = res);
}

int main() {
	int n;
	cin >> n;
	vector<int> w(n), b(n);
	rep(i, n) cin >> w[i];
	rep(i, n) cin >> b[i];
	memo = map<pair<int, int>, int>();
	int xval = 0;
	rep(i, n) xval ^= grundy(w[i], b[i]);
	if (xval != 0) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
