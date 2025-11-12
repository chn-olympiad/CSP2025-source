#include<bits/stdc++.h>
using namespace std;
string a[200001][2],ta,tb;
string read()
{
	string y="";
	char x;
	x=getchar();
	while(x==' '||x=='\n')x=getchar();
	while(x!=' '&&x!='\n')
	{
		y=y+x;
		x=getchar();
	}
	return y;
}
int n,q,k;
long long s;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		a[i][0]=read();
		a[i][1]=read();
	}
	while(q--)
	{
		ta=read();
		tb=read();
		s=0;
		for(int i=1;i<=n;i++)
		{
			k=0;
			while(ta.find(a[i][0],k)!=-1)
			{
				k=ta.find(a[i][0],k);
				ta.replace(k,a[i][1].size(),a[i][1]);
				if(ta==tb)s++;
				ta.replace(k,a[i][0].size(),a[i][0]);
				k++;
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
//time limit exceed,don't learn me.
