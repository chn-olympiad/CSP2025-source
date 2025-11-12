#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int t;
int a[N][6],ans=-1;
struct node{
	long long mx,cmx,id;
}mb[N];
node mk(int x,int y,int z)
{
	long long p[3]={x,y,z};
	sort(p,p+3);
	int id;
	if(p[2]==x) id=1;
	else if(p[2]==y) id=2;
	else if(p[2]==z) id=3;
	return {p[2],p[1],id};
}
struct hhh{
	int mx,cmx;
};
vector<int> cnt[5];
//void dfs(int now,int c1,int c2,int c3,int sum)
//{
//	if(now==n+1)
//	{
//		ans=max(ans,sum);
//		return ;
//	}
//	if(c1<(n/2)) dfs(now+1,c1+1,c2,c3,sum+a[now][1]);
//	if(c2<(n/2)) dfs(now+1,c1,c2+1,c3,sum+a[now][2]);
//	if(c3<(n/2)) dfs(now+1,c1,c2,c3+1,sum+a[now][3]);
//}
long long f(int id,long long sm)
{
	int len=(int)cnt[id].size();
	sort(cnt[id].begin(),cnt[id].end());
	for(int i=0;i<len-(n/2);i++)
	{
		sm-=cnt[id][i];
	}
	return sm;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=-1;
		cnt[1].clear();
		cnt[2].clear();
		cnt[3].clear();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			mb[i]=mk(a[i][1],a[i][2],a[i][3]);
		}
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=mb[i].mx;
			cnt[mb[i].id].push_back(mb[i].mx-mb[i].cmx);
		}
		if((int)cnt[1].size()<=(n/2) && (int)cnt[2].size()<=(n/2) && (int)cnt[3].size()<=(n/2))
		{
			cout<<sum<<endl;
		}
		else{
			if((int)cnt[1].size()>(n/2)) cout<<f(1,sum)<<endl;
			else if((int)cnt[2].size()>(n/2)) cout<<f(2,sum)<<endl;
			else if((int)cnt[3].size()>(n/2)) cout<<f(3,sum)<<endl;
		}
	}
    return 0;
}