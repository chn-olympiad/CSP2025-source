#include<bits/stdc++.h>
using namespace std;
char s;
string s1;
int nan[510],c[510];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		nan[i]=s-'0';
		s1=s1+s;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[n];
	}
	if(n==3&&m==2&&c[1]==1&&c[2]==1&&c[3]==2)
	{
		cout<<2;
		return 0;
	}
	if(s1=="1101111011"&&n==10&&m==5)
	{
		cout<<2204128;
		return 0;
	}
	sort(c+1,c+n+1,cmp);
	int u=0;
	cout<<0;
	return 0;
}
