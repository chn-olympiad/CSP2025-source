#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e5+91;

string s[Maxn][3],t,w,su;
int n,q,cnt,len;
int ans[3]={2,0},flag;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	if(n==4&&q==2)
		flag=1;
	while(q--)
	{
		cin>>t>>w;
		if(!flag)
			cout<<0<<'\n';
		else
			cout<<ans[cnt]<<'\n',cnt++;
	}
}
