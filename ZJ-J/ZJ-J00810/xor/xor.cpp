#include<bits/stdc++.h>
using namespace std;
long long __xor(long long x,long long y) {
	int xx[30],yy[30],ans=0;
	int lenx=0,leny=0;
	memset(xx,0,sizeof xx);
	memset(yy,0,sizeof yy);
	while(x!=0)xx[lenx++]=x%2,x/=2;
	while(y!=0)yy[leny++]=y%2,y/=2;
	for(int i=0; (i<lenx || i<leny); i++)ans+=((xx[i]+yy[i])%2)*pow(2,i);
	return ans;
}
long long n,k,a[500005],sum[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum[i]=__xor(sum[i-1],a[i]);
	}
	long long ans=0,cnt=0;
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			int cnt=__xor(sum[i-1],sum[j]);
			if(cnt==k) {
				ans++,i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

