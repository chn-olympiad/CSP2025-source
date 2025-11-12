#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c=1,r=0;
	int a[1000];
	cin>>n>>m;
	for(int i=0;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;++i)
	{
		if(a[0]<a[i])
			r++;
		else
			r=1;
		if(r>m)
		{
			r--;
			c++;
		}
		
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
}
