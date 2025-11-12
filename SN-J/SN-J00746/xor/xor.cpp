#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
bool check(long long x){
	int ans=-1;
	for(int i=1;i<=n;i++){
		int be=i,en=i,xoor=a[i],cnt=0;
		while(be<=n){
			while(xoor!=k&&en<=n) {
				en++;
				xoor^=a[en];
			}
			if(en>n) break;
			cnt++;
			if(cnt>=x){
			//	cout<<"*"<<x<<' '<<cnt<<' '<<i<<' '<<be<<en<<"*\n";
				return 1;
			}
			be=en+1;
			en=be;
		}
		ans=max(ans,cnt);
	}
	//cout<<"*"<<ans<<'\n';
	if(ans>=x) return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long l=-1,r=n+1,m;
	while(l+1<r){
		m=(l+r)/2;
	//	cout<<m<<'\n';
		if(check(m)) l=m;
		else r=m;
	}
	cout<<l+1;
	return 0;
}/*
4 2
2 1 0 3

2

*/
