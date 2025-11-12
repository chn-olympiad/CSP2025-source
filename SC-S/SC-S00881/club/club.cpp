#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100001],t,n,s=0,c=0;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
		cin>>t;
		for(int i=1;i<=t;i++)
		{
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				cin>>a[1]>>a[2]>>a[3];
			}
			for(int i=1;i<=n;i++)
			{
				if(a[1]>a[2]&&a[1]>a[3])
					s=a[1];
				else if(a[2]>a[1]&&a[2]>a[3])
					s=a[2];
				else if(a[3]>a[1]&&a[3]>a[2])
					s=a[3];
				s+=s;
			}
				
			cout<<s<<endl;
		}
	return 0;
}