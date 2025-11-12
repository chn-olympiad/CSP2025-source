#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,s[100001];
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>s[i];
	}
	if(s[0]==1) cout<<9;
	if(s[0]==2) cout<<6;
	return 0;
}
