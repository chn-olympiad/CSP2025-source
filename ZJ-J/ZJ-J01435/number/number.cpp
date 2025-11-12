#include<bits/stdc++.h>
using namespace std;
long long l,i,j,t[1000];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	l=s.size();
	for(i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-48]++;
		}
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}
