#include<bits/stdc++.h>
#define int long lnog
using namespace std;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	long long a,b,c;
	if(n==1){
		cout<<0;
	} 
	if(n==2){
		cout<<0;
	}
	if(n==3){
		cin>>a>>b>>c;
		if(a+b>c&&b+c>a&&a+c>b){
			cout<<1;
		}
	}
	return 0;
}
