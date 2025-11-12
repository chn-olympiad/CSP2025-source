#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=2e5+10,mod=1e9+7;
ll fac[N],inv[N];
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void init(int n){
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mod;
}
int n,a[N][4],mx[N]; 
vector<int> v[4];
bool cmp(int x,int y){
	return mx[x]<mx[y];
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		for(int j=1;j<=3;++j) v[j].clear();
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) v[1].push_back(i);
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) v[2].push_back(i);
			else v[3].push_back(i);			
		}
		int p=0;
		for(int j=1;j<=3;++j){
			if(v[j].size()>n/2)
				p=j;
		}
//		for(int j=1;j<=3;++j){
//			for(int x : v[j])
//				cout<<x<<" ";
//			cout<<"\n";
//		}
		int ans=0;
		for(int j=1;j<=3;++j){
			for(int x : v[j])
				ans+=a[x][j];
		}
		if(p==0){
			cout<<ans<<"\n";
			continue;
		}
//		for(int j=1;j<=3;++j){
//			for(int x : v[p]){
//				mx[x]=0;
//				if(j!=p) mx[x]=max(mx[x],v[j][x]); 
//				mx[x]=v[j][x]-mx[x];
//			}
//		}
		for(int x : v[p]){
			mx[x]=0;
			for(int j=1;j<=3;++j){
				if(j!=p) mx[x]=max(mx[x],a[x][j]);
			}
			mx[x]=a[x][p]-mx[x];
		}
//		puts("******");
		sort(v[p].begin(),v[p].end(),cmp);
		for(int i=1;i<=v[p].size()-n/2;++i)
			ans-=mx[v[p][i-1]];
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
