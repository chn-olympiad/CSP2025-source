#include<bits/stdc++.h>
//typedef unsigned long long ull1;
using namespace std;
const int N=1e5+5;
struct ikun{
	int a,b,c;
}d[N];
int t,n,ans;
bool f[N];
bool cmp1(ikun x,ikun y){
	return x.a>y.a;
}
void dfs(int k,int sum,int aa,int bb,int cc){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			if(aa<(n>>1))dfs(k+1,sum+d[i].a,aa+1,bb,cc);
			if(bb<(n>>1))dfs(k+1,sum+d[i].b,aa,bb+1,cc);
			if(cc<(n>>1))dfs(k+1,sum+d[i].c,aa,bb,cc+1);
			f[i]=0;
		}
	}
}
void solve(){
	cin>>n;
	bool f1=0,f2=0;
	ans=0;
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].b>>d[i].c;
		if(d[i].c>0)f2=1;
		if(d[i].b>0)f1=1;
	}
	if(f1==0&&f2==0){
		sort(d+1,d+n+1,cmp1);
		for(int i=1;i<=(n>>1);i++)
			ans+=d[i].a;
		cout<<ans<<'\n';
		return;
	}
	memset(f,0,sizeof(f));
	dfs(1,0,0,0,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}