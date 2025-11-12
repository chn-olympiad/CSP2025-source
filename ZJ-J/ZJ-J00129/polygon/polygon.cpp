#include<bits/stdc++.h>
using namespace std;
int a[5005],ans=0;
int n;
int tmp[100];
map<string,int> mp;
void dfs(int x,int mx,int len,int p){
	if(len>mx*2){
		ans++;
		ans%=998244353;
	}
	for(int i=x;i<=n;i++){
		tmp[p+1]=a[i];
		dfs(i+1,max(mx,a[i]),len+a[i],p+1);
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans%998244353;
	return 0;
}

