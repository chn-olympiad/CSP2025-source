#include<bits/stdc++.h>
using namespace std;
bool f[501000];
long long a[501000],s,n,r;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n-j+1;i++)
		{
			long long y=0;
			if(f[i]) continue;
			y^=a[i];
			for(int k=1;k<j;k++) 
				if(f[i+k])	
				{
					for(int x=i;x<i+k;x++) f[x]=1;
					break;
				}
				else y^=a[i+k];		
			if(y==r&&!f[i]) 
			{
				s++;
	 			for(int x=i;x<=i+j-1;x++) f[x]=1;
			}
		}	
	cout<<s;
	return 0;
}
/*
4 2
2 1 0 3
4 3
2 1 0 3
4 0
2 1 0 3
*/