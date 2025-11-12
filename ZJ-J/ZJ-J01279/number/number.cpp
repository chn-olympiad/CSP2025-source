#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0) a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}

