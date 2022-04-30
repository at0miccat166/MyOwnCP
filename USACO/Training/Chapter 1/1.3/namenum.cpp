/*	
	TASK: namenum
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


int orz(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ifstream fin1 ("dict.txt");
	ifstream fin2 ("namenum.in");
	ofstream fout ("namenum.out");

	vector <string> dict;
	string x;	
	while (fin1 >> x){
		dict.push_back(x);
	}
	fin1.close();

	char map[300];
	map['A'] = map['B'] = map['C'] = '2';
	map['D'] = map['E'] = map['F'] = '3';
	map['G'] = map['H'] = map['I'] = '4';
	map['J'] = map['K'] = map['L'] = '5';
	map['M'] = map['N'] = map['O'] = '6';
	map['P'] = map['R'] = map['S'] = '7';
	map['T'] = map['U'] = map['V'] = '8';
	map['W'] = map['X'] = map['Y'] = '9';
	
	string n;
	fin2 >> n;
	int ok = 0;
	int l = n.length();
	for (int i = 0; i <= (int) dict.size() - 1; i++){
		int k = 0;
		int t = dict[i].length();
		if (t != l) continue;
		else {
			for (int j = 0; j <= t - 1; j++, ++k)
				if (map[dict[i][j]] != n[j]) break;
		}
		if (k == t){
			fout << dict[i] << "\n";
			ok++;
		}
	}
	if (!ok) fout << "NONE\n";

	
	fin2.close();
	fout.close();
	return 0;
}
