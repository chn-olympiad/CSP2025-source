#include<bits/stdc++.h>
using namespace std;
long long T,n,cnt,ans;
struct node{
	long long a,b,c;
}d[100010];
int cmp(node x,node y){
	if(x.a==y.a){
		if(x.b==y.b) return x.c>y.c;
		return x.b>y.b;
	}
	else return x.a>y.a;
}
int dfs(long long now,long long ca,long long cb,long long cc,long long s){
	if(now>n){
		ans=max(ans,s);
		return 0;
	}
	ans=max(ans,s);
	if(ca<cnt&&d[now].a!=0){
		dfs(now+1,ca+1,cb,cc,s+d[now].a);
	}
	if(cb<cnt&&d[now].b!=0){
		dfs(now+1,ca,cb+1,cc,s+d[now].b);
	}
	if(cc<cnt&&d[now].c!=0){
		dfs(now+1,ca,cb,cc+1,s+d[now].c);
	}
	ans=max(ans,s);
	return 0;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		cnt=n/2;
		for(int i=1;i<=n;i++) cin>>d[i].a>>d[i].b>>d[i].c;
		sort(d+1,d+1+n,cmp);
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
