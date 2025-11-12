#include<bits/stdc++.h>
using  namespace std;
int a[11][11];
int c[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int x=0,p=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>c[i]; 
	}
	for(int i=1;i<n*m;i++)
	{
		if(c[i]>c[0]) x++;
	}
    p=n*m-(n*m-1-x);
    for(int i=1;i<m+1;i++)
    {
    	if(p<n){
			cout<<i<<' '<<p;
			return 0;
		 }
		 if(p==n){
		 	cout<<i<<' '<<n;
		 	return 0;
		 }
		if(i%2==1&&p<i*n+1){
		 	cout<<i<<' '<<i*n-p-1;
		 	return 0;
		 }
		 if(i%2==0&&p<i*n+1){
		 	cout<<i<<' '<<p+1-i;
		 	return 0;
		 }		 
	}
	return 0;
}
