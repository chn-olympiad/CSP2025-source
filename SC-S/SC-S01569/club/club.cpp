#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=100010;
ll n,goal;
ll ans;
struct T{
	ll a[4];
	ll w;
	ll id,cho;
}t[MAXN];
ll tot=0;
ll cut[MAXN];
ll sum[4];
ll Get(ll x){
	ll res=max(t[x].a[1],max(t[x].a[2],t[x].a[3]));
	if(t[x].a[1]==res){
		t[x].w=max(t[x].a[2],t[x].a[3]);
		return 1;
	}
	if(t[x].a[2]==res){
		t[x].w=max(t[x].a[1],t[x].a[3]);
		return 2;
	}
	if(t[x].a[3]==res){
		t[x].w=max(t[x].a[1],t[x].a[2]);
		return 3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--){
		cin>>n;
		ll up=(n>>1);
		ans=0;
		goal=0;
		tot=0;
		for(ll i=1;i<=3;i++)
			sum[i]=0;//初始化
		for(ll i=1;i<=n;i++){
			cin>>t[i].a[1]>>t[i].a[2]>>t[i].a[3];
			t[i].id=i;
			ll number=Get(i);
			t[i].cho=number;//第i个人被分配到cho个社团 
			++sum[number];
			ans+=t[i].a[number];
			if(sum[number]>up){
				goal=number;
			}
		}
		if(!goal){
			cout<<ans<<"\n";
			continue; 
		}//没有一个社团人数超过一半 
		//否则，找出亏损最小的方法 
		for(ll i=1;i<=n;i++){
			if(t[i].cho==goal){
				cut[++tot]=t[i].a[goal]-t[i].w;//转移走这个人的亏损 
			}
		}	
		sort(cut+1,cut+tot+1);
		for(ll i=1;i<=(tot-up);i++){
			ans-=cut[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
