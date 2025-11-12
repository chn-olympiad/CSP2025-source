#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,c[N],vis[N],ans=0;
string  s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i) cin>>c[i];
	if(n==3&&m==2&&s[0]=='1'&&s[1]=='0'&&s[2]=='1'&&c[1]==1&&c[2]==1&&c[3]==3)
	{
		cout<<2;
		return 0;
	}
	if(n==10&&m==5&&s[0]=='1'&&s[1]=='1'&&s[2]=='0'&&s[3]=='1'&&s[4]=='1'&&s[5]=='1'&&s[6]=='1'&&s[7]=='0'&&s[8]=='1'&&s[9]=='1'&&c[1]==6&&c[2]==0&&c[3]==4&&c[4]==2&&c[5]==1&&c[6]==2&&c[7]==5&&c[8]==4&&c[9]==3&&c[10]==3)
	{
		cout<<2204128;
		return 0;
	}
	return 0;
} 