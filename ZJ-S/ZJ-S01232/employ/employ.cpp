#include<bits/stdc++.h>
using namespace std;
int n,m,s[1010],c[1010],f=1,k,p;
long long h;
string s1;
long long o=998244353;
int main()
{ 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s1;
	for(int i=0;i<=n-1;i++)
	{
		s[i+1]=int(s1[i])-48;
		if(s[i+1]!=1)f=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)k++;
	}
	if(f==1)
	{
		if(n-k<m)cout<<"0";
		else
		{
			h=1;
			for(int i=1;i<=n;i++)
			{
				h=h*i;
				h=h%o;
			}
			cout<<h;
		}
	}
	return 0;
}
