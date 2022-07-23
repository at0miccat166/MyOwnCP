/*	
 PROG: gift1
 LANG: C++
 */
#include "bits/stdc++.h"

using namespace std;

string names[16];
int money[16] ={0};

int find(string s, int n){
	for (int i = 0; i <= n - 1; i++){
		if(names[i] == s) return i;
	}
	return -1;
}

int main(){	
	// ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");
	// ios_base:: sync_with_stdio(false);
	// cin.tie(0);
	
	int np; fin >> np;
	for (int i = 0; i <= np - 1; i++){
		fin >> names[i]; 
	}


	for (int i = 0; i <= np - 1; i++){
		string s;
		int m, k;
		fin >> s >> m >> k;
		int giver = find(s, np);
		if(k == 0 || m == 0) continue;
		money[giver] += (-m + m % k);
		for (int j = 0; j <= k - 1; j++){
			fin >> s;
			int re = find(s, np);
			money[re] += (m / k);
		}
	}

	for (int i = 0; i <= np - 1; i++){
		fout << names[i] << " " << money[i] << "\n";
	}
	return 0;
}