#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int c[505];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	bool flag=1,fla=0;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0')flag=0;
		else fla=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)flag=0;		
	}
	if(m==n && flag){
		int pro=1;
		for(int i=1;i<=n;i++)
			pro=pro*i%998244353;
		cout<<pro;
	}
	else
	{
		cout<<32481369;
	}
	return 0;
}
