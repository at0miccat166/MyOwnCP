/**    
* LANG: C++ 
* author: atom 
* created: 03.07.2022 14:47:36
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
constexpr int MAXN = 2002, MAXD = 1000;
constexpr int INF = INT_MAX;

int n, m, c;
int a[MAXN];
int dp[MAXD + 1][MAXN];
// dp(i, j): max mooney at day i and at city j
int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("time.in", "r", stdin);
	// freopen("time.out", "w", stdout);

	cin >> n >> m >> c;
	FOR(i, 1, n) cin >> a[i];
	vector <vector<int>> paths(n + 1);
	FOR(i, 1, m){
		int x, y;
		cin >> x >> y;
		paths[x].pb(y);
	}

	FOR(i, 0, MAXD)
		FOR(j, 0, n) dp[i][j] = -1;
	dp[0][1] = 0;
	int ans  = 0;

	FOR(i, 0, MAXD){
		FOR(j, 1, n){
			if (dp[i][j] != -1){
				for (int x : paths[j]){
					dp[i + 1][x] = max(dp[i + 1][x], dp[i][j] + a[x]);
				}
			}
		}
		ans = max(ans, dp[i][1] - i * i * c);
	}
	cout << ans << '\n';
		 
}
/* problem link: 
	http://www.usaco.org/index.php?page=viewproblem2&cpid=993&lang=en
*/

