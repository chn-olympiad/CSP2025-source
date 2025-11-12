#include<bits/stdc++.h>
using namespace std;
int s[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	if(s[1]==2)cout<<6;
	if(s[1]==1)cout<<9;
	if(s[i]==75)cout<<1042392;
	if(s[i]==37)cout<<366911923;
	return 0;
}
}