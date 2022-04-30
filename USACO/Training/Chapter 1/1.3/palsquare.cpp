/*	
	TASK: palsquare
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

char convert[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
					'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

int b;

string bString(int n){
	string res = "";
	while (n){
		int r = n % b;
		res = convert[r] + res;
		n /= b;
	}
	return res;
}

bool checkPanlin(string s){
	int l = s.length();
	for (int i = 0; i <= (l - 1) / 2; i++)
		if (s[i] != s[l - 1 - i]) return false;
	return true;
}


void solve(int n){
	string s1 = bString(n);
	string s2 = bString(n * n);
	if (checkPanlin(s2)){
		cout << s1 << " " << s2 << "\n";
	}
}


int orz(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);

	cin >> b;
	for (int i = 1; i <= 300; i++){
		solve(i);
	}
	return 0;
}
