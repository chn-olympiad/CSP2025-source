#include<bits/stdc++.h>
using namespace std;
int a[5005];
int bj[5005];
int n;
long long o=0;
long long mod=998244353;
void dfs(int qq,int gs,int h,int mxs)
{
//	cout<<qq<<" "<<endl;
	if(qq==n+1&&gs>=2)
	{
		for(int i=1;i<=n;i++)
		{
			if(bj[i]==0)
			{
				long long l1=mxs,l2=h-mxs,l3=a[i];
				long long l4=max(l1,l2);
				long long l5=max(l4,l3);//zd
				long long l6=min(l1,l2);
				long long l7=min(l2,l3);//zs
				long long l8;//zj
				if(l1!=l5&&l1!=l7)l8=l1;
				if(l2!=l5&&l2!=l7)l8=l2;
				if(l3!=l5&&l2!=l7)l8=l3;
				if(l7+l8>l5&&l5>abs(l8-l7))
				{
				o++;
				o=o%mod;
			
				}
			}
		}
		return;
	}
	else if(qq==n+1)
	{
		return;
	}
	for(int i=0;i<=1;i++)
	{
		if(i==0)
		{
			dfs(qq+1,gs,h,mxs);
		}
		else
		{
			if(a[qq]>mxs)
			bj[qq]=1;
			dfs(qq+1,gs+1,h+a[qq],a[qq]);
			bj[qq]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<o;
	return 0;
}
