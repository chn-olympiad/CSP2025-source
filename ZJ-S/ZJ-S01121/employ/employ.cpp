#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,f=1,cnt;
int p[100001];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out"."w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];if(s[i]==0) f=0;
	}
	sort(p+1,p+1+n);
	if(m==1) sa();
	if(m==n) sb();
	if(f==1) sc();
	return 0;
}