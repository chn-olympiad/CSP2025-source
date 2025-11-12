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
	}
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int mx=max(a,max(b,c)),tot=a+b+c;
		if(tot>2*mx){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	return 0;
}
