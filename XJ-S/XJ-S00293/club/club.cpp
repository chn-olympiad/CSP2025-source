#include<bits/stdc++.h>
using namespace std;
unsigned long long int t,n,a[100005][5],v[100005][5],maxn,ans,x,s[5],u[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(u,0,sizeof(u));
		memset(s,0,sizeof(s));
		memset(v,0,sizeof(v));
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
	    for(x=1;x<=3;x++)
		for(i=1;i<=n;i++)
		{	
			if(v[i][x]==0&&a[i][x]>maxn)
			{
				maxn=a[i][x];
			}
		}
		for(x=1;x<=3;x++)
	    for(i=1;i<=n;i++)
	    {
	    	if(u[x]<=(n/2))
			{
				v[i][x]=1;
				s[x]+=a[i][x];
				u[x]++;
			}
		}
		for(i=1;i<=3;i++)
		{
			ans+=s[i];
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
