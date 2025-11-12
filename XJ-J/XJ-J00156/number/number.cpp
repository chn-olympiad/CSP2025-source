#include<bits/stdc++.h>
using namespace std;
string s;
int tong[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		if(s[i]>='0'&&s[i]<='9') tong[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++){
			cout<<i;
		}
	}
	return 0;
}
