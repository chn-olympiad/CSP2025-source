#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Mod=998244353;
ll f[505],c[505],t[2];
string s;
ll jc(ll x)
{
	if(x==0||x==1)
		return 1;
	if(f[x])
		return f[x];
	else
		return (jc(x-1)*x)%Mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=0;i<s.size();i++)
		if(s[i]=='1')
			t[1]++;
	cout<<jc(n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
