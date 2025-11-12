#include<bits/stdc++.h>
using namespace std;
int n,k,a[200010],p[200010],f[200010];
int s(int x,int y)
{
	return p[y]^p[x-1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=p[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=i;j>=1;j--)
		{
			if(f[i]-f[j-1]>=1)
				break;
			if(s(j,i)==k)
			{
				f[i]++;
				break;
			}
		}
	}
	cout<<f[n];
	return 0;
}
