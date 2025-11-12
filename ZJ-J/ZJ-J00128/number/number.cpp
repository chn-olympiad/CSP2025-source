#include<bits/stdc++.h>
using namespace std;
long long vis[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9') vis[(s[i]-'0')]++;
	}
	for(long long i=9;i>=0;i--){
		for(long long j=1;j<=vis[i];j++) cout<<i;
	}
	return 0;
}
