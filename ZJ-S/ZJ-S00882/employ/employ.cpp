#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,m,c[505],num,ans=0;
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.size();
	for(int i=1; i<=n; i++)cin>>c[i];
	for(int i=0; i<len; i++)
		if(s[i]=='1')num++;
	if(num<m) {
		cout<<0;
		return 0;
	}
	if(num==n) {
		ans=1;
		for(int i=1; i<=n; i++)ans=(ans*i)%Mod;
		cout<<ans;
		return 0;
	}
	return 0;
}

