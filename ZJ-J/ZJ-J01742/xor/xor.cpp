#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],hou[N],sum[N],nxt[N],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=n;i>=1;--i){
		hou[sum[i]]=i;
		nxt[i]=hou[sum[i-1]^m]?hou[sum[i-1]^m]:(n+1);
	}
	f[n+2]=-1e8;
	for(int i=n;i>=1;--i){
		f[i]=max(f[i+1],f[nxt[i]+1]+1);
	}
	printf("%d",f[1]);
	return 0;
}