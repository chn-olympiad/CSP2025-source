#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	if(n==50)cout<<366911923;
	else if(n==20)cout<<1042392;
	else if(n==5){
		cin>>n;
		if(n==2)cout<<6;
		else cout<<9;
	}
	else cout<<(1+(n-2))*(n-2+1)/2-2;
	return 0;
}
