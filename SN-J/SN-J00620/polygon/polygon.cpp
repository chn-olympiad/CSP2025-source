//SN-J00620 杨昕然 西安高新第一中学  
#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
long long n,a[5005],f[5005][5005],b[5005],Max,ans,C[5005][5005],ny[5005];
long long dfs(long long x,long long cnt){
	if(x==0&&cnt==-1)return 1;
	if(x==0&&cnt!=-1)return 0;
	if(f[x][cnt+1]!=-1)return f[x][cnt+1];
	long long ans=0;
	for(long long i=0; i<=b[x]; i++){
		ans=(ans+dfs(x-1,max(cnt-i*x,-1ll))*C[x][i])%Mod;
	}
	return f[x][cnt+1]=ans;
}
long long CC(long long x,long long y){
	long long ans=1;
	for(long long i=x; i>=x-y+1; i--)ans=(ans*i)%Mod;
	for(long long i=1; i<=y; i++)ans=(ans*ny[i])%Mod;
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(f,-1,sizeof(f));
	cin>>n;
	ny[1]=1;
	for(long long i=2; i<=n; i++){
		ny[i]=((-ny[Mod%i]*(Mod/i))%Mod+Mod)%Mod;
	}
	for(long long i=1; i<=n; i++){
		cin>>a[i];
		Max=max(Max,a[i]);
		b[a[i]]++;
	}
	for(long long i=1; i<=Max; i++){
		C[i][0]=1;
		for(long long j=1; j<=b[i]; j++){
			C[i][j]=CC(b[i],j);
		}
	}
	for(long long i=Max; i>=1; i--){
		if(!b[i])continue;
		for(long long j=1; j<=b[i]; j++){
			ans=(ans+dfs(i-1,max(2*i-j*i,-1ll))*C[i][j])%Mod;
		}
	}
	cout<<ans;
	return 0;
}
/*
1.见大样例 

longlong

1.DP
*/
