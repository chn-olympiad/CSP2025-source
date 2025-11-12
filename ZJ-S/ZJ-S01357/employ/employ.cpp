#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,MOD=998244353;
bool vis[N],flag;
ll n,m,c[N],t[N],ans,s[N];
void f(ll d,ll lq,ll fq){
//	for(ll i=1;i<d;i++){
//		cout<<t[i]<<" ";		 
//	}
//	cout<<"t:"<<lq<<" "<<fq<<'\n';
	if(d>n){
		if(lq>=m){
			ans++;
			ans%=MOD;
//			for(ll i=1;i<=n;i++){
//				cout<<t[i]<<' ';
//			}
//			cout<<"\n";
		}
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		t[d]=i;
		if(c[i]<=fq||(s[d]==0)){
			f(d+1,lq,fq+1);
		}else{
			f(d+1,lq+1,fq);
		} 
		vis[i]=0;
	}
	return;
}
signed main(){
	ios:;sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		char cc;
		cin>>cc;
		if(cc=='1') s[i]=1;
		else flag=0;
	}
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		bool flag1=0,flag2;
		ll sum=1;
		sort(c+1,c+1+n);
		for(ll i=2;i<=n;i++){
			if(c[i]!=c[i-1]) flag1=0;
		}
		for(ll i=2;i<=n;i++){
			if(c[i]!=0) flag2=0;
		}
		for(ll i=1;i<=n;i++){
			sum*=n;
			sum%=MOD;
		}
		if(flag2) cout<<0;
		else if(flag1) cout<<sum-1;
		else cout<<sum<<"\n";
	}else if(flag){
		
	}
	f(1,0,0);
	cout<<ans<<"\n";
	return 0;
}
