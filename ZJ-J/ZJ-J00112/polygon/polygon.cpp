#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,arr[5010],yh[5010][5010],cnt=0;
bool tepan=1;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]!=1)tepan=0;
	}
	if(tepan){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(j==0||j==i)yh[i][j]=1;
				else yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
				yh[i][j]%=mod;
			}
		}
		int ans=0;
		for(int i=3;i<=n;i++)ans+=yh[n][i],ans%=mod;
		cout<<ans;
		return 0;
	}
	for(int i=0;i<(1<<n);i++){
		int k=i,maxx=0,sum=0,tot=0;
		while(k){
			int bit=k&1;
			k>>=1;
			if(bit)sum+=arr[tot],maxx=max(maxx,arr[tot]);
			tot++;
		}
		if(sum>maxx*2)cnt++;
	}
	cout<<cnt;
}