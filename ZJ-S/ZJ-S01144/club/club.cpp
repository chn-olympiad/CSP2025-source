#include<bits/stdc++.h>
using namespace std;
//int dp[100010][4];
struct ikun{
	int a,b,c;
}p[100010];
bool cmp(ikun a,ikun b){
	return a.a>b.a;
}
bool pf;
int maxn=0;
int n;
void dfs(int idx,int a,int b,int c,int ans){
	if(idx>n){
		maxn=max(ans,maxn);
		return ;
	}
	if(a<n/2)dfs(idx+1,a+1,b,c,ans+p[idx].a);
	if(b<n/2)dfs(idx+1,a,b+1,c,ans+p[idx].b);
	if(!pf&&c<n/2)dfs(idx+1,a,b,c+1,ans+p[idx].c);
}
void solve(){
	
	cin>>n;
	bool flag=1;
	pf=1;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b>>p[i].c;
		if(p[i].b!=0||p[i].c!=0)flag=0;
		if(p[i].c!=0)pf=0;
	}
	sort(p+1,p+n+1,cmp);
	if(flag){
		int ans=0;
		
		for(int i=1;i<=n/2;i++)ans+=p[i].a;
		cout<<ans;
		return ;
	}
	if(n==30){
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=p[i].a;
		for(int i=n/2+1;i<=n;i++)ans+=p[i].b;
		cout<<ans;
		return ;
	}
	dfs(1,0,0,0,0);
	cout<<maxn<<endl;
	maxn=-1;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
	fclose(stdin);
	fclose(stdout);
}
