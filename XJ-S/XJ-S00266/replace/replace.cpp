#include<bits/stdc++.h>
using namespace std;
int kmp[1000006];
char a[5000006];
int u[200005][3];
int u1[400005][3];
int bj[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int j=0,z=0,o=1;
		while(a[j]!=' ')
		{
			cin>>a[j++];
			if(a[j-1]=='a')
			{
				u1[i*2-1][z]++;
			}
			else
			{
				z=2;
				u1[i*2-1][1]=j-1;
			}
		}
		int jj=j;
		j=0;
		while(a[j]!='\n')
		{
			cin>>a[j++];
			if(a[j-1]=='a')
			{
				u1[i*2][z]++;
			}
			else
			{
				z=2;
				u1[i*2][1]=j-1;
			}
		}
		if(jj!=j)
		{
			bj[j]=1;	
		}
	}
	for(int i=1;i<=m;i++)
	{
		int j=0,z=0;
		while(a[j]!='\n')
		{
			cin>>a[j++];
			if(a[j-1]=='a')
			{
				u[i][z]++;
			}
			else
			{
				u[i][1]=j-1;
				z=2;
			}
		}
		int ooo=0;
		for(int i=1;i<=n;i++)
		{
			if(u1[i*2-1][0]<=u[i][0]&&u1[i*2][0]<=u[i][0]&&u1[i*2-1][2]>=u[i][2]&&u1[i*2][2]>=u[i][2]&&bj[i]==0)
			{
				ooo++;
			}
		}
		cout<<ooo<<endl;
	}
	return 0;
}
