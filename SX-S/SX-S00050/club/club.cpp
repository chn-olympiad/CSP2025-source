#include<bits/stdc++.h>
using namespace std;
int a[100010][13],v[13];
long long t,n,s,maxx;
void dfs(int k)
{
	if(k==n+1)
	{
		maxx=max(maxx,s);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(v[i]==n/2)continue;
		s=s+a[k][i];
		v[i]++;
		dfs(k+1);
		v[i]--;
		s=s-a[k][i];
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;
	while(t--)
	{
		cin>>n;
		s=0;
		maxx=LLONG_MIN;
		v[1]=0,v[2]=0,v[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1);
		cout<<maxx<<"\n";
	}




	return 0;
}