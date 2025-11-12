#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,c=0,p=0,xiandu[501],x[501];
	string s;
	cin>>n>>m;
	cin>>s;
	for (int i=0;i<n;i++){
		cin>>xiandu[i];
	}
	for (int i=0;i<n;i++){
		if (s[i] == '0') x[i]++;
		for (int j=i;j>0;j--){
			c+=x[i];
			if (c>=xiandu[i]) break;
		}
		if(s[i]=='1'){
			 p++;
		}if (p==m) {
			cout<<p;
			continue;
		}
	}
	return 0;
}
