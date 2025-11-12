#include<bits/stdc++.h>
using namespace std;
int yzq[11];
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57) yzq[s[i]-'0']+=1;
	}
	for(int i=9;i>=0;i--){
		while(yzq[i]--) cout<<i;
	}
	return 0;
}
