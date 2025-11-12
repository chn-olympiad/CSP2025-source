#include<bits/stdc++.h>

using namespace std;

const int N=5005,p=998244353;

int n,a[N],dpl[N][N],dpr[N][N],Max;
long long ans=0;int cnt[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],Max=max(Max,a[i]),cnt[a[i]]++;
	dpl[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=Max;j++){
			dpl[i][j]=dpl[i-1][j];
			if(j>=a[i])dpl[i][j]=(dpl[i][j]+dpl[i-1][j-a[i]])%p;
		}
	}
	dpr[n+1][0]=1;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=Max;j++){
			dpr[i][j]=dpr[i+1][j];
			if(j>=a[i])dpr[i][j]=(dpr[i][j]+dpr[i+1][j-a[i]])%p;
		}
	}
	ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*2ll%p;
	ans=(ans-1+p)%p;
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=0;j<=a[i];j++){
			s=(s+dpl[i-1][j])%p;
			ans=(ans-1ll*s*dpr[i+1][a[i]-j]%p+p)%p;
		}
	}
	for(int i=1;i<=Max;i++)
		ans=(ans+(1ll*(cnt[i]-1)*cnt[i]/2)%p)%p;
	cout<<(ans%p)<<"\n";
	return 0;
}
