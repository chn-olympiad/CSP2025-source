#include<bits/stdc++.h>
using namespace std;
string s;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	bool f=1;
	for(int i=9;i>=0;i--){
		if(i==0&&f==1){
			cout<<0;
			return 0;
		}
		for(int j=1;j<=a[i];j++){
			cout<<i;
			f=0;
		}
	}
	return 0;
}
