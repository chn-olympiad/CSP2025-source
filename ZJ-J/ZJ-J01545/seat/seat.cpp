#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int l=a[1],li;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==l)li=n*m-i+1;
	int ansn,ansm=(li-1)/n+1;
	if(ansm%2==1)ansn=li-(ansm-1)*n;
	else ansn=ansm*n-li+1;
	cout<<ansm<<" "<<ansn;
	return 0;
}
