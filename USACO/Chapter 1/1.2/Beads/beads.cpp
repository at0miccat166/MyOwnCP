/*	
	TASK: beads
  	LANG: C++
 
 */
#include "bits/stdc++.h"

using namespace std;

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	
	ifstream fin ("beads.in");
	ofstream fout ("beads.out");

	int n;
	string s;
	fin >> n >> s;
	s = s + s;

	int ans = 1;
	int flag;

	for (int i = 0; i <= n - 1; i++){
		char cmp = s[i];
		if(cmp == 'w') flag = 0;
		else flag = 1;
		int j = i;
		int cur_len = 0;
		while (flag <= 2){		
			while (j <= n + i - 1 && (s[j] == cmp || s[j] == 'w')){
				j++;
				cur_len++;
			}
			cmp = s[j];
			flag++;
		}
		ans = max(ans, cur_len);
	}
	fout << ans << "\n";
	return 0;
}