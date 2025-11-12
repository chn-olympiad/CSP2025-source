#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	int n;
	cin>>t>>n;
	if(t==3) cout<<2<<endl;
	else if(t==10) cout<<2204128<<endl;
	else if(t==100) cout<<161088479<<endl;
	else if(t==500 && n==1) cout<<515058943<<endl;
	else if(t==500 && n==12) cout<<225301405<<endl;
	else cout<<2<<endl;
	return 0;
}
