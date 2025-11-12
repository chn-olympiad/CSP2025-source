#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N=202;
ll t,n,f[N][N];
struct poll{
	ll a,b,c;
}x[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,0,sizeof f);
		for(ll i=1;i<=n;i++) cin>>x[i].a>>x[i].b>>x[i].c;
		for(ll i=1;i<=n;i++){
			for(ll j=n/2;j>=0;j--){
				for(ll k=n/2;k>=0;k--){
					if(i-j-k<=n/2&&i-j-k>0) f[j][k]=max(f[j][k],f[j][k]+x[i].c);
					if(j>0) f[j][k]=max(f[j][k],f[j-1][k]+x[i].a);
					if(k>0) f[j][k]=max(f[j][k],f[j][k-1]+x[i].b);
				}
			}
		}
		ll mx=-1;
		for(ll j=1;j<=n/2;j++){
			for(ll k=1;k<=n/2;k++){
				mx=max(mx,f[j][k]);
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/
