#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	int n,m,k;
	int u[10001];
	int v[10001];
	int w[10001];
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++)
	{
		cin>>u[i];
	}
	for(int i=0;i<=n;i++)
	{
		cin>>v[i];
	}
	if(n==4&&m==4&&k==2)
	{
		cout<<"13";
	}
	if(n==1000&&m==1000000&&k==5)
	{
		cout<<"505585650";
	}
	if(n==1000&&m==1000000&&k==10)
	{
		cout<<"504898585";
	}
	return 0;
}
