#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	int cnt=0;
	bool flag=0;
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			if(i==0&&flag==0){
				cout<<"0";
				return 0;
			}
			flag=1;
			for(int j=0;j<a[i];j++){
				cout<<char(i+'0');
			}
		}
	}
	return 0;
}
