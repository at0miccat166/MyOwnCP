// #include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

typedef long long ll;

#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)

const ll MOD = 1e15 + 7;

typedef struct matrix {
	int x, y;
	ll a[5][5];
}mat;

int dig(ll x){
	int res = 0;
	while (x > 0){
		res++;
		x /= 10;
	}
	return res;
}

ll solve(ll x, ll y) {
	if (x == 0 || y == 0) return 0;
	int l1 = dig(x), l2 = dig(y);
	char X[l1+1], Y[l1+1];
	char Z[l1 + l2 + 1];
	memset(Z, '0', sizeof(Z));
	for (int i = 0; i <= l1 - 1; i++) {
		X[i] = (char)(x%10+'0');
		x /= 10;
	}
	for (int i = 0; i <= l2 - 1; i++) {
		Y[i] = (char)(y%10+'0');
		y /= 10;
	}
	
	FOR(i,0,l1-1) {
		int c = 0;
		FOR(j,0,l2-1) {
			c += (Z[i+j]-'0') + (X[i]-'0')*(Y[j]-'0');
			Z[i+j] = (char)(c%10+'0');
			c /= 10;
		}
		if (c > 0) Z[i+l2] += c;
	}
	ll ans = 0;
	FOD(i,l1 + l2 -1,0) ans = (ans*10ll + Z[i]-'0') % MOD;
	return ans;
}

mat matExp(mat a, mat b) {
	mat c = {a.x, b.y};
	FOR(i,1,c.x) FOR(j,1,c.y) c.a[i][j] = 0ll;
	FOR(i,1,c.x)
		FOR(j,1,c.y)
			FOR(k,1,a.y)
				c.a[i][j] = (c.a[i][j] + solve(a.a[i][k] % MOD, b.a[k][j] % MOD)) % MOD;
	return c;
}

mat Power(mat a, int x) {
	if (x == 1) return a;
	mat ans = Power(a, x/2);
	if (x % 2) return matExp(matExp(ans, ans), a);
	return matExp(ans, ans);
}

int t, n, T[5], F[5];
mat a, x, ans;

int main() {

	FOR(i,1,3) T[i] = i;
	FOR(i,1,3) F[i] = F[i-1] + T[i];

	a.x = 4;
	a.y = 1;
	a.a[1][1] = (ll)F[3];
	a.a[2][1] = (ll)T[3];
	a.a[3][1] = (ll)T[2];
	a.a[4][1] = (ll)T[1];

	x.x = x.y = 4;
	x.a[1][1] = x.a[1][2] = x.a[1][3] = x.a[1][4] = 1ll;
	x.a[2][2] = x.a[2][3] = x.a[2][4] = 1ll;
	x.a[3][2] = x.a[4][3] = 1ll;

	scanf("%d\n", &t);
	while (t--) {
		scanf("%d\n", &n);
		if (n <= 3) {
			printf("%d\n", F[n]);
			continue;
		}
		ans = matExp(Power(x, n-3), a);
		printf("%lld\n", ans.a[1][1]);
	}


	return 0;
}
