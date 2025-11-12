#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c,d,e,ans=0;
	cin>>n>>m>>k;
	int u[10000],v[10000],w[10000];
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
		    for(int l=0;l<m;l++)
		    {
			    if(v[i]==u[j]&&u[l]==u[i]&&v[l]==v[j])
				{
					ans-=w[l];
				}		    	
			}
		}
	}
	for(int i=0;i<k;i++)
	{
		cin>>a>>b>>c>>d>>e;
	}
	cout<<ans<<endl;
	return 0;
} 
