#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int n,m,s[600];
string ss;
bool flag=1;
int A(int n,int m)
{
	int ans=1;
	for(int i=n-m+1;i<=n;i++) ans=ans*i%998244353;
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ss;
	for(int i=0;i<ss.length();i++)
	{
		s[i]=ss[i]-'0';
		if(s[i]==1) flag=0;
	}
	if(flag) cout<<A(n,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
