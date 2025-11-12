#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b,c,d;
	cin>>d>>a>>b>>c;
	int ans=max(a,b);
	ans=max(ans,c);
	if((a+b+c)>2*ans) cout<<1;
	else cout<<0;
	return 0;
}
