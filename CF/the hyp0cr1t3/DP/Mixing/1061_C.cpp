/**
* LANG: C++
* author: atom
* created: 18.07.2022 06:57:19
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
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;

int n, a[MAX], dp[MAX];
int pre[MAX], cur[MAX];
// dp(i, j) takes j elements from array of 1 to ith index;
// sum of good sequences of (1 to i - 1) of j length when a(i) not included
// and (1 to i - 1) of (j - 1) length when (a(j)) is included.
// -> dp(i, j) = dp(i - 1)(j) + dp(i - 1)(j - 1);
// base: dp(1, 0) = 1
// dp OTG
int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[0] = 1;
	pre[0] = 1; 
	cur[0] = 1;
	for (int i = 1; i <= n; i++) {
		vector <int> div;
		for (int j = 1; j <= sqrt(a[i]); j++) {
			if (a[i] % j == 0) {
				div.emplace_back(j);
				if (a[i] / j != j) div.emplace_back(a[i] / j);
			}
		}
		sort(all(div), greater <int> ());
		if (!div.empty()) {
			for (int j : div) {
				debug(j);
				dp[j] += dp[j - 1];
				dp[j] %= MOD;
				debug(dp[j], dp[j - 1]);
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) ret += dp[i], ret %= MOD;
	cout << ret << "\n";
}
/* problem link:

*/

