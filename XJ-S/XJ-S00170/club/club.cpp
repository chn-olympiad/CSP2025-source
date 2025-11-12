#include<bits/stdc++.h> 
using namespace std;
long long int i,j,n,s,t,m,l,r,p,q,k;
struct node
{
	long long int x,y,c,f=0;
}a[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		s=0;
		cin>>n;
		for(i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y>>a[i].c;
			if(a[i].y==0&&a[i].c==0)
			{
				for(i=1;i<=n/2;i++)
	            {	
	            r=0;
	            for(i=1;i<=n;i++)
				if(a[i].x>r&&a[i].f==0)
				{
					r=a[i].x;
					a[i].f=1;
				}
				s+=r;
			    }
			}
		cout<<s<<endl;
	}
	
	return 0;
}

