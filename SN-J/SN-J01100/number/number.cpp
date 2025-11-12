#include<bits/stdc++.h>
using namespace std;
string s;
int a[25],cnt;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0&&!cnt){
			cout<<0;
			return 0;
		}
		for(int j=1;j<=a[i];j++){
			printf("%d",i);cnt=1;
		}
	}
	return 0;
}
