//CSP-J
//SN-J00313
//张之奇
//西安市铁一中学 

#include <bits/stdc++.h>
using namespace std;

const int maxn=5005;
const int mod=998244353;
int n;
long long a[maxn];
long long ans;
long long C[5005][5005];

void dfs(int i,long long mx,long long sum,int cnt){
	if (i==n+1){
		if (cnt<=2)	return ;
		if (mx*2<sum)	ans++;
		return ;
	}
	dfs(i+1,mx,sum,cnt);
	dfs(i+1,max(mx,a[i]),sum+a[i],cnt+1);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)	cin>>a[i];
	for (int i=1;i<=n;i++){
		for (int j=0;j<=i;j++){
			if (j==0||j==i)	C[i][j]=1ll;
			else	C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	if (n<=20){
		dfs(1,0,0,0);
		cout<<ans;
	}
	else {
		for (int i=3;i<=n;i++)	ans=(ans+C[n][i])%mod;
		cout<<ans;
	}
	return 0;
}
