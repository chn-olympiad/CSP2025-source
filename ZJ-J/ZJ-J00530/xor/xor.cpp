#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[2000005][2],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=0;i<=255;++i) f[i][0]=f[i][1]=-1e8;
	f[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=255;++j){
			if(j==k) f[0][1]=max(f[0][1],f[j^a[i]][0]+1);
			f[j][1]=max(f[j][1],f[j^a[i]][0]);
		}
		for(int j=0;j<=255;++j) f[j][1]=f[j][0]=max(f[j][0],f[j][1]);
	}
	for(int i=0;i<=255;++i) ans=max(ans,f[i][1]);
	cout<<ans;
	return 0;
}
