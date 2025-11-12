#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int a,b,c,f;
}x[100005];
long long int aa[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,i,l,ans=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>x[i].a>>x[i].b>>x[i].c;
			x[i].f=n/2;
			aa[i]=x[i].a;
		}
		l=n/2;
		sort(aa+1,aa+n+1);
		for(i=n;i>l;i--)
		{
			ans+=x[i].a;
		}
		cout<<ans;
	}	
	return 0; 
 } 
