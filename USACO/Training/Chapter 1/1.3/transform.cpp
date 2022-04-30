/*	
	TASK: transform
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

char a1[12][12], b1[12][12], b_m[12][12];
int n;

bool one(char a[][12], char b[][12]){
	// case 1;
	bool flag = true;
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++)
			if (b[i][j] != a[j][n - 1 - i]){
				flag = false;
				break;
			}
		if (!flag) break;
	}
	return flag;
}

bool two(char a[][12], char b[][12]){
	bool flag = true;
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++)
			if (b[i][j] != a[n - 1 - i][n - 1 - j]){
				flag = false;
				break;
			}
		if (!flag) break;
	}
	return flag;
}

bool three(char a[][12], char b[][12]){
	bool flag = true;
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++)
			if (b[i][j] != a[n - 1 - j][i]){
				flag = false;
				break;
			}
		if (!flag) break;
	}
	return flag;
}


bool four(char a[][12], char b[][12]){
	bool flag = true;
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++)
			if (b[i][j] != a[i][n - 1 - j]){
				flag = false;
				break;
			}
		if (!flag) break;
	}
	return flag;
}

bool five(char a[][12], char b[][12]){
	return (one(a, b) || two(a, b) || three(a, b));
}

bool six(char a[][12], char b[][12]){
	bool flag = true;
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++)
			if (b[i][j] != a[i][j]){
				flag = false;
				break;
			}
		if (!flag) break;
	}
	return flag;
}



int orz(){

	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++){
			scanf("%c", &b1[i][j]);
			b_m[i][n - 1 - j] = b1[i][j];
		}
		getchar();
	}
	for (int i = 0; i <= n - 1; i++){
		for (int j = 0; j <= n - 1; j++) 
			scanf("%c", &a1[i][j]);
		getchar();
	}
	int k = 0;
	if (one(a1, b1)) k = 1;
	else if (two(a1, b1)) k = 2;
	else if (three(a1, b1)) k = 3;
	else if (four(a1, b1)) k = 4;
	else if (five(a1, b_m)) k = 5;
	else if (six(a1, b1)) k = 6;
	else k = 7;
	printf("%d\n", k);
	return 0;
}
