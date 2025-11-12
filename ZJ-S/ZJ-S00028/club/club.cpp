#include<bits/stdc++.h>
using namespace std;
int n;
int a[5][150005];
struct node{
	int op,mx,cj;
}b[150005];
bool cmp(node x,node y)
{
	return x.cj<y.cj;
}
int sum[55];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t; 
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans=0;
		int i,j;
		sum[1]=sum[2]=sum[3]=0;
		for(i=1;i<=n;i++)
		{
			int op1=0,mx1=0,mx2=0;
			cin>>a[1][i]>>a[2][i]>>a[3][i]; 
			if(a[1][i]>mx1)
			{
				mx2=mx1;
				mx1=a[1][i];
				op1=1;
			} 
			else if(a[1][i]>mx2)
			{
				mx2=a[1][i];
			}
			if(a[2][i]>mx1)
			{
				mx2=mx1;
				mx1=a[2][i];
				op1=2;
			} 
			else if(a[2][i]>mx2)
			{
				mx2=a[2][i];
			}
			if(a[3][i]>mx1)
			{
				mx2=mx1;
				mx1=a[3][i];
				op1=3;
			} 
			else if(a[3][i]>mx2)
			{
				mx2=a[3][i];
			}
			ans+=mx1;
			sum[op1]++;
//			b[i]={op1,mx1,mx1-mx2};
			b[i].op=op1;
			b[i].mx=mx1;
			b[i].cj=mx1-mx2;
		}
		sort(b+1,b+1+n,cmp);
		int op=0;
		if(sum[1]>sum[op])op=1;
		if(sum[2]>sum[op])op=2;
		if(sum[3]>sum[op])op=3;
		int cnt=sum[op]-n/2;
		for(i=1;cnt>0&&i<=n;i++)
		{
			if(b[i].op==op)
			{
				ans-=b[i].cj;
				cnt--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
