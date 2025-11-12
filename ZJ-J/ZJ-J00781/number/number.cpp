#include<bits/stdc++.h>
using namespace std;
int p[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.length()-1;i++){
		if(s[i]>='0'&&s[i]<='9') p[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=p[i];j++){
			cout<<i;
		}
	}
	return 0;
}