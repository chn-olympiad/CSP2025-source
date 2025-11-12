#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0,s=0;
    cin>>n>>m;
    s=n*m;
    int a[s]={},b[n][m]={};
    for(int i=1;i<=s;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<s-1;i++)
    {
        for(int j=1;j<i-1;j++)
        {
            if(a[j]==a[i])
            {
                ij=i;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
           if(a[i]==a[1])
           {
               cout<<b[n][m];
           }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
