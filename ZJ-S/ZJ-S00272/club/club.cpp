#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100050][4],dp[100050],peo[4],sum[4],place[100050],ans=0;
void exp(ll id,ll num){
	ll del=0xff,cha=0,to=0;
	for(int i=1;i<=num;i++){
		if(place[i]==id){
			for(int j=1;j<=3;j++){
				if(peo[j]<=n/2&&j!=id){
					if(a[i][id]-a[i][j]<del){
						del=a[i][j]-a[i][id];
						cha=i;
						to=j;
					}
				}
			}
		}
	}
	place[cha]=to;
	peo[to]++;
	sum[id]-=a[cha][id];
	sum[to]+=a[cha][to];
}
void solve(){
	ans=0;
	memset(place,0,sizeof(place));
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	memset(peo,0,sizeof(peo));
	memset(sum,0,sizeof(sum));
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		ll maxu=max(a[i][1],max(a[i][2],a[i][3]));
		for(int j=1;j<=3;j++){
			if(maxu==a[i][j]){
				peo[j]++;
				sum[j]+=maxu;
				place[i]=j;
				if(peo[j]>n/2){
					exp(j,i);
				}
			}
		}
	}
	ans=sum[1]+sum[2]+sum[3];
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}
