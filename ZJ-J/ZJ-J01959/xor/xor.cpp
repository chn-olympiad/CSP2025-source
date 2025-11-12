#include<bits/stdc++.h>
using namespace std;
long long a[5005],ans,k,n,ansi;
struct po
{
	int l,r;
};
po p[12502505];
bool cmp(po a,po b)
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
		cin>>a[i];
		a[i]=(a[i]^a[i-1]);
	}
	int pos=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if((a[r]^a[l-1])==k)
			{
				p[pos].l=l;
				p[pos].r=r;
				pos++;
			}
		}
	}
	sort(p,p+pos,cmp);
	int l_can=0;
	for(int i=0;i<pos;i++)
	{
		if(p[i].l>l_can)
		{
			ans++;
			l_can=p[i].r;
		}
	}
	
	cout<<ans;
	
	

	return 0;
}
