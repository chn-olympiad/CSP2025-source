#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[0],na=1,ma,k=0;
	for(int i=1;i<n*m;i++)
	{
		if(a[i]>r) k++;
	}
	if((k/n)%2==0) cout<<k/n+1<<" "<<m-k%n;
	else cout<<k/n+1<<" "<<k%n;
	return 0;
}
