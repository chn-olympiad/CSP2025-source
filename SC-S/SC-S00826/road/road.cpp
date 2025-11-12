#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll n,m,k,x,y,z,f[N],mi=1e9;
struct ac{
	ll x,y,z;
}a[N];
ll b[20][N];
bool cmp(ac a,ac b){
	return a.z<b.z;
}
ll find(ll x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
ll solve(ll n,ll m){
	ll cnt=0,ans=0;
	for(ll i=1;i<=n;i++) f[i]=i;
	for(ll i=1;i<=m;i++){
		ll xx=find(a[i].x),yy=find(a[i].y);
		if(xx==yy) continue;
		f[xx]=yy;
		cnt+=a[i].z;
		ans++;
//		cout<<a[i].x<<" "<<a[i].y<<"\n";
		if(ans==n-1){
			return cnt;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	mi=solve(n,m);
	for(ll i=1;i<=k;i++){
		cin>>b[i][0];
		for(ll j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(ll i=0;i<=(1<<k)-1;i++){
		ll mx=0,nn=n,mm=m;
		for(ll j=0;j<=9;j++){
			if((1<<j)&i){
				nn++;
				mx+=b[j+1][0];
				for(ll z=1;z<=n;z++){
					mm++;
					a[mm].x=nn;
					a[mm].y=z;
					a[mm].z=b[j+1][z];
				}
			}
		}
		sort(a+1,a+1+mm,cmp);
		mi=min(mi,mx+solve(nn,mm));
//		cout<<mx+solve(nn,mm)<<"\n";
	}
	cout<<mi;
}