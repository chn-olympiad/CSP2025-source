#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node{
	int b,c,d;
}a[maxn];
int n,ans=0;
void dfs(int x,int s1,int s2,int s3,int sum){
	if(x==n+1){
//		cout<<x<<" "<<s1<<" "<<s2<<" "<<s3<<" "<<sum<<endl;
		if(s1<=n/2&&s2<=n/2&&s3<=n/2) ans=max(ans,sum); 
		return;
	}
	if(s1<n/2&&a[x].b!=0) dfs(x+1,s1+1,s2,s3,sum+a[x].b);
	if(s2<n/2&&a[x].c!=0) dfs(x+1,s1,s2+1,s3,sum+a[x].c);
	if(s3<n/2&&a[x].d!=0) dfs(x+1,s1,s2,s3+1,sum+a[x].d);
}
int cmp(node n,node m){
	return n.b>m.b;
}
void solve(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c>>a[i].d;
	}
	if(n<=30) dfs(1,0,0,0,0);
	else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].b;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}