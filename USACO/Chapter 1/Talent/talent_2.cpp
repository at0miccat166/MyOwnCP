#include<bits/stdc++.h>
using namespace std;
 
#define pb              push_back
#define SZ(x)           (int)x.size()
#define F               first
#define S               second
#define ALL(x)          x.begin(), x.end()
#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i, a, b)    for(int i = a; i < b; ++i)
#define endl            '\n'
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef ONLINE_JUDGE
#define debug(...)
#else
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#endif
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9;

#define int ll
const int N = 1000 + 5, K = 250 + 5;
ll dp[K][N], n, w;
std::vector<ll> a(K+1), b(K+1);

bool check(int x) {
	FOR(i, 0, n+1) {
		FOR(j, 0, w+1) {
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	FOR(i, 1, n+1) {
		FOR(j, 0, w+1) {
			// dp[i][j] = -INF;
			if(j < a[i])
				dp[i][j] = max(dp[i-1][j], 1000ll * b[i] - x * a[i]); 
			else{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j - a[i]] + 1000ll * b[i] - x * a[i]);
			}
		}
	}
	return (dp[n][w] >= 0);
}

void solve() {
	cin >> n >> w;
	FOR(i, 1, n+1) {
		cin >> a[i] >> b[i];
	}
	ll lo = -1, hi = 1e9;
	while(hi - lo > 1) {
		int mid = (int)(hi + lo) / 2;
		// debug(mid);
		if(check(mid)) lo = mid;
		else hi = mid;
	}
	cout << check(1066) << '\n';
	cout << lo << endl;
}
 
signed main() {
	fast;
	// #ifndef ONLINE_JUDGE   
	// freopen("talent.in", "r", stdin);   
	// freopen("talent.out", "w", stdout);   
	// #endif  
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}