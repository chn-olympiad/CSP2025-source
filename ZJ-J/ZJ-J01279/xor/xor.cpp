#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],f[N],g[N],maxx,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((f[j]^f[i-1])==k){
				g[i]=j;
				break;
			}
		}
		if(i>maxx&&g[i]) maxx=g[i],ans++;
		if(g[i]<maxx&&g[i]) maxx=g[i];
	}
	cout<<ans;
	return 0;
}

