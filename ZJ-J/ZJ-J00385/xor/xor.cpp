#include<bits/stdc++.h.>
using namespace std;
int k,n,m,a[500005],x[5000005],y[5000005],s,p,q;
bool b[500001][21],c[21];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]!=1) p=1;
	if(p==0)
	{
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		p=0;
		while(a[i]>0)
		{
			p++;
			b[i][p]=a[i]%2;
			a[i]/=2;
		}
	}
	p=0;
	while(k>0)
	{
		p++;
		c[p]=k%2;
		k/=2;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=20;j++)
		{
			if(b[i-1][j]==b[i][j]) b[i][j]=0;
			else b[i][j]=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			p=0;
			for(int k=1;k<=20;k++)
				if((b[i-1][k]==b[j][k]&&c[k]==1)||(b[i-1][k]!=b[j][k]&&c[k]==0))
				{
					p=1;
					break;
				}
			if(p==1) continue;
			m++;
			x[m]=i;y[m]=j;
		}
	if(m==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<m;j++)
			if(y[j]>y[j+1])
			{
				swap(x[j],x[j+1]);
				swap(y[j],y[j+1]);
			}
	s=1;
	q=y[1];
	for(int i=2;i<=m;i++)
	{
		if(x[i]>q)
		{
			s++;
			q=y[i];
		}
	}
	cout<<s;
	return 0;
}