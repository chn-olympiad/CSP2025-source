#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,k,o,a[500005],s[500005],ans,f[500005],g;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	s[i]=s[i-1]+a[i];
	if(n==3){
		if(a[3]*2<a[1]+a[2]+a[3])
		cout<<1;
		else
		cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
	if(s[i-1]>a[i]){
		ans+=(n-i+1)*(s[i-1]*a[i]);
	}
	}
	cout<<ans;
	return 0;
}
