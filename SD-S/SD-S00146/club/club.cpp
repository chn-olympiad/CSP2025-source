#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,t,ans,vis[206][206][206],flag;
struct Node{
	ll op1,op2,op3;
}a[100086];
void dfs(ll x,ll sum,ll tot1,ll tot2,ll tot3){
	if(x>n){
		ans=max(ans,sum);
		return ;
	}
	if(vis[x][tot1][tot2]>sum) return ;
	vis[x][tot1][tot2]=sum;
	if(tot1<n/2){
		dfs(x+1,sum+a[x].op1,tot1+1,tot2,tot3);
	}
	if(tot2<n/2){
		dfs(x+1,sum+a[x].op2,tot1,tot2+1,tot3);
	}
	if(tot3<n/2){
		dfs(x+1,sum+a[x].op3,tot1,tot2,tot3+1);
	}
}
bool cmp(Node a,Node b){
	return a.op1>b.op1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=flag=0;
		for(int i=0;i<=n;i++) for(int j=0;j<=n/2;j++) for(int k=0;k<=n/2;k++) vis[i][j][k]=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i].op1>>a[i].op2>>a[i].op3;
			if(a[i].op2>0||a[i].op3>0) flag=1;
		}
		if(flag==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].op1;
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
