#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long n,a[5005],ans;
bool key=1;
void dfs(long long i,long long k,long long sum,long long mx,bool b) {
	if(b && k>=3 && sum>2*mx)ans=(ans+1)%Mod;
	if(i>n)return ;
	dfs(i+1,k,sum,mx,0);
	dfs(i+1,k+1,sum+a[i],max(mx,a[i]),1);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(i>1 && a[i]!=a[i-1])key=0;
	}
	if(key) {
		for(int i=3; i<=n; i++) {
			long long cnt=1;
			for(int j=1; j<=i; j++) {
				cnt=(cnt*(n-j+1)%Mod/j)%Mod;
			}
			ans=(ans+cnt)%Mod;
		}
	} else dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}

