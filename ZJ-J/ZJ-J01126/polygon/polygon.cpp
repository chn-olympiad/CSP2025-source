#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=998;
bool t[5010];
int n,a[5010],ans,b[5010][5010];

inline void dfs(int x){
	if(x==n+1){
		int ma=0,gs=0;
		ll z=0;
		for(int i=1;i<=n;i++)
			if(t[i]){
				gs++;
				ma=max(ma,a[i]);
				z=z+a[i];
			}
		if(z>ma*2&&gs>=3)
			ans++;
		ans=ans%mod;
		return;
	}
	t[x]=true;
	dfs(x+1);
	t[x]=false;
	dfs(x+1);
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=20){
		dfs(1);
		printf("%d\n",ans);
	}else{
		b[1][1]=1;
		b[2][1]=b[2][2]=1;
		for(int i=3;i<=n;i++)
			for(int j=1;j<=i;j++){
				b[i][j]=b[i-1][j-1]+b[i-1][j];
				b[i][j]=b[i][j]%mod;
			}
		int num=0;
		for(int i=3;i<=n;i++){
			num=num+b[n][i];
			num=num%mod;
		}
		printf("%d\n",num);
	}
	return 0;
}
