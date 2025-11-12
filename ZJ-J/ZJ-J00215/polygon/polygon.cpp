#include<bits/stdc++.h>
using namespace std;
int n,a[500001],used[500001],q[500001],ma,sum;
long long cnt;
int check(int x,int y,int z)
{
	int sum2=x+z;
	int ma2=max(y,z);
	if(sum2>ma2*2) return 1;
	else return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3&&(a[1]+a[2]+a[3])-max(a[1],max(a[2],a[3]))>max(a[1],max(a[2],a[3])))
	{
		cout<<1;
		return 0;
	} 
	else if(n==3&&(a[1]+a[2]+a[3])-max(a[1],max(a[2],a[3]))<=max(a[1],max(a[2],a[3])))
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
//		memset(used,0,sizeof(used));
		memset(q,0,sizeof(q));
		used[i]=1;
		q[1]=a[i];
		for(int j=i+1;j<=n;j++)
		{
			memset(used,0,sizeof(used));
			used[i]=1;
			if(used[j]==1) continue;
			used[j]=1;
			q[2]=a[j];
			int s=1,e=2;
			sum=q[1]+q[2],ma=max(q[1],q[2]);
			while(s<=e)
			{
				s++;
				for(int k=j+1;k<=n;k++)
				{
					if(used[k]==1) continue;
					if(check(sum,ma,a[k])==0) continue;
					
					q[++e]=a[k];
					sum+=a[k];
					ma=max(ma,a[k]);
					cnt++;
					used[k]=1;
				}
				
			}
		}
		cnt=cnt%998;
		cnt=cnt%244;
		cnt=cnt%353;
	}
	cout<<cnt;
	return 0;
}
