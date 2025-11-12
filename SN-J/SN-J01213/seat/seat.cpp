#include <bist/stdc++.h>
using namespace std;
int main(){
	int m,n,b=0,c=0,d=0;
	int a[999];
	cin>>n>>m;
	for(int i;i<=n*m;i++){
		cin>>a[i];
		c=a[1]-a[0];
		d=a[1]-a[3];		
	}
	cout<<c<<d;
	return 0;
}
