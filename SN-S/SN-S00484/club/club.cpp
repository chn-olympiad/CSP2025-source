#include<bits/stdc++.h>
using namespace std;
int t,n,a[10],f[5];
struct Node
{
	priority_queue <int> q;
};
Node m[5];
int main()
{
	freopen("club.in ","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		memset(f,0,sizeof(f));
		memset(m,0,sizeof(m));
		int sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1];
			cin>>a[2];
			cin>>a[3];
			int maxn=max(max(a[1],a[2]),a[3]);
			for(int j=1;j<=3;j++)
			{
				if(a[j]==maxn)
				{
					if(a[1]<a[2]) swap(a[1],a[2]);
					if(a[1]<a[3]) swap(a[1],a[3]);
					if(a[2]<a[3]) swap(a[2],a[3]);
					f[j]++;
					if(f[j]>(n/2))
					{	
						if(abs(m[j].q.top())<(maxn-a[2]))
						{
							
							sum=sum+maxn+m[j].q.top();
							m[j].q.pop();
							m[j].q.push(a[2]-maxn);
						}
						else
						{
							sum+=a[2];
						}
					}
					else
					{
						m[j].q.push(a[2]-maxn);
						sum+=maxn;				
					}
					break;
				}
			}	
		}
		cout<<sum<<endl;
	}
	return 0;
}
