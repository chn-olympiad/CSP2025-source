#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int ma=-1;
		ma=max(a,b);
		ma=max(ma,c);
		int x=a+b+c;
		if(x>2*ma) cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
