#include<bits/stdc++.h>
using namespace std;

int a[1010],sx[1010],f[1010];
vector<int>g[1010];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sx[i]=sx[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((sx[i]^sx[j-1])==k){
				g[i].push_back(j); 
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(!g[i].size()){
				f[i]=max(f[i],f[j]);
				continue;
			}
			int t=upper_bound(g[i].begin(),g[i].end(),j)-g[i].begin();
			if(t>=g[i].size()) f[i]=max(f[i],f[j]);
			if(g[i][t]<=j || g[i][t]>i) f[i]=max(f[i],f[j]);
			else f[i]=max(f[i],f[j]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	cout<<ans;
	return 0;
}

