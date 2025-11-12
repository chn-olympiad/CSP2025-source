#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c)) 
int _;
const int N=1e5+7;
int n;
ll ans=0;
bool sp;
struct stu
{
	int a,b,c;
	bool operator<(const stu &w) const
	{
		if(max3(a,b,c)==max3(w.a,w.b,w.c))
		{
			if(max3(a,b,c)-min3(a,b,c)==max3(w.a,w.b,w.c)-min3(w.a,w.b,w.c))
			{
				return min3(a,b,c)>min3(w.a,w.b,w.c);
			}
			return max3(a,b,c)-min3(a,b,c)>max3(w.a,w.b,w.c)-min3(w.a,w.b,w.c);
		}
		return max3(a,b,c)>max3(w.a,w.b,w.c);
	}
}a[N];
void dfs(ll sum,int dep,int ca,int cb,int cc)
{
	if(ca>n/2||cb>n/2||cc>n/2) return;
	if(dep>n)
	{
		ans=max(ans,sum);
		return ;
	}
	dfs(sum+a[dep].a,dep+1,ca+1,cb,cc);
	dfs(sum+a[dep].b,dep+1,ca,cb+1,cc);
	dfs(sum+a[dep].c,dep+1,ca,cb,cc+1);
}
void solve()
{
	sp=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[i].c!=0||a[i].b!=0) sp=0;
	}
	sort(a+1,a+n+1);
	int ca=0,cb=0,cc=0;
	ans=0;
	if(sp)
	{
		for(int i=1;i<=n/2;i++) ans+=a[i].a;
		cout<<ans<<'\n';
		return ;
	}
	else
	{
		dfs(0,1,0,0,0);
		cout<<ans<<'\n';
		return ;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	for(int i=1; i<=_; i++) {
//		printf("---test---%d---\n",i);
		solve();
	}
	return 0;
}
