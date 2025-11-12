#include<bits/stdc++.h>
using namespace std;
string s;
long long ans=1,mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	cin >> s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin >> a;
		if(a==0 || s[i]=='0')
		{
			cout << 0;
			return 0;
		}
		ans=ans*i%mod;
	}
	cout << ans;
	return 0;
}
