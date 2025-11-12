#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],ans,sum[N],q,k,vis[N],c[N];
int lowbit(int x){
	return x&-x;
}
int Query(int x){
	int ret=0;
	for(;x;x-=lowbit(x)){
		ret+=c[x];
	}
	return ret;
}
void Modify(int x,int v){
	for(;x<=n;x+=lowbit(x)){
		c[x]+=v;
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int l=q+1; l<=n; l++) {
		if(a[l]==k and Query(l)==0) {
			q=l;
			ans++;
			continue;
		}
		for(int r=l; r<=n; r++) {
			if(sum[r]^sum[l-1]!=k) {
				continue;
			} else {
				Modify(l,1);
				Modify(r+1,-1);
//				cout<<l<<" "<<r<<"\n";
				q=r;
				ans++;
				break;

			}
		}
	}
	cout<<ans;
	return 0;
}

