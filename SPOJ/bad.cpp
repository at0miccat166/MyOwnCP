#include<stdio.h>

//mang input
int A[1001][1001];

void solve()
{
    int m, n;
    char s[1002] = {'\0'};  // s la xau xu li tung hang input

    // mang 1 chieu chua cac phan tu 1 2 tuong ung voi
    int hang[1001][3] = {0}, cot[1001][3] = {0};  

    // nhap gia tri cho mang A va mang hang, cot
    scanf("%d %d",&m, &n);
    for ( int i = 0 ; i < m ; i++ )
    {
        scanf("%s",s);
        for ( int j = 0 ; j < n ; j++ )
        {
            A[i][j] = s[j] - 48;
            if (A[i][j]) hang[i][A[i][j]]++;
            if (A[i][j]) cot[j][A[i][j]]++;
        }
    }
    long long sum = 0;
    for ( int i = 0 ; i < m ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
        {
            // neu A[i][j] duoc to mau (A[i][j] != 0)
            if (A[i][j])
            {
                //tim mau P1 P3 con lai (A[i][j] coi nhu la P2)
                for ( int k = 1 ; k <= 2 ; k++ )
                {
                    if (A[i][j] != k)
                    {
                        //tim tong diem anh dep tai A[i][j] cong vao sum
                        sum += 1LL * hang[i][k]*cot[j][k];
                    }
                }
            }
        }
    }
    printf("%lld\n",sum);
}

int main()
{
    int t;
    scanf("%d",&t);
    for ( int i = 1 ; i <= t; i++ )
    {
        solve();
    }
}