#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,ans,a[N];
bool vis[N],b[N];
bool judge(){
	for(int i=1;i<=n;i++){
		if(b[i]!=vis[i]){
			return true;
		}
	}
	return false;
}
void dfs(int x,int num,int sum,int max_n){
	if(num>=3){
		if(sum>2*max_n){
			if(!judge())return;
			for(int i=1;i<=n;i++)b[i]=vis[i];
			ans=(ans+1)%998244353;
		}
	}
	if(x>n)return;
	dfs(x+1,num,sum,max_n);
	vis[x]=1;
	dfs(x+1,num+1,sum+a[x],a[x]);
	vis[x]=0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans%998244353<<endl;
	return 0;
}
