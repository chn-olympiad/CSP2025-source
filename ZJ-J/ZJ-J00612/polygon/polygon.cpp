#include<bits/stdc++.h>
using namespace std;
long long i,n,ans,a[5010],b[5010],f[5010];
void sc(long long t,long long g,long long c){
	long long i;
	if(t>g){
		long long s=0,ma=0;
		for(i=1;i<=t;i++)
			ma=max(ma,b[i]),s+=b[i];
		if(s>ma*2) ans++;
		ans%=998244353;
		return;
	}
	for(i=c;i<=n;i++)
		if(!f[i]){
			f[i]=1;b[t]=a[i];
			sc(t+1,g,i+1);
			f[i]=0;b[t]=0;
		}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=3;i<=n;i++) sc(1,i,1);
	cout<<ans;
	return 0;
}

