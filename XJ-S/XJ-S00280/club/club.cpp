#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int arr[100000],tong[3],maxx[3],sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int a=1;a<=n;a++)
		{
			int x,y,z;
			cin>>x>>y>>z; 
			maxx[a]=max(max(x,y),z); 
			if(maxx[a]==x)
				tong[1]++;
			else if(maxx[a]==y)
				tong[2]++;
			else if(maxx[a]==z)
				tong[3]++;        
		}
		            
		if(tong[1]<=n/2&&tong[2]<=n/2&&tong[3]<=n/2)
		{
			for(int i=1;i<=n;i++)
				sum+=maxx[i];
				cout<<sum;
		}
	}
	return 0;
}
