#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int sc1,sc2;
	int id1,id2;
}f[100010];
struct abc
{
	int x,id;
}s[4];
int st[4];

bool cmp1(abc a,abc b){return a.x>b.x;}
bool cmp2(stu a,stu b){
	if(a.sc1-a.sc2!=b.sc1-b.sc2)  return a.sc1-a.sc2>b.sc1-b.sc2;
	else  return a.sc1>b.sc1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		for(int i=1;i<=3;i++)  st[i]=0;
		int n,ans=0;cin>>n;
		for(int i=1;i<=n;i++)
		{
			s[1].id=1,s[2].id=2,s[3].id=3;
			cin>>s[1].x>>s[2].x>>s[3].x;
			sort(s+1,s+4,cmp1);
			f[i].sc1=s[1].x,f[i].id1=s[1].id;f[i].sc2=s[2].x,f[i].id2=s[2].id;
		}
		sort(f+1,f+n+1,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(st[f[i].id1]<n/2)
				ans+=f[i].sc1,st[f[i].id1]++;
			else
				ans+=f[i].sc2,st[f[i].id2]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
