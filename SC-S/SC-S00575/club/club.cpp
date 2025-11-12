#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T;
ll n;
struct node{
	ll a,num,dif,b;
}f[100005];
pair<ll,ll> t[5];
ll a[100005][5],ot=0;
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	return a.first>b.first;
}
bool cmp1(node a,node b){
	if(a.num!=ot){
		return 0;
	}
	if(b.num!=ot){
		return 1;
	}
	return a.dif>b.dif;
}
ll cnt[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		memset(f,0,sizeof(f));
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cin>>t[j].first;
				t[j].second=j;
			}
			sort(t+1,t+4,cmp);
			f[i].a=t[1].first;
			cnt[t[1].second]++;
			f[i].num=t[1].second;
			f[i].b=t[2].first;
			f[i].dif=t[1].first-t[2].first;
		}
		ll flg=0;
		for(ll i=1;i<=3;i++){
			if(cnt[i]>n/2){
				flg=1;
				ot=i;
			}
		}
		if(flg==0){
			ll ans=0;
			for(ll i=1;i<=n;i++){
				ans+=f[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		ll ans=0;
		sort(f+1,f+1+n,cmp1);
		for(ll i=1;i<=n/2;i++){
			ans+=f[i].a;
		}
		for(ll i=n/2+1;i<=n;i++){
			if(f[i].num!=ot){
				ans+=f[i].a;
			}
			else{
				ans+=f[i].b; 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 