#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[105],x,y;
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out ","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	
	sort(a+1,a+n*m+1);
	
	for(int i=1;i<=n*m;i++)
		if(a[i]==x){
			y=n*m-i+1;
		}
	
	if(y==n)
		c=(y+1)/n;
	else
		c=y/n+1;
	if(c%2!=0)
		if(y==n)
			r=y;
		else
			r=y%n;
	else
		r=n-y%n+1;
		
	cout<<c<<" "<<r;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
