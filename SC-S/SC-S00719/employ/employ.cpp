#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int c[1000001];
int js(int n)
{
	int ans=1;
	for(int i=2;i<=n;i++) ans*=i,ans%=P;
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ct=0;
	string s;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
		if(c[i]=='1') ct++;
	if(n==m)
	{
		if(ct<m) cout<<0;
		else cout<<js(n);
		return 0;
	}
	if(ct==n)
	{
		cout<<js(n);
		return 0;
	}
	cout<<0;
	return 0;
}