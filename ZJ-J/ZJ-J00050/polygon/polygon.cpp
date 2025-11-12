#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const long long mod=998244353;

int n,m,a[maxn];
long long f[maxn*2],ext,ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	m=a[n]*2;
	f[0]=1;
	for (int i=1;i<=n;i++){
		if (i>=3){
			for (int j=a[i]+1;j<=m;j++){
				ans+=f[j];
				ans%=mod;
			}
			ans+=ext;
			ans%=mod;
		}
		ext*=2;
		ext%=mod;
		for (int j=m-a[i]+1;j<=m;j++){
			ext+=f[j];
			ext%=mod;
		}
		for (int j=m;j>=a[i];j--){
			f[j]+=f[j-a[i]];
			f[j]%=mod;
		}
	}
	printf("%d",ans);
	return 0;
}
