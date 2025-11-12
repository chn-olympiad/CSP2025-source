#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=4e6+5;
int n,k,a[N],s[N],f[N],g[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=4000000;i++) g[i]=-1;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],g[k^s[i]]+1);
		g[s[i]]=max(g[s[i]],f[i]);
		//cout<<f[i]<<" ";
	}
	cout<<f[n]<<"\n";
	return 0;
}
