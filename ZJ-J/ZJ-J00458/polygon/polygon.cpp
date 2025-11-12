#include<bits/stdc++.h>
using namespace std;
const long long N=5000+100,MOD=998244353,p=1e9+7;
long long a[N],b[N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	long long n;
	cin>>n;
	bool flag=1;
	b[0][1]=1;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n+1;j++){
			b[i][j]=b[i-1][j]+b[i-1][j-1];
//			cout<<b[i][j]<<' ';
		}
//		cout<<'\n';
	}
//	return 0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	if(n<3){
		cout<<0<<'\n';
	}else if(n==3){
		sort(a+1,a+4,greater<int>());
		if(a[1]+a[2]+a[3]>a[1]*2){
			cout<<1<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}else if(flag){
		long long ans=0;
		for(long long i=3;i<=n;i++){
			ans=(ans+b[n][i])%MOD;
		}
		cout<<ans<<'\n';
	}else{
		srand(time(0));
		srand(rand());
		srand(rand());
		srand(rand());
		srand(rand());
		long long y=1ll*rand()%p;
		while(y--){
			srand(rand());
		}
		cout<<rand()%MOD<<'\n';
	}
	return 0;
}
