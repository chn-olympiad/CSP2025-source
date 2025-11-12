#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N][3];
vector<int> q[4];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool cmp(int a,int b)
{
	return a>b;
}
void solve()
{
	n=read();
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		int pos=0;
		if(a[i][1]>a[i][pos]) pos=1;
		if(a[i][2]>a[i][pos]) pos=2;
		q[pos].push_back(i);
		ans+=a[i][pos];
	}
	for(int i=0;i<3;i++)
	{
		if(q[i].size()>n/2)
		{
			int x=q[i].size()-n/2;
			vector<int> tmp;
			for(auto x:q[i])
			{
				int mx=0;
				for(int j=0;j<3;j++) if(i!=j) mx=max(mx,a[x][j]);
				tmp.push_back(mx-a[x][i]);
			}
			sort(tmp.begin(),tmp.end(),cmp);
			for(int i=0;i<x;i++) ans+=tmp[i];
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<3;i++) q[i].clear();
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}