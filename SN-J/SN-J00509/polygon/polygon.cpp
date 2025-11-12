//考号：SN-J00509 姓名：李兴辰 学校：安康高新技术产业开发区九年制学校
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll N=5005,mod=998244353;
ll n,a[N],c;
void dfs(int i,int x,ll ans,ll maxn){
	for(int j=i+1;j<=n;j++){
		if((ans+a[j])>(max(maxn,a[j])<<1)){
			dfs(j,x+1,ans+a[j],max(maxn,a[j]));
			c++;
			c%=mod;
		}
		else dfs(j,x+1,ans+a[j],max(maxn,a[j]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	ll ans=0,maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i],maxn=max(maxn,a[i]);
	}
	if(n==3){
		cout<<(ans>(maxn<<1));
	}else{
		dfs(0,0,0,0);
		cout<<c;
	}
	return 0;
} 
