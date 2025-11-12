#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s[510],c[510],p[510];
int res=0;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)p[i]=i;
	int ans=0;
	do{
		int res=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]&&(res<c[p[i]]))num++;
			else res++;
		}
		if(num>=m)ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}








