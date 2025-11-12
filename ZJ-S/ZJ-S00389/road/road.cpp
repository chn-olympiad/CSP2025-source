#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll n,m,k,head[maxn],tail[maxn],price1[maxn],price2[maxn];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<maxn;i++){
		price2[i]=10000000;
	}
	for(int i=1;i<=m;i++){
		cin>>head[i]>>tail[i]>>price1[i];
	}
	for(int i=1;i<=k;i++){
		ll ab,num[10010];
		cin>>ab;
		for(int j=1;j<=n;j++){
			cin>>num[j];
			if(num[j]+ab<price2[j]){
				price2[j]=(ab+num[j]);
				ab=0;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=price2[i];
	}
	cout<<ans;
	return 0;
}
