#include<bits/stdc++.h>
using namespace std;
long long int l,r,n,k,x,b[500005],ans; 
long long int ll,rr;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		b[i]=(x^b[i-1]);
	}
	cout<<endl;
	for(l=1;l<=n;l++)
	for(r=l;r<=n;r++)
	{
	
		if(l>=ll&&r<=rr&&(b[r]^b[l-1])==k)
		{
			ll=l;
			rr=r;
		}
		else if((l>rr||r<ll)&&(b[r]^b[l-1])==k)
		{
			ans++;
			ll=l;
			rr=r;
		}
	}
	cout<<ans;
	return 0;
}
