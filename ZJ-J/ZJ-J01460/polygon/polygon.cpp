#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define R register
#define LL long long
using namespace std;
const int N=5e5+10,mod=998244353;
int n,a[N],sum;
LL f[N],ans;
inline LL work(int x){
	f[0]=1;
	for(R int i=1;i<=sum;i++) f[i]=0;
	for(R int i=1;i<x;i++)
		for(R int j=sum-a[x];j>=a[i];j--)
			f[j]=(f[j]+f[j-a[i]])%mod;
	LL s=0;
	for(R int i=a[x]+1;i<=sum;i++) s=(s+f[i])%mod;
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(R int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(R int i=1;i<=n;i++){
		sum+=a[i];
		ans=(ans+work(i))%mod;
	}
	cout<<ans<<'\n';
	return 0;
}
