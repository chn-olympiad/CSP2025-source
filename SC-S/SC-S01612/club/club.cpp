#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10,M=205;
ll T,n;
struct edge{
	ll a,b,c;
}arr[N];
bool cmp(edge x,edge y){
	return abs(x.a-x.b)>abs(y.a-y.b);
}
ll read(){
	ll x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
ll f[2][M][M];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		bool flag=1;
		for(ll i=1;i<=n;i++){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			if(arr[i].c) flag=0;
		}
		if(n<=200){
			memset(f,0,sizeof f);
			for(ll i=1;i<=n;i++){
				for(ll j=0;j<=n/2;j++){
					for(ll k=0;k<=n/2&&j+k<=i;k++){
						f[i%2][j][k]=0;
						if(j+k<i) f[i%2][j][k]=max(f[i%2][j][k],f[(i+1)%2][j][k]+arr[i].c);
						if(j-1>=0) f[i%2][j][k]=max(f[i%2][j][k],f[(i+1)%2][j-1][k]+arr[i].a);
						if(k-1>=0) f[i%2][j][k]=max(f[i%2][j][k],f[(i+1)%2][j][k-1]+arr[i].b);
					}
				}
			}
			ll ans=0;
			for(ll i=0;i<=n/2;i++){
				for(ll j=0;j<=n/2&&i+j<=n;j++){
					ans=max(ans,f[n%2][i][j]);
				}
			}
			cout<<ans<<'\n';
		}
		else if(flag){
			sort(arr+1,arr+n+1,cmp);
			ll ans=0,tota=0,totb=0;
			for(ll i=1;i<=n;i++){
				if(arr[i].a>arr[i].b){
					if(tota<n/2){
						ans+=arr[i].a;
						tota++;
					}
					else{
						ans+=arr[i].b;
						totb++;
					}
				}
				else{
					if(totb<n/2){
						ans+=arr[i].b;
						totb++;
					}
					else{
						ans+=arr[i].a;
						tota++;
					}
				}
			}
			cout<<ans<<'\n';
		}
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