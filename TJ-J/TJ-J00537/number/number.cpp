#include<bits/stdc++.h>
using namespace std;
int sz[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(sz,0,sizeof(sz));
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sz[s[i]-48]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sz[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
