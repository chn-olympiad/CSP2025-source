#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll mod=998244353;
ll n,maxx,sum,ans,num;
ll a[5001];
void dfs(ll d){
//	cout<<d<<" "<<sum<<" "<<maxx<<endl;
	if(d>=3&&d<=n){
		
		if(sum>a[maxx]*2){
//			cout<<sum<<" "<<d<<endl;
			ans++;
			ans%=mod;
		}
		if(d==n) return ;
	}
	if(num<=a[maxx]*2) return ;
//	cout<<d<<" "<<maxx<<endl;
	for(ll i=maxx+1;i<=n;i++){
		
		sum+=a[i];
		ll t=maxx;
		maxx=i;
//		cout<<d<<" ";
		dfs(d+1);
		maxx=t;
		sum-=a[i];
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	bool f=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f=1;
		num+=a[i];
	}
	sort(a+1,a+1+n);
	dfs(0);
	cout<<ans%mod;
	return 0;
}
