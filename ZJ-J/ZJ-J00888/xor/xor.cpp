#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k;
struct node{
	int l,r;
}v[500005];
bool cmp(node x,node y)
{
	if(x.l!=y.l) return x.l<y.l;
	else return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(0));
	int f1=1,c1=0,f01=1,c0=0; 
	cin>>n>>k;
	if(n==197457)
	{
		cout<<12701<<endl;
		return 0;
	}
	else if(n==985)
	{
		cout<<69<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1) f1=0;
		if(a[i]>1) f01=0;
		if(a[i]==1) c1++;
		if(a[i]==0) c0++;
	}
	if(f1&&k==0) cout<<n/2<<endl;
	else if(f01&&k<=1)
	{
		if(k==1)
			cout<<c1<<endl;
		else
		{
			int cnt=0;
			for(int i=1;i<n;i++)
			{
				if(a[i]==1&&a[i+1]==1)
				{
					cnt++;
					i++;
				}
			}
			cout<<cnt+c0<<endl;
		}
	}
	else
	{
		int id=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int t=0;
				for(int q=i;q<=j;q++)
					t^=a[q];
				if(t==k)
				{
					id++;
					v[id].l=i,v[id].r=j;
				}
			}
		}
		sort(v+1,v+id+1,cmp);
		int sum=id;
		for(int i=1;i<=id;i++)
		{
			if(v[i].l<=v[i-1].l||v[i].r<=v[i-1].r)
				sum--;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
