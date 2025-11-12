#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans="";
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			ans+=i+'0';
		}
	}
	int st=0;
	while(ans[st]=='0' && ans.size()-st>1){
		st++;
	}
	for(int i=st;i<ans.size();i++){
		cout<<ans[i];	
	}
	return 0;
}
