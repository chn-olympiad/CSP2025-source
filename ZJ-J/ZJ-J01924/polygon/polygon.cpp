#include<bits/stdc++.h>
using namespace std;
long long a[100010],t,mo=998244353,xx,n,s,sum,ans,mx;
void dfs(long long x,long long y,long long z,long long v,long long u){
	if(y>x){
		if(2*z<v)ans++;
		ans%=mo;
		return;
	}
	for(long long i=u+1;i<=n;i++){
		dfs(x,y+1,max(z,a[i]),v+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		mx=max(mx,a[i]);
	}
	if(n<=3){
		if(s>2*mx)cout<<1;
		else cout<<0;
	}
	else{
		for(long long i=3;i<=n;i++)dfs(i,1,0,0,0);
		cout<<ans;
	}
}
