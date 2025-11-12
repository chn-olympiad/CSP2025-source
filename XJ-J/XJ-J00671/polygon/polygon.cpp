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
	vector<int> a;
	int mx=-1,sum=0;
	for(int i=0,j;i<n;i++){
		cin>>j;
		a.push_back(j);
		if(j>mx) mx=j;
		sum+=j;
	}
	if(n==3){
		if(sum>(mx*2)) cout<<1;
		else cout<<0;
	}else{
		if(sum>(mx*2)) cout<<6;
		else cout<<0;
	}
	return 0;
}
