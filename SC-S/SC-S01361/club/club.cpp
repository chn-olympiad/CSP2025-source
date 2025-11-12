#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
ll a[maxn][3];
ll n;
ll cnt1,cnt2,cnt3;
priority_queue<ll> q;
short ty[maxn];
void work(){
	memset(a,0,sizeof(a));
	while(q.size()) q.pop();
	cnt1=0;
	cnt2=0;
	cnt3=0;
	cin>>n;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>=a[i][1]){
			if(a[i][0]>=a[i][2]){
				cnt1++;
				ty[i]=0;
				ans+=a[i][0];
			}
			else{
				cnt3++;
				ty[i]=2;
				ans+=a[i][2];
			}
		}
		else{
			if(a[i][1]>=a[i][2]){
				cnt2++;
				ty[i]=1;
				ans+=a[i][1];
			}
			else{
				cnt3++;
				ty[i]=2;
				ans+=a[i][2];
			}
		}
	}
	if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
		cout<<ans<<"\n";
		return;
	}
	ll diffe=max(cnt1,max(cnt2,cnt3))-n/2;
	if(cnt1>n/2){
		for(ll i=1;i<=n;i++){
			if(ty[i]==0){
				q.push(max(a[i][1],a[i][2])-a[i][0]);
			}
		}
	}
	if(cnt2>n/2){
		for(ll i=1;i<=n;i++){
			if(ty[i]==1){
				q.push(max(a[i][0],a[i][2])-a[i][1]);
			}
		}
	}
	if(cnt3>n/2){
		for(ll i=1;i<=n;i++){
			if(ty[i]==2){
				q.push(max(a[i][0],a[i][1])-a[i][2]);
			}
		}
	}
	for(ll i=0;i<diffe;i++){
		ans+=q.top();
		q.pop();
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--) work();
	return 0;
}