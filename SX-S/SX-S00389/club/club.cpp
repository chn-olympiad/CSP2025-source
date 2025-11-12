#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main()
{
	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdin);
 	int t,n,ans;
 	cin>>t>>n;
 	for(int i=0;i<=n;i++){
 		for(int j=0;j<=n;j++)
		{
			ans++;	 
		}	
 	}
 	cout<<ans;
	return 0;
}
