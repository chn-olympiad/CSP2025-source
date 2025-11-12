#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,k;
	cin>>n>>m;
	k=n;
	string st;
	long long a[1003],s[1003];
	cin>>st;
	s[1]=0;
	for(long long i=1;i<n;i++)s[i+1]=s[i]-st[i-1]+1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) k--;
	}
	sort(a+1,a+n+1);
	long long ans=1;
	for(long long i=1;i<=k;i++){
		ans*=(k-i+1)%998244353;
	}
	cout<<ans;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
