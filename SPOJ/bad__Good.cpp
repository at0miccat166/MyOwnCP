/*Manhcute*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b) (a > b)? a : b;
#define min(a,b) (a < b)? a : b;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define cin(a) scanf("%d", &a);
#define cout(a) printf("%d ", a);
typedef long long ll;
typedef unsigned long long ull;


void MT(){
	int n, m;
	cin(n); cin(m);
	char arr[n+1][m+1];
	FOR(i, 0, n-1){
		char s[m+1];
		scanf("%s", s);
		FOR(j, 0, m-1)
			arr[i][j] = s[j];
	}
	int R1[1002]={0}, C1[1002]={0}, R2[1002]={0}, C2[1002]={0};

	ll cnt = 0;
	FOR(i, 0, n-1){
		FOR(j, 0, m-1){
			// if(arr[i][j] == 0) continue;
			if(arr[i][j] == '1'){
				R1[i]++;
				C1[j]++;
			}
			else if(arr[i][j] == '2'){
				R2[i]++;
				C2[j]++;
			}
			else continue;
		}
	}
	FOR(i, 0, n-1)
		FOR(j, 0, m-1){
			if(arr[i][j] == '1'){
				cnt+= (ll) R2[i]*C2[j];
			}
			else if(arr[i][j] == '2'){
				cnt+= (ll) R1[i]*C1[j];
			}
			else continue;
		}
			
	printf("%lld\n", cnt);
}

int main(){
		int t; cin(t);
		while(t--){
			MT();
		}
	return 0;
}