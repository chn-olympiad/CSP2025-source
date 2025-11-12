#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	if(a+b>c&&a+c>b&&b+c>a) cout<<1;
	else cout<<0;
	return 0;
}
