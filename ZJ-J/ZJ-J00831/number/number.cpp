#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
stack<int> stk;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'<=9){
			stk.push(s[i]-'0');
		}
	}
	while(!stk.empty()){
		int tmp;
		tmp=stk.top();
		stk.pop();
		a[cnt]=tmp;
		cnt++;
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
