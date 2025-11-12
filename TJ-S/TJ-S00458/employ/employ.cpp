#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
int a[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	bool f=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0')f=0;
	}
	if(f)
	{
		sort(a+1,a+n+1);
		
	}
	return 0;
}
