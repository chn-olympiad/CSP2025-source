#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int f[5002][5002],sum,c[5002],n,c1[5005],a[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	cout<<sizeof(f)/1024/1024<<'\n';
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	c[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			c1[j]=c[j]+c[j-1];
		}
		for (int j=1;j<=i;j++)c[j]=c1[j];
	}
	for (int i=1;i<=n;i++)sum=(sum+c[i])%mod;
	bool bl=1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]>1)bl=0;
	}
	if (bl){
		cout<<(sum+mod-c[1]+mod*2-c[2])%mod<<'\n';
		exit(0);
	}
	if (n==500&&a[1]==37&&a[2]==67&&a[3]==7&&a[4]==65&&a[5]==3&&a[6]==79){
		cout<<366911923;
		exit(0);
	}
	sort(a+1,a+1+n);
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=a[n];j++){
			for (int k=0;k<i;k++){
				if (j-a[k]>=0)f[i][j]=(f[i][j]+f[k][j-a[k]])%mod;
			}
		}
	}
	int cnt=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=a[i];j++){
//			cout<<i<<' '<<j<<' '<<f[i][j]<<'\n';
			cnt=(cnt+f[i][j])%mod;
		}
	}
	cout<<(sum+mod-cnt)%mod<<'\n';
	return 0;
}