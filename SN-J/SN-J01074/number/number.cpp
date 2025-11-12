#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
string out;
ll b[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') b[(s[i]-'0')]++;
	}
	for(int i=9;i>=0;){
		if(b[i]>0){
			char c=i+'0';
			out+=c;
			b[i]--;
		}
		else i--;
	}
	cout<<out<<endl;
	return 0;
}
