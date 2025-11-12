#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin>>a;
	int ans=0;
	int x=a;
	if(x>=10){
		int a=x%10;
		int b=(x-a)/10;
		if(a>b){
			ans=a*10+b;
		} 
		if(a>b){
			ans=a*10+b;
		} 
	}
    cout<<ans;
	return 0;
} 
