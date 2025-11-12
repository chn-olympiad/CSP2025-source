#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,num[500005],qz[500005],sum;
struct node{
	ll start,end;
}kc[500005];
bool cmp(node x,node y){
	return x.end<y.end || (x.end==y.end && x.start<y.start);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		qz[i]=num[i]^qz[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((qz[j]^qz[i-1])==k){
				kc[++sum].start=i;
				kc[sum].end=j;
				break;
			}
		}
	}
	sort(kc+1,kc+sum+1,cmp);
	ll time=0;
	ll ans=0;
	for(ll i=1;i<=sum;i++){
		if(kc[i].start>time){
			ans++;
			time=kc[i].end;
		}
	}
	cout<<ans;
	return 0;
}
