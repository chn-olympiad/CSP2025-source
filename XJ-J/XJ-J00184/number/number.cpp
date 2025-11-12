#include<bits/stdc++.h>
using namespace std;
int ans[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			ans[s[i]-48]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		if(ans[i]>0){
			for(int j=0;j<ans[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
