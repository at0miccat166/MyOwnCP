/**    
* LANG: C++ 
* author: atom 
* created: 04.07.2022 11:37:53
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
void __print(const T &x) {int f = 0; 
	cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
 
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T const& t, V const& ... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
 
#ifdef LOCAL
#define debug(x...) cout << "#L" <<__LINE__<< ":" <<" [" << #x << "]=\n" <<"["; _print(x); cout << '\n';
#else
#define debug(...) 42
#endif

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 252;
constexpr ll INF = 1e18;
 
ll n, W;
ll a[MAX], b[MAX];
ll dp[MAX * 4];

bool ok(int x){
	for (int j = 0; j <= W; ++j) dp[j] = -INF;
	dp[0] = 0;
	for (int i = 1; i <= n; i++){
		ll val = 1000LL * b[i] - x * a[i];
		for (int j = W; j >= 0; --j){
			if (j >= a[i])
				dp[j] = max(dp[j], dp[j - a[i]] + val);
			else
				dp[j] = max(dp[j], val);
		}
	}	
	return dp[W] >= 0;
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);

	cin >> n >> W;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	int l = -1, r = 1e9, ans = 1e9;
	while (l <= r){
		int m = (l + r) / 2;
		if (ok(m)){
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}	
	cout << ans << '\n';

		 
}
/* problem link: 
	http://www.usaco.org/index.php?page=viewproblem2&cpid=839
*/

