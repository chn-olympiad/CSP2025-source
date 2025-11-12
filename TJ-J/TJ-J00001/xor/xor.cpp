#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],h,c;
struct cc{
	int l,r;
}d[500010];
bool cmp(cc a,cc b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int j;
		cin>>j;
		a[i]=a[i-1]^j;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			int q=a[i]^a[j];
			if(q==k)
			{
				int f=1;
//				cout<<i<<" "<<j<<" "<<q<<endl;
				d[++h].r=i;
				d[h].l=j+f;
			} 
		}
	}
	sort(d+1,d+h+1,cmp);
	d[0].l=d[0].r=-1;
	int e=-1;
	for(int i=1;i<=h;i++)
	{
		if(d[i].l>d[e].r)
		{
			c++;
			e=i;
		}
	}
	cout<<c;
	return 0;
} 
