#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(long unsigned int i=0;i<str.size();i++){
		if(str[i]>47&&str[i]<58){
			cnt[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(cnt[i]!=0){
			for(int j=0;j<cnt[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
