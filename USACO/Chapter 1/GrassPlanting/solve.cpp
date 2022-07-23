/**    
* LANG: C++ 
* author: atom 
* created: 08.07.2022 10:18:55
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
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int x, y, n;
vector <vector <int>> adj;
vector <int> grass_need;

void dfs(int cur_pos, int pre_pos){
	int type = 1;
	for (int next_pos : adj[cur_pos]){
		if (next_pos == pre_pos) continue;
		while (type == grass_need[cur_pos] || type == grass_need[pre_pos])
			type++;
		grass_need[next_pos] = type;
		dfs(next_pos, cur_pos);
		type++;
	}
}

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);

	cin >> n;
	adj.resize(n + 1);
	grass_need.resize(n + 1);
	FOR(i, 1, n - 1){
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	grass_need[1] = 1; 
	dfs(1, 1);
	int ans = 0;
	FOR(i, 1, n)
		ckmax(ans, grass_need[i]);
	cout << ans << '\n';
}
/* problem link: 
	http://www.usaco.org/index.php?page=viewproblem2&cpid=894
*/
