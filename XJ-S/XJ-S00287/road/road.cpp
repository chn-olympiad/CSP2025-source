#include<bits/stdc++.h>
#define int long long int
using namespace std;
int n,m,k,sum;
signed main()
{
	freopen("road.in","r",stdin); 
    freopen("road.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
     int u,v,val;
     cin>>u>>v>>val;
     sum+=val;
	}
	for(int i=1;i<=k;i++)
	{
	 int a,b,c,d,e;
	 cin>>a>>b>>c>>d>>e;
	 sum+=b+c+d+e;
	}
    srand(time(NULL));
    cout<<rand()%sum-1;
    return 0;
}
