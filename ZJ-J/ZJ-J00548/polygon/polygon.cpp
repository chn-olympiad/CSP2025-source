#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool use[5005];
long long ans=0,g1[5105],g2[5105],g3[5105],g4[5105];
void dfs(int flo,int si){
	if(flo>=3){
		int Max=0;
		long long k=0;
		for(int i=1;i<=n;i++){
			if(use[i])Max=max(Max,a[i]),k+=a[i];
		}
		if(Max*2<k)ans=(ans+1)%998244353;
	}
	if(flo==n)return;
	for(int i=si+1;i<=n;i++){
		if(!use[i]){
			use[i]=true;
			dfs(flo+1,i);
			use[i]=false;
		}
	}
	return;
}
bool f=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)f=false;
	}
	if(f){
		if(n==3)printf("1\n");
		g2[1]=5,g3[1]=11,g4[1]=1;
		for(int i=4;i<=n+5;i++)
			g3[i-2]=(g3[i-3]*2+i)%998244353;
		for(int i=2;i<=n+5;i++)
			g2[i]=(g2[i-1]+g3[i-1])%998244353;
		printf("%d",g2[n-3]);
	}else{
		dfs(0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
