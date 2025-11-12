#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int n,p;
	bool operator<(const node a)const{
		return a.n<n;
	}
};
void solve(){
	int n=0,ans=0;
	int a[N]={},b[N]={},c[N]={};
	bool ka[N]={},kb[N]={},kc[N]={};
	int na=0,nb=0,nc=0;
	priority_queue<node>pab,pac,pba,pbc,pca,pcb;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(a[i]>=max(b[i],c[i])){
			ans+=a[i];
			ka[i]=1;
			pab.push({a[i]-b[i],i});
			pac.push({a[i]-c[i],i});
			na++;
		}
		else if(b[i]>=max(a[i],c[i])){
			ans+=b[i];
			kb[i]=1;
			pba.push({b[i]-a[i],i});
			pbc.push({b[i]-c[i],i});
			nb++;
		}
		else{
			ans+=c[i];
			kc[i]=1;
			pca.push({c[i]-a[i],i});
			pcb.push({c[i]-b[i],i});
			nc++;
		}
	}
	if(na>n/2){
		for(int i=1;i<=na-n/2;i++){
			while(!ka[pab.top().p])pab.pop();
			while(!ka[pac.top().p])pac.pop();
			if(pab.top().n<=pac.top().n){
				ka[pab.top().p]=0;
				ans-=pab.top().n;
				pab.pop();
			}
			else{
				ka[pac.top().p]=0;
				ans-=pac.top().n;
				pac.pop();
			}
		}
	}
	else if(nb>n/2){
		for(int i=1;i<=nb-n/2;i++){
			while(!kb[pba.top().p])pba.pop();
			while(!kb[pbc.top().p])pbc.pop();
			if(pba.top().n<=pbc.top().n){
				kb[pba.top().p]=0;
				ans-=pba.top().n;
				pba.pop();
			}
			else{
				kb[pbc.top().p]=0;
				ans-=pbc.top().n;
				pbc.pop();
			}
		}
	}
	else if(nc>n/2){
		for(int i=1;i<=nc-n/2;i++){
			while(!kc[pca.top().p])pca.pop();
			while(!kc[pcb.top().p])pcb.pop();
			if(pca.top().n<=pcb.top().n){
				kc[pca.top().p]=0;
				ans-=pca.top().n;
				pca.pop();
			}
			else{
				kc[pcb.top().p]=0;
				ans-=pcb.top().n;
				pcb.pop();
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}