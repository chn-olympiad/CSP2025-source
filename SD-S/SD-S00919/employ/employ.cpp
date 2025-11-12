#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int n,m,b=1;
string s;
__int128 tot=1;
void cc()
{
	for(int i=n;i>n-m;i--)
	{
		tot*=i;
	}
	tot/=m;
	tot%=998244353; 
	while(tot!=0)
	{
		char c=tot%10+'0';
		s=c+s;
		tot/=10;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		char c;
		cin>>c;
		if(c=='1')
		{
			b=0;
		}
	}
	if(b)
	{
		cc();
		cout<<s<<endl;
	}
	else
	{
		cout<<0<<endl;
	} 
	return 0;
}
//I love CCF 
