#include<bits/stdc++.h>
using namespace std;
#define int long long
bool st;
int a[100005];
int f[25000005];
int n;
const int mod=998244353;
bool ed;
signed main(){
//	cout<<(&st-&ed)/1024.0/1024.0<<endl;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0,m=0;
	f[0]=1;
	for(int i=1;i<=n;i++){
		m+=a[i];
		if(i>=3){
			for(int j=a[i]+1;j<=m;j++){
				ans=(ans+f[j])%mod;
			}
		}
		for(int j=m;j>=a[i];j--){
			f[j]=(f[j]+f[j-a[i]])%mod;	
		}
	}
	cout<<ans;
}

