#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("clubin","r",stdin);
	freopen("club.out","w",stdout);
	int t,b,a1,a2,a3,n,c,d;
	cin>>t;
	int a[t][3];
	cin>>n;
	cin>>a1>>a2>>a3;
	for(int i;i<n*3;i++){
		cin>>a[t][3];
	}
	b=a[0][0]+a[0][1]+a[0][2];
	c=a[1][0]+a[1][1]+a[1][2];
	d=a[2][0]+a[2][1]+a[2][2];
	
	cout<<b<<endl<<c<<endl<<d<<endl;

	return 0;
}

