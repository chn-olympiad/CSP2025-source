#include<bits/stdc++.h>
using namespace std;
long long n,ans=1;
string s;
int a[1006];
int main()
{
	long long m;
	cin>>n>>m;
	char c;
	c=getchar();        
	getline(cin,s);
	int countloss=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) if(a[i]==0) countloss++;else{a[i]-=countloss;if(a[i]<=0) countloss++;}
	for(int i=n-countloss;i>=m;i--) ans*=i,ans%=998244353;
	cout<<ans;
	return 0;
}