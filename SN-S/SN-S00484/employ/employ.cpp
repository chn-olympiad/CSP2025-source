#include<bits/stdc++.h>
using namespace std;
int m,n,p,c[510],f;
char s[510];
int main()
{
	freopen("employ.in ","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0) f++;
	}
	if(f>=m) cout<<0;
	else cout<<1;
	return 0;
}
