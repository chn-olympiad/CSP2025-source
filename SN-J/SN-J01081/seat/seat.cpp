#include<bits/stdc++.h>
using namespace std;
long long n,m,c=1,r=1,i,b=0;
long long a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	
	{
		for(int j=i+1;j<=n;j++)
		cin>>a[i];
		if(a[i]>a[i+1]){
		
		}
		else
		{
			
			r++;
			if(r%n==1)
			{
			
			c=2;
				c++;
				r=1;
			}
		}
		
		
		
		
		
	}

	cout<<c<<' '<<r; 
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
