#include<bits/stdc++.h>
using namespace std;
int a[500005]={0},l[500005]={0},r[500005],p[500005]={0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x=0,d=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+1-i;j++)
		{
			int t=i,x=0,t1=i;
			while(t)
			{
				t--;
				x^=a[j+t];
			}
			if(x==k)
			{
				
				l[d]=j;
				r[d]=j+i-1;
				p[d]=l[d]+r[d];
				d++;
			}
		}
	}
	d--;
	for(int i=1;i<=d;i++)
	{
		for(int j=i+1;j<=d;j++)
		{
			if(p[i]>p[j])
			{
				swap(p[i],p[j]);
				swap(r[i],r[j]);
				swap(l[i],l[j]); 
			}
		}
	}
	for(int i=1;i<=d;i++)
	if(l[1]==0)
	{
		cout<<"0";
		return 0; 
	}
	int m=1;
	x=1;
	for(int i=1;i<=d;i++)
	{
		
		if(r[x]<l[i])
		{
			m++;
			x=i;
		}
	}
	cout<<m;
}
