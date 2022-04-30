/*	
	TASK: milk2
  	LANG: C++
 
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define PII pair<int, int>
#define debug(x) printf(#x " is %d \n", x)
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

bool cmp(PII a, PII b){
	return a.S < b.S;
}
int orz(){
	// // #ifdef ONLINE_JUDGE
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	// #endif
	int n;
	scanf("%d", &n);
	vector <PII> a;
	for (int t = 0; t <= n - 1; t++){
		int i, j;
		scanf("%d%d", &i, &j);
		a.push_back({i, - 1});
		a.push_back({j, 1});
	}
	sort(all(a));
	int ans_m = 0, ans_i = 0, cur_m = 0, cur_i = 0;
	int farmer = 0;
	for (int i = 0; i <= a.size() - 1; i++){
		if (i != 0){
			if (farmer){
				cur_m += a[i].F - a[i - 1].F;
				cur_i = 0;
				ans_m = max(ans_m, cur_m);
			}
			else {
				cur_i += a[i].F - a[i - 1].F;
				cur_m = 0;
				ans_i = max(ans_i, cur_i);
			}
		}
		if (a[i].S == -1) farmer++;
		else farmer--;
	}
	printf("%d %d\n", ans_m, ans_i);
	
	return 0;
}
