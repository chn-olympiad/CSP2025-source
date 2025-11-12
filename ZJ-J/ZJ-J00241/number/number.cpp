#include<bits/stdc++.h>
using namespace std;
long long a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	long long i,j;
	for(i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9) a[s[i]-'0']++;
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}