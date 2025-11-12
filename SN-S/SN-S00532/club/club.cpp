//王雅宁  SN-S00532 西安市曲江第一中学、
#include<bits/stdc++.h>
using namespace std;
int t,n,s=0,x=0,y=0,z=0,a,b,c;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		while(n--)
		{		
			cin>>a>>b>>c;
			if(x<n/2 && max(max(a,b),c)==a)
			{
				x++;
				s+=x*a;		
			}
			else if(y<n/2 && max(max(a,b),c)==b)
			{
				y++;
				s+=y*b;
			}
			else if(z<n/2 && max(max(a,b),c)==c)
			{
				z++;
				s+=z*c;
			}
		}
		cout<<s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
