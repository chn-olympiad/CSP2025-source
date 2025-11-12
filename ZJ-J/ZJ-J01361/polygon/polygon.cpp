#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],sum[5005],ans,c[5005][5005];
const int mod=998244353;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=0;i<(1<<n);i++){
			ll ma=0,cnt=0;
			for(int j=0;j<n;j++){
				if((i&(1<<j))){
					cnt+=a[j];
					ma=max(ma,a[j]);
				}
			}
			if(cnt>ma*2){
				ans++;
			}
	//			cout<<cnt<<" "<<ma*2<<"\n";
		}
	}else{
		sort(a+1,a+1+n,cmp);
		c[0][0]=c[1][0]=c[1][1]=1;
		for(int i=2;i<=n;i++){
			c[i][0]=1;
			for(int j=1;j<=i;j++){
				c[i][j]=c[i-1][j]+c[i-1][j-1];
				c[i][j]%=mod;
			}
		}
		int m;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				m=i;
				break;
			}
		}
		int cnt=1;
		for(int i=1;i<=n-m;i++){
			cnt+=c[n-m][i];
			cnt%=mod;
		}
		for(int i=3;i<=m;i++){
			ans+=c[m][i]*cnt%mod;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4
*/