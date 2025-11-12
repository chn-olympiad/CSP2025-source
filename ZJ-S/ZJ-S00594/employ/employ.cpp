#include<bits/stdc++.h>
using namespace std;
int n,m,a[600],b[600];
string s;
long long sum;
void f(int x,int y,int z)
{
	if(x>=m)
	{
		sum++;
		sum%=998244353;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			if(y<a[i])
			f(x,y+1,z+1);
			else if(s[z]=='1')
			f(x+1,y,z+1);
			else if(s[z]=='0')
			f(x,y+1,z+1);	
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f(0,0,0);
	cout<<sum;
	return 0;
}
