#include<bits/stdc++.h>
using namespace std;
struct manyidu
{
	int a1[];
	int a2[];
	int a3[];
}a;
void an(int a[],int y)
{
	int ans=0;
	for(int i=0;i<y;i++)
	{
		ans+=a[i];
	}
	cout<<ans;
}
void maxm(int a[],int b[],int c[],int r)
{
	int m[r];
	for(int i=0;i<r;i++)
	{
		m[i]=max(max(a[i],b[i]),c[i]);
	}
	an(m,r);
}

void sr(int t,int q,int w)
{
	for(int i=0;i<w;i++)
	{
		cin>>a.a1[i]>>a.a2[i]>>a.a3[i];
	}
	maxm(a.a1,a.a2,a.a3,w);
} 

int main()
{
	freopen("club.in","r",std in);
	freopen("club.out","w",std out);
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		sr(t,i,n);
	}
}