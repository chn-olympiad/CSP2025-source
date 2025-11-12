//SN-J00384  张溪诺  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll l,r;
}a[10000100];
int g[1000010];
ll top,num,numm;
ll n,k;
bool cmp(node a,node b)
{
	return a.r<b.r;
}
bool cheak(int x,int y)
{
	ll s=0;
	for(int i=x;i<=y;i++)
	{
		s=s^g[i];
	}
	if(s==k)return true;
	else return false;
}
int main()
{
 	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>g[i];
		if(g[i]==k)numm++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(cheak(i,j))
			{
				a[++top].l=i;
				a[top].r=j;
			}
		}
	}
	sort(a+1,a+top+1,cmp);
	int p=a[1].r;
	num++;
	for(int i=2;i<=n;i++)
	{
		if(p<a[i].l)
		{
			p=a[i].r;
			num++;
		}
	}
	cout<<max(num,numm);
	return 0;
}

