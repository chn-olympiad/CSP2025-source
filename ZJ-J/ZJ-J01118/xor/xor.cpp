#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005]={},q=0,p=0,r;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int g=i+1,y=a[i];
			while(g<=j)
			{
				int x=a[g],s=0,b=0;
				while(x>0||y>0)
				{
					if(x%2!=y%2) s+=pow(2,b);
					x=x/2;y=y/2;b++;
				}
				y=s;g++;
			}
			if(y==k) 
			{
				
				if(q==0&&p==0) 
				{
					q=i;p=j;r=j-i+1;
				}
				else
				{
					if(q<=i&&p>=j) 
					{
						q=i;p=j;
						r=j-i+1;
					}
					else
					if(!(q>=i&&p<=j))
					{
						int r1=j-i+1;
						if(r1>r)
						{
							q=i;p=j;
							r=r1;
						} 
					}
				}
			}
		}
	cout<<r;
	return 0;
}
