#include<bits/stdc++.h> 
using namespace std;
struct node
{
	long long int a;long long int b;
}b[1000000];
long long int n,k,i,j,a[1000006],p,c,o,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	for(j=i;j<=n;j++)
	{
			c=i;
			o=0;
			while(c<=j)
			{
				o=o^a[c++];
			}
			if(o==p)
			{
				b[++p].a=i;
				b[p].b=j;
			}
			
	}
	for(i=1;i<=p;i++)
	for(j=i+1;j<=p;j++)
	{
		if(!(b[i].a<=b[j].a&&b[j].b<=b[i].b))
		{
			ans++;
		} 
		
	}
	cout<<ans<<endl;
	return 0;
} 


