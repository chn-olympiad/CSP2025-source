#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=1e5+5;
struct note{
	ll x[5],id[5];
	void read(){
		for(ll i=1;i<=3;i++){
			cin>>x[i];
			id[i]=i;
			ll j=i;
			while(x[j]>x[j-1]&&j>1){
				swap(x[j],x[j-1]);
				swap(id[j],id[j-1]);
				j--;
			}
		}
		return;
	}
};
bool cmp(note x,note y){
	for(ll i=1;i<=3;i++){
		if(x.x[i]-x.x[i+1]!=y.x[i]-y.x[i+1]){
			return x.x[i]-x.x[i+1]>y.x[i]-y.x[i+1];
		}
	}
}
ll n;
note a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			a[i].read();
			//for(ll j=1;j<=3;j++)cout<<a[i].x[j]<<" "<<a[i].id[j]<<"\n";
		}
		sort(a+1,a+n+1,cmp);
		/*
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cout<<a[i].x[j]<<" "<<a[i].id[j]<<"\n";
			}
			cout<<"\n";
		}*/
		ll ans=0,sum[5]={0,0,0,0,0};
		//sum[1]=sum[2]=sum[3]=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				if(sum[a[i].id[j]]<(n/2)){
					ans+=a[i].x[j];
					sum[a[i].id[j]]++;
					//cout<<"选第"<<j<<"个"<<a[i].x[j]<<"\n";
					//cout<<sum[1]<<" "<<sum[2]<<" "<<sum[3]<<"\n";
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0; 
}
/*
15:45 1h 15min 调不出来。 
16:07 调出第一个样例。
16:13 样例全对，但第五个1.8s(时限1s)。 
	感觉要超时啊/(ㄒoㄒ)/~~ 
*/

/*
总结：
A题(club)可能有部分分；
B题(road)暴力都不会； 
C题(replace)暴力没调完； 
D题(employ)特殊性质A应该能过； 
应该不会爆零了。
2025.11.1
*/
