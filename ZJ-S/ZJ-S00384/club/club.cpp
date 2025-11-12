#include<bits/stdc++.h>
using namespace std;
int T,n,u[100005],ans,acb,ok2;
struct node{
	int c1,c2,c3;
}a[100005];
void dfs(int st,int d,int b,int c,int sum){
	if(st>n){
		ans=max(ans,sum);
		return;
	}
	if(d<n/2) dfs(st+1,d+1,b,c,sum+a[st].c1);
	if(b<n/2) dfs(st+1,d,b+1,c,sum+a[st].c2);
	if(c<n/2&&!ok2) dfs(st+1,d,b,c+1,sum+a[st].c3);
}
bool cmp(node x,node y){
	return x.c1>y.c1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ok1=1;
		acb=0,ok2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			acb+=a[i].c2;
			if(a[i].c2!=0||a[i].c3!=0) ok1=0;
			if(a[i].c3!=0) ok2=0;
		}
		if(ok1){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].c1;
			}
			cout<<ans<<'\n';
			ans=0;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
