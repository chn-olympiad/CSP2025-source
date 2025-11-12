#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int u[1000005];
int v[1000005];
int w[1000005];
int c[10];
int a[10][10005];
bool cmp(int a,int b){
	return a<b;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int l=0;
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=0;j<k;j++)
	{
		cin>>c[j];
		for(int i=0;i<n;i++)
		{
			cin>>a[j][i];
		}
	}
	sort(w,w+m,cmp);
	long long cnt=0;
	for(int i=0;i<n-1;i++) cnt+=w[i];
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
}
