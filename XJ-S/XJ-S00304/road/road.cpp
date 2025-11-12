#include<bits/stdc++.h>
using namespace std;
bool l[100005];
int s;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u[100005],v[100005],w[100005],a[100005];
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		if(l[u[i]]==false&&l[v[i]]==false)
		{
			s+=w[i];
			l[u[i]]=true;
			l[v[i]]=true;
		}
	}
	int c,a1[100005];
	for(int i=1;i<=k;i++)
	{
		int f=0;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>a1[j];
			if(l[j]==false)
			{
				l[j]=true;
				if(f==0)
				{
					s+=a1[j];
					s+=c;
				}
				else
				{
					s+=a1[j];
				}
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
