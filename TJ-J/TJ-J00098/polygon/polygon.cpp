#include<bits/stdc++.h>
using namespace std;
set<int>a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}else{
		int a,b,c;
		cin>>a>>b>>c;
		int y=max({a,b,c});
		if(a+b+c>y*2){
			cout<<n/3;

		}else{
			cout<<0;
		}return 0;
	}
return 0;

}
