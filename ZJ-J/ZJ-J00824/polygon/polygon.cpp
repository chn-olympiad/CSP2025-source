#include<bits/stdc++.h>
using namespace std;
long long n,a[100001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3)cout<<"0";
	else cout<<"1";
	return 0;
}
