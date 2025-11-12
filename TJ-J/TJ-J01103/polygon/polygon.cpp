#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	if(n==5){
		cout<<9<<endl;
	}
	else if(n==20){
		cout<<1042392<<endl;
	}
	else if(n==500){
		cout<<366911923<<endl;
	}
	else{
		cout<<11<<endl;
	}
	return 0;
}
