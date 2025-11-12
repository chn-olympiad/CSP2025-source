#include<bits/stdc++.h>
using namespace std;
int n,k,f[500010],s[500010],l[(1<<21)+5],x;
int read()
{
	int x;
	char ch;
	while(1)
	{
		ch=getchar();
		if(ch>='0'&&ch<='9') 
		{
			x=ch-'0';
			break;
		}
	}
	while(1)
	{
		ch=getchar();
		if(ch>='0'&&ch<='9') x=x*10+ch-'0';
		else return x;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    n=read();k=read();
    for(int i=1;i<=n;i++)
    {
    	x=read();
    	s[i]=s[i-1]^x;
	}
	for(int i=1;i<=n;i++)
	{
		if(l[s[i]^k]==0) f[i]=f[i-1];
		else f[i]=max(f[i-1],f[l[s[i]^k]]+1);
		if((s[i]^s[i-1])==k) f[i]=f[i-1]+1;
		if(s[i]==k) f[i]=max(f[i],1);
		l[s[i]]=i;
	}
	printf("%d\n",f[n]);
	return 0;
}
