/**    
* LANG: C++ 
* author: atom 
* STRESS_TEST
**/
#include "bits/stdc++.h"
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long h) {
	return uniform_int_distribution<long long>(l, h)(rng);
}

string Rand_string(long long n){
	string s = "";
	for (int i = 0; i <= n - 1; i++){
		s += (char) (Rand(0, 2) + '0');
	}
	return s;
}

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	int t = (int) Rand(1, 5);
	cout << t << '\n';
	while (t--){
		int n = (int) Rand(5, 10);
		int m = (int) Rand(5, 10);
		cout << n << ' ' << m << '\n';
		char a[n][m];
		for (int i = 0; i <= n - 1; ++i){
			string t = Rand_string(m);
			for (int j = 0; j <= m - 1; j++) a[i][j] = t[j];
		}

		for (int i = 0; i <= n - 1; ++i){
			for (int j = 0; j <= m - 1; j++) cout << a[i][j] << ' ';
				cout << '\n';
		}
		cout << '\n';	
	}


	
	return 0;
}