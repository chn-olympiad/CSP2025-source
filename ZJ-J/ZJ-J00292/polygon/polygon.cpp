#include<bits/stdc++.h>
using namespace std;
#define int long long
 const int N=998244353;
 int n,m,ans=0,ans1=0;
 int a[5010];
 int sm[5010],f[5010][5010],dp[5010];
 int jc[5010],injc[5010];
int qsm(int x,int y){
	int as=1;
	while(y){
		if(y&1)as=as*x%N;
		x=x*x%N;
		y>>=1;
	}
	return as;
}
void init(){
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%N;
	injc[n]=qsm(jc[n],N-2);
	for(int i=n-1;i>=0;i--)injc[i]=injc[i+1]*(i+1)%N;
}
int C(int x,int y){return jc[x]*injc[y]%N*injc[x-y]%N;}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	init();
	for(int i=3;i<=n;i++)ans1=(ans1+C(n,i))%N;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]+a[j]>a[n])break;
			f[i][a[i]+a[j]]++;
		}
	}
	for(int i=1;i<=a[n];i++)sm[i]=f[2][i];
	for(int i=3;i<=n;i++){
		for(int j=a[i];j<=a[n];j++)f[i][j]=(f[i][j]+sm[j-a[i]])%N;
		for(int j=2;j<=a[n];j++)sm[j]=(sm[j]+f[i][j])%N;
	}
	for(int i=1;i<=a[n];i++)sm[i]=f[2][i];
	for(int i=3;i<=n;i++){
		for(int j=2;j<=a[i];j++)dp[i]=(dp[i]+sm[j])%N;
		for(int j=1;j<=a[n];j++)sm[j]=(sm[j]+f[i][j])%N;
		ans=(ans+dp[i])%N;
	}
	cout<<(ans1-ans+N)%N;
	return 0;
}
