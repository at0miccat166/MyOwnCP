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
constexpr int MAX = 2005;
constexpr int INF = INT_MAX;
 
int s, n;
vector <vector <pii>> a(MAX, vector <pii> ());
ll dp[MAX][MAX];
int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> s >> n;
	for (int i = 1; i <= n; i++){
		int v, w, k;
		cin >> v >> w >> k;
		a[w].pb({v, k});
	}

	ll ans = 0;
	for (int i = 1; i <= s; i++){

		sort(all(a[i]), [&] (const pii &x, const pii &y){
			return x.F > y.F;
		});

		for (int j = 1; j <= s; j++){
			int cur_w = 0, cur_v = 0;
			for (pii x : a[j]){
				for (int k = 1; k <= x.S; k++){
					cur_w += j;
					cur_v += x.F;
					if (cur_w > i) break;
					dp[i][j] = max(dp[i][j], dp[i - cur_w][j - 1] + cur_v);
				}
				if (cur_w > i) break;
			}		
			dp[i][j] = max(dp[i][j], dp[i][j - 1]); 
			ans = max(ans, dp[i][j]);
		}
	}	 
	cout << ans << '\n';
}
/* problem link: 
	https://oj.uz/problem/view/NOI18_knapsack
*/

