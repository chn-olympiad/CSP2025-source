#include<bits/stdc++.h>
using namespace std;
int n,m,mid=1,z,a[102],midd,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=z;i++)
	{
		cin>>a[i];
		if(a[i]>r)
		mid++;
	}
	midd=mid%n;
	mid=mid/n;
	if(midd!=0){
		if(mid%2==0){
			cout<<mid+1<<" "<<midd;
		}
		else
		cout<<mid+1<<" "<<n-midd+1;
	}
	else
	{
		if(mid%2==0){
			cout<<mid<<" "<<1;
		}
		else
		cout<<mid<<" "<<n;
	}
	return 0;
}
