#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5,mod=998244353;
int n;
int a[N],f[N];
int ans;
signed main(){
//	system("fc polygon.out polygon4.ans");
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[0]=1;
	ans=1;
	for(int i=1;i<=n;i++){
		ans*=2;
		if(ans>=mod){
			ans-=mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i];j>=0;j--){
			ans-=f[j];
			if(ans<0){
				ans+=mod;	
			}
		}
		for(int j=a[n];j>=a[i];j--){
			f[j]+=f[j-a[i]];
			if(f[j]>=mod){
				f[j]-=mod;
			}
		}
	}
	ans--;
	if(ans<0){
		ans+=mod;
	}
	cout<<ans;
	return 0;
}
