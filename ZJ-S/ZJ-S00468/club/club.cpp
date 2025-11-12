#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
long long ans;
long long b[N];
long long c[N][4];
long long d[N];
long long mxa;
long long n;
priority_queue<long long> q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--)
	{
		b[1]=0;
		b[2]=0;
		b[3]=0;
		mxa=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>c[i][1]>>c[i][2]>>c[i][3];
			if(c[i][1]>=c[i][2]&&c[i][1]>=c[i][3])
			{
				b[1]++;
				d[i]=1;
				ans+=c[i][1];
			}	
				else if(c[i][2]>=c[i][3])
			{
				b[2]++;
				d[i]=2;
				ans+=c[i][2];
			}
			else
			{
				b[3]++;
				d[i]=3;
				ans+=c[i][3];
			}
		}
		if(b[1]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i]==1)
				{
				q.push(-min(c[i][1]-c[i][2],c[i][1]-c[i][3]));
				}
	    	}	
		}
		if(b[2]>n/2)
		{
				for(int i=1;i<=n;i++)
			{
				if(d[i]==2)
				{
				q.push(-min(c[i][2]-c[i][1],c[i][2]-c[i][3]));
				}
	    	}	
		}
		if(b[3]>n/2)
		{
				for(int i=1;i<=n;i++)
			{
				if(d[i]==3)
				{
				q.push(-min(c[i][3]-c[i][2],c[i][3]-c[i][1]));
				}
	    	}	
		}
		while(q.size()>n/2)
		{
			ans+=q.top();
			q.pop();
		}
		cout<<ans<<endl;
		while(!q.empty())
		q.pop();
	}
	return 0;
}
