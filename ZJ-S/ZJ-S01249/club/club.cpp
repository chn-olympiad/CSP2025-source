#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,dpp[101][101][101];
struct W{
	int w1,w2,w3;
}w[N];
bool cmp(W a,W b){
	return a.w1>b.w1;
}
void dp2() {
	memset(dpp,0,sizeof(dpp));
	for(int i=1; i<=n; i++) {
		for(int j=n/2; j>=0; j--) {
			for(int k=n/2; k>=0; k--) {
				for(int e=n-j-k; e>=0; e--) {
					if(j>0) dpp[j][k][e]=max(dpp[j][k][e],dpp[j-1][k][e]+w[i].w1);
					if(k>0) dpp[j][k][e]=max(dpp[j][k][e],dpp[j][k-1][e]+w[i].w2);
					if(e>0) dpp[j][k][e]=max(dpp[j][k][e],dpp[j][k][e-1]+w[i].w3);
				}

			}
		}
	}
	int ans=0;
	for(int i=0; i<=n/2; i++) {
		for(int j=0; j<=n/2; j++) {
			int k=n-i-j;
			if(k>n/2) break;
			ans=max(ans,dpp[i][j][k]);
		}
	}
	cout<<ans<<"\n";
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	 freopen("club.in","r",stdin);
	 freopen("club.out","w",stdout);
	bool flaga=1;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>w[i].w1>>w[i].w2>>w[i].w3;
			if(w[i].w2 || w[i].w3) flaga=0;
		}
		if(n<=200) {
			dp2();
		}
		else if(flaga){
			int ans=0;
			sort(w+1,w+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=w[i].w1;
			}
			cout<<ans;
		}
	}
	return 0;
}
