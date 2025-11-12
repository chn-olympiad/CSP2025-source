#include<bits/stdc++.h>
using namespace std;
bool mp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[20][20],x;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    		cin>>a[i][j];
    x=a[1][1];
    sort(a+1,a+1+n*m,mp);
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {   
            cout<<a[i][j]<<" ";
        }
        puts("");
    }
}
