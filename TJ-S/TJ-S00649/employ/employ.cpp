#include <bits/stdc++.h>
using namespace std;
long long c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m; 
	string s;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
			sum++;
		}
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	long long ans=1;
	for(long long i=1;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
} 
