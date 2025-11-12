#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int b[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int maxn=0;
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=n*m;j++)
	  	{

            maxn=max(a[j],maxn);
            b[j]=maxn;
        }
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
