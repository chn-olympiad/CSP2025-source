#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10]={};
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int slen=s.length();
	for(int i=0;i<slen;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	bool can=0;
	for(int i=1;i<=9;i++){
		if(a[i]!=0){
			can=1;
			break;
		}
	}
	if(can==0){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
