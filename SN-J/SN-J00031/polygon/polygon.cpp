#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],b[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=1;i<=(1<<n)-1;i++){
		memset(b,0,sizeof(b));
		int cnt=0;
		int num=__builtin_popcount(i);
		if(num<3) continue;
		int y=i;
		for(int j=1;j<=n;j++){
			if(y&1) b[++cnt]=a[j];
			y>>=1;
		}
		int maxn=0,sum=0; 
		for(int j=1;j<=cnt;j++){
			maxn=max(maxn,b[j]);
			sum+=b[j];
		}
		if(sum>maxn*2) ans++;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
