#include<bits/stdc++.h>
using namespace std;
int w[200],v[200],f[20000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,W;cin>>n>>W;
	for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++) 
		for(int j=W;j>=w[i];j++)
		f[j]=max(f[j],f[j-w[i]]+v[i]);
	cout<<f[W];
	return 0; 
} 