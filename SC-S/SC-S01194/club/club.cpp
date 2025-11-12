#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a1[205],a2[205],a3[205];
	int t,n,ans;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		if(n=4)
		{
		sort(a1+1,a1+n+1);
		sort(a2+1,a2+n+1);
		sort(a3+1,a3+1+n);
		ans=a1[n]+a2[n]+a3[n]+max(a1[n-1],max(a2[n-1],a3[n-1])); 
		
		
		}else
	
			ans=max(a1[1],max(a2[1],a2[1]))+max(a1[1],max(a2[1],a2[1]));
			
			
		cout<<ans<<endl;
		
	}
	return 0;
 } 