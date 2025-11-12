#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL mod=998244353;
LL n,m,s,f=-1;
LL a[505];
LL nd[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
		if(f==-1&&a[i]==1)f=i-1;
	}
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>f)s++;
	}
	for(LL i=1;i<n;i++){
		s=s*i%mod;
	}
	cout<<s;
	return 0;
}//kf
