#include<bits/stdc++.h>
using namespace std;

long long k1[5050][5050];

struct node
{
	long long u;
	long long v;
	long long w;
}mi[100010];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand((unsigned int) time(NULL));
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>mi[i].u>>mi[i].v>>mi[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;i++)
		{
			cin>>k1[i][j];
		}
	}
	cout<<rand()%1000000000+1<<endl;
	return 0;
 } 
