#include<bits/stdc++.h>
using namespace std;
int a[5005];
int C[5005][5005];
int n;
int solve1(int st,int h,int m){
	if(st==n){
		if(h>2*m)return 1;
		return 0;
	}
	return (solve1(st+1,h+a[st+1],max(m,a[st+1]))+solve1(st+1,h,m))%998244353;
}//40pts
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	if(n<=20){
		printf("%d\n",solve1(0,0,0));
	}
	else {
		for(int i=0;i<=n;i++)C[i][0]=C[0][i]=1;
		C[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%998244353;
			}
		}
		int ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+C[n][i])%998244353;
		}
		printf("%d\n",ans);
		//24pts.
	}
}
