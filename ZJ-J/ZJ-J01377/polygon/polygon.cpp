#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int q=1;q<=n;q++)cin>>a[q];
	for(int q=1;q<=n-2;q++){
		for(int w=q+1;w<=n-1;w++)ans+=n-w;
	}
	cout<<ans;
	return 0;
}
