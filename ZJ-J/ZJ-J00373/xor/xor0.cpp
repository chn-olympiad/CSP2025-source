#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,ans,a[maxn],s[maxn],f[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor0.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=0;j<i;j++)
			if((s[i]^s[j])==m)f[i]=max(f[i],f[j]+1),ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}

