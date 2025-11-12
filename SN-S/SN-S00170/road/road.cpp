#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,num=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		num+=c;
	}
	for(int i=0;i<k;i++)
	{
		int aa;
		cin>>aa;
		for(int j=0;j<n;j++)
		{
			int l;cin>>l;
		}
		num+=aa;
	}
	
	
	
	cout<<num;
	
	
	
	
	
	
	
	
	
	
	
	return 0;
 } 
