#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[500005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3)cout<<0;
	else{
		sort(a+1,a+n+1);
		int c=a[3];
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	return 0;
}
