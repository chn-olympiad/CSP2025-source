#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int s=0;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])s++;
	}
	s++;
	int lie=s/n+(s%n!=0),hang;
	if(lie%2==0)hang=n-s%n+(s%n!=0);
	else hang=s%n+n*(s%n==0);
	cout<<lie<<" "<<hang;
	return 0;
}