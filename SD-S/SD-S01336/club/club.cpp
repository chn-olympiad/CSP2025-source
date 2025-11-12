#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
int a[100010][4],wy,f[100010];
void sol(int now,int s,int aa,int bb,int cc){
	if(now==n+1){
		wy=max(s,wy);
		return;
	}
	if(s+f[now]<=wy)return;
	if(aa<n/2)sol(now+1,s+a[now][1],aa+1,bb,cc);
	if(bb<n/2)sol(now+1,s+a[now][2],aa,bb+1,cc);
	if(cc<n/2)sol(now+1,s+a[now][3],aa,bb,cc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		wy=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int mx=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				mx=max(mx,a[i][j]);
			}
			f[i]=mx;
		}
		if(n>200){
			for(int i=1;i<=n;i++)wy+=f[i],f[i]=0;
			printf("%lld\n",wy);
			continue;
		}
		for(int i=n;i>=1;i--)f[i]=f[i+1]+f[i];
		sol(1,0,0,0,0);
		for(int i=n;i>=1;i--)f[i]=0;
		printf("%d\n",wy);
	}
	return 0;
}
//51wy็þาร 
