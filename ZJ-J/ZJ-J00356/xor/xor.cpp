#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s=1,ans=0;
int yih(int a,int b)
{
	int len1=0,len2=0;
	string a1,b1;
	while(a>0)
	{
		len1++;
		char x=(a%2)+'0';
		a1=a1+x;
		a/=2;
	}
	while(b>0)
	{
		len2++;
		char x=(b%2)+'0';
		b1=b1+x;
		b/=2;
	}
	int len=max(len1,len2);
	if(len1<len2)
	{
		swap(len1,len2);
		string c=a1;
		a1=b1;
		b1=c;
	}
	int z=0,x=1;
	char b11;
	for(int i=0;i<len;i++)
	{
		b11='0';
		char a11=a1[i];
		if(i<len2) 
			b11=b1[i];
		if(a11!=b11)
			z+=1*x;
		x*=2;
	}
	return z;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int z=0;
		for(int j=i;j>=s;j--)
		{
			z=yih(z,a[j]);
			if(z==k)
			{
				s=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
