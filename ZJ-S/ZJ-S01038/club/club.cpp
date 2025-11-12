#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define xx first
#define yy second
using namespace std;
#define Exit(str,val) {cout<<str<<endl;return val;}
#define Ms(shuzu,val) memset(shuzu,val,sizeof(shuzu))
const int N=1e5+5;int maxx=0;
struct node{int a,b,c;}a[N];
int n,s[N];
void dfs(int dep,int _1,int _2,int _3)
{
	if(dep==n+1)
	{
		int res=0;
		if(_1>n/2||_2>n/2||_3>n/2) return;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==1) res+=a[i].a;
			else if(s[i]==2) res+=a[i].b;
			else if(s[i]==3) res+=a[i].c;
		}
		maxx=max(maxx,res);return;
	}
	if(_1<n/2) s[dep]=1,dfs(dep+1,_1+1,_2,_3);
	if(_2<n/2) s[dep]=2,dfs(dep+1,_1,_2+1,_3);
	if(_3<n/2) s[dep]=3,dfs(dep+1,_1,_2,_3+1);
}
void Solve()
{
	cin>>n;Ms(s,0);
	int f1=1,f2=1;maxx=0;
	for(int i=1;i<=n;i++)
		cin>>a[i].a>>a[i].b>>a[i].c;
	for(int i=1;i<=n;i++)
		f1&=(a[i].b==0),f2&=(a[i].c==0);
	sort(a+1,a+n+1,[&](node x,node y){
		return x.a>y.a;
	});
	if(f1&&f2)
	{
		int sum=0;
		for(int i=1;i<=n/2;i++) sum+=a[i].a;
		cout<<sum<<endl;return;
	}
	if(f2)
	{
		int ans1=0,ans2=0;
		for(int i=1;i<=n/2;i++) ans1+=a[i].a;
		for(int i=n/2+1;i<=n;i++) ans1+=a[i].b;
		sort(a+1,a+n+1,[&](node x,node y){
			return x.b>y.b;
		});
		for(int i=1;i<=n/2;i++) ans2+=a[i].b;
		for(int i=n/2+1;i<=n;i++) ans2+=a[i].a;
		cout<<max(ans1,ans2)<<endl;return;
	}
	dfs(1,0,0,0);cout<<maxx<<endl;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--) Solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/