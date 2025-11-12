#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int NN=5e2+5;
int m;
int n;
int c[NN],f[NN],t,p;
string s;
ll ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1') 
		{
		    t++;
		}
	}
	if(t<m) printf("0");
	else printf("1");
	return 0;
}

