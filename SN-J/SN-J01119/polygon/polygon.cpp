#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m=0,s=0;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--)
	{
		for(int j=i-1;j>=2;j--)
		{
			
			for(int v=j-1;v>=1;v--)
			{
				if(a[v]+a[j]>a[i])
					m+=1;
			}
					
		}
	}		
	cout<<m;
	return 0;
} 
