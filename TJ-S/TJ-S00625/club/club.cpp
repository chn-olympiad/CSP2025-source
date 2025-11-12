#include <bits/stdc++.h>
using namespace std;
int t,n,v[100005][5],cg[100005],s[5],ans;
unordered_map<int,int> m;
void slv(int c)
{
	int tgt=s[c]-n/2,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(m[i]==c)
		{
			if(c==1) cg[++cnt]=v[i][1]-max(v[i][2],v[i][3]);
			if(c==2) cg[++cnt]=v[i][2]-max(v[i][1],v[i][3]);
			if(c==3) cg[++cnt]=v[i][3]-max(v[i][1],v[i][2]);		
		}
	}
	sort(cg+1,cg+s[c]+1);
	for(int i=1;i<=tgt;i++) ans-=cg[i];
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));memset(v,0,sizeof(v));memset(cg,0,sizeof(cg));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i][1]>>v[i][2]>>v[i][3];
			ans+=max(max(v[i][1],v[i][2]),v[i][3]);
			if(v[i][1]>=v[i][2]&&v[i][1]>=v[i][3])	
			{
				m[i]=1;
				s[1]++;
			}
			if(v[i][2]>=v[i][1]&&v[i][2]>=v[i][3])	
			{
				m[i]=2;
				s[2]++;
			}
			if(v[i][3]>=v[i][1]&&v[i][3]>=v[i][2])	
			{
				m[i]=3;
				s[3]++;
			}
		}
		for(int i=1;i<=3;i++)
		{
			if(s[i]>n/2) slv(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
