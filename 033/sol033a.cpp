// 033a 自力AC
// 自力解法: 直接立式する
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
	int h, w;
	cin >> h >> w;
	if (h<=1 || w<=1) cout << max(h, w) << endl;
	else cout << (((h+1)/2) * ((w+1)/2)) << endl;
	return 0;
}
