/**
* LANG: C++
* author: atom
* created: 16.07.2022 15:31:14
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << "{"; __print(x.first); cerr << ", "; __print(x.second); cerr << "}\n";}
template<typename T>
void __print(const T &x) {
	int f = 0;
	cerr << '{'; for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";
}

void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T const& t, V const& ... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef LOCAL
#define debug(x...) cout << "#L" <<__LINE__<< ":" <<" [" << #x << "]=\n" <<"["; _print(x); cout << '\n';
#else
#define debug(...) 42
#endif

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e3 + 2;
constexpr int INF = INT_MAX;

int h, g;
pii a[MAX], b[MAX];
ll dp[MAX][MAX][2];

ll dist(pii x, pii y) {
	return (x.F - y.F) * (x.F - y.F) + (x.S - y.S) * (x.S - y.S);
}

int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);

	cin >> h >> g;
	for (int i = 1; i <= h; i++) {
		cin >> a[i].F >> a[i].S;
	}
	for (int i = 1; i <= g; ++i) {
		cin >> b[i].F >> b[i].S;
	}
	for (int i = 0; i <= h; i++)
		for (int j = 0; j <= g; j++)
			for (int k = 0; k <= 1; k++) dp[i][j][k] = INF;

	dp[1][0][0] = 0;
	// dp(i, j, k) at first ith H cows, first jth G cows, and at k (0 : Holsteins or 1: Guerneys)
	for (int i = 0; i <= h; i++)
		for (int j = 0; j <= g; j++)
			for (int k = 0; k <= 1; k++) {
				if (i == 0 && j == 0) continue;
				if (!k && i){
					ckmin(dp[i][j][0], dp[i - 1][j][0] + dist(a[i - 1], a[i]));
					ckmin(dp[i][j][0], dp[i - 1][j][1] + dist(a[i], b[j]));
				}
				if (k && j) {
					ckmin(dp[i][j][1], dp[i][j - 1][1] + dist(b[j - 1], b[j]));
					ckmin(dp[i][j][1], dp[i][j - 1][0] + dist(a[i], b[j]));
				}
			}
	cout << dp[h][g][0] << "\n";
}
/* problem link:

*/

