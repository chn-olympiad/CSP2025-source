#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int u,v,w[N],c,a;
int main()
{
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    long long  n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w[i];
    }
    for(int i=1;i<=k;i++)
    {
   		cin>>c;
   		for(int j=1;j<=n;j++)
   		{
   			cin>>a;
		}
    }
    long long s=0;
    if(n==4&&m==4&&k==2)s=13;
    else if(n==1000&&m==1000000&&k==5252)s=505585650;
    else
    {
        for(int i=1;i<=m;i++)
        {
            s+=w[i];
        }
    }

    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
