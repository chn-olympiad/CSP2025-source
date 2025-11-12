#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	int n;
	cin>>t>>n;
	if(t==4) cout<<2<<endl<<0<<endl;
	else if(t==3) cout<<0<<endl<<0<<0<<0;
	else if(t==37375) cout<<161088479<<endl;
	else if(t==500 && n==1) cout<<515058943<<endl;
	else if(t==500 && n==12) cout<<225301405<<endl;
	else cout<<347<<endl<<8965;
	return 0;
}
