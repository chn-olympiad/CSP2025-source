#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool b[500005];
int s1(int l,int r)
{
	int x=0;
	for(int i=l;i<=r;i++)
	{
		if(b[i]==1)
			return -1;
		x=x^a[i];
	}
	return x;
}
void s2(int l,int r)
{
	for(int i=l;i<=r;i++)
		b[i]=1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int c=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			if(s1(j,j+i-1)==k)
			{
				c++;
				s2(j,j+i-1);
			}
	cout<<c;
	return 0;
}
