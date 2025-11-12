#include<bits/stdc++.h>
using namespace std;
string s;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int p=s[i]-'0';
			num[p]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++)cout<<i;
	}
	return 0;
}
