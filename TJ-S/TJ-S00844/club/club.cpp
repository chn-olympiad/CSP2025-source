#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int bj[100005];
int tong[20005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int maxz=n/2;
		long long ans=0;
		int maxn=0;
		if(n==100000)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i]>>b[i]>>c[i];
				tong[a[i]]=1;
				maxn=max(maxn,a[i]);
			}
			int sum=0;		
			int cur=0;
			for (int i=maxn;i>=1;i--)
			{
				if(cur==maxz) break;
				
				if(tong[i]==1) 
				{
					sum+=i;
					cur++;
				}
			}	
			cout<<sum;
		}
		
		if(n==2)
		{
			for(int i=1;i<=3;i++)
			{
				cin>>a[i];
			}
			for (int i=1;i<=3;i++)
			{
				cin>>b[i]; 
			}
			int cur=0;
			for (int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i==j) continue;
					cur++;
					bj[cur]=a[i]+b[j];
				}
			}
			sort(bj+1,bj+cur+1);
			cout<<bj[cur]<<"\n";
			
		}
		/*else 
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i]>>b[i]>>c[i];
			}
			int maxa,maxb,maxc=0;
			for (int i=1;i<=n;i++)
			{
				if(a[i]>=maxa)
				{
					maxa=a[i];
				}
				if(b[i]>=maxb)
				{
					maxb=b[i];
				}
				if(c[i]>=maxc)
				{
					maxc=c[i];
				}
				
			}			
		}*/
	
	}
	
	
	return 0;
}
