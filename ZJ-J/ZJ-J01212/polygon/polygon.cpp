#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=10010;
#define lz long long
int n,m;
int f[N];
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++)cin >>a[i],a[i]%=mod;
	sort(a+1,a+n+1);
	f[0]=1;
	int ans=0;
	int m=N-9;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=m-a[i]+1;j--)
			ans+=f[j],ans%=mod,f[m]+=f[j],f[m]%=mod;
		for(int j=m;j>=a[i];j--){
			if(j>a[i]*2&&f[j-a[i]])
			ans+=f[j-a[i]];
			f[j]+=f[j-a[i]];
			f[j]%=mod;
			ans%=mod;
		}	
	}
	cout<<ans<<"\n";
	return 0;
}

