/*	
	TASK: milk2
  	LANG: C++
  	author: TRAN MINH HIEU
	Handle: at0miccat
  	manh cute pho mai we :3
  	
 */
#include "bits/stdc++.h"

using namespace std;

struct milk{
	int c, m;
};

void cycle(milk b[]){
	for (int j = 1; j <= 100; j++){
		int i = j % 3;
		if (b[i].m <= b[i + 1].c - b[i + 1].m){
			b[i].m = 0;
			b[i + 1].c += b[i].m;
		}
		else{
			b[i].m -= b[i + 1].c - b[i + 1].m;
			b[i + 1].m = b[i + 1].c;
		}
	}
}

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	ifstream fin ("milk2.in");
	ofstream fout ("milk2.out");

	milk b[3];
	for (auto i : b) cin >> i.c >> i.m;
	cycle(b);
	for (auto i : b) cout << i.m << "\n";
	return 0;
}