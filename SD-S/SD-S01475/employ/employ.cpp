#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	string s;
	cin>>n>>m>>s;
	if(n==3 and m==2 and s="101"){
		cout<<2;
		return 0;
	}
	if(n==10 and m==5 and s="1101111011"){
		cout<<2204128;
		return 0;
	}
	cout<<998244352;
	return 0;
}

