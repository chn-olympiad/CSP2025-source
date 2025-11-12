#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+10;
ll n,m,k,ans;
ll f[N];
ll find(ll x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
struct node{
	ll id1,id2,idx;
}a[N];
bool cmp(node q,node h){
	return q.idx<h.idx;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(ll i=0;i<=n;i++) f[i]=i;
		for(ll i=1;i<=m;i++){
			cin>>a[i].id1>>a[i].id2>>a[i].idx;
		}
		sort(a+1,a+1+m,cmp);
		for(ll i=1;i<=m;i++){
			ll A=find(a[i].id1),B=find(a[i].id2);
			if(A!=B){
				ans+=a[i].idx;
				f[A]=B;
			}
		}
		cout<<ans<<"\n";
	}else{
		for(ll i=1;i<=m;i++){
			cin>>a[i].id1>>a[i].id2>>a[i].idx;
			ans+=a[i].idx;
		}
		cout<<ans<<"\n";
	}
	
	
	
	
	return 0;
}
/*

*/
