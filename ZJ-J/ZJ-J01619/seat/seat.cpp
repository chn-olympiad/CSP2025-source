#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],w,x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++)
	 if(i&1)
	  for(int j=1;j<=n;j++)
	   {
	   	w++;
	   	if(a[w]==x) {
	   		cout<<i<<' '<<j;
	   		return 0;
		   }
	   }
	 else
	  {
	  	for(int j=n;j;j--)
	  	 {
	  	 	w++;
	  	 	if(a[w]==x) {
	  	 		cout<<i<<' '<<j;
	  	 		return 0;
			   }
		   }
	  }
	return 0;
}
