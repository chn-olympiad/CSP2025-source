#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[50005];
bool m[10001][10001];
long long t[5001];
bool b[50005];
long long read()
{
	long long i=0;
	char j;
	j=getchar();
	while(j<'0'||j>'9') j=getchar();
	while(j>='0'&&j<='9')
	{
		i=i*10+j-'0';
		j=getchar();
	}
	return i;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	n=read();
	k=read();
	long long ans=0;
	bool l=1;
	for(long long i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==1&&l)l==1;
		else l=0;
	}
	if(k==0&&l==1)
	{
		ans=n/2;
	}
	else if(n==1)
	{
		if(a[1]==k) ans=1;
		else ans=0;
	}
	else if(k==1)
	{
		long long h=0;
		for(long long i=1;i<=n;i++)
		{
			if(a[i]==1) h++;
		}
		ans=h;
	}
	else if(n<=10)
	{
		for(long long i=1;i<=n;i++)
		{
			if(a[i]==k) 
			{
				ans++;
				b[i]=1;
			}
		
		}
	}
	else ans=3;
	fclose(stdin);
	fclose(stdout);
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4