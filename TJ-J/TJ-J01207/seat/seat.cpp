#include<bits/stdc++.h>
using namespace std;
int r,c,n,m,a[105],mine;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[++cnt];
        }
    }
    mine=a[1];
    sort(a+1,a+n*m+1,cmp);
    c=1,r=1;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==mine) break;
        if(r==m && c%2==1) c++;
        else if(r==1 && c%2==0) c++;
        else if(c%2==1)r++;
        else r--;
    }
    cout << c << ' ' << r;
    return 0;
}
