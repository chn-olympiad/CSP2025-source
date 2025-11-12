#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s[500010],f[500010],go[500010],mk[2000010];
vector<int> xr[2000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mk[0]=1;
	xr[0].push_back(0);
	for(int i=1;i<=n;++i){
		go[i]=n+1;
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(mk[s[i]^k]){
			for(int v:xr[s[i]^k]){
				go[v]=i;
			}
			xr[s[i]^k].clear();
			mk[s[i]^k]=0;
		}
		xr[s[i]].push_back(i);
		mk[s[i]]=1;
	}
	f[go[0]]=1;
	for(int i=1;i<=n;++i){
		f[i]=max(f[i],f[i-1]);
		f[go[i]]=max(f[go[i]],f[i]+1);
//		cout<<go[i]<<' ';
	}
	cout<<f[n];
	return 0;
}
