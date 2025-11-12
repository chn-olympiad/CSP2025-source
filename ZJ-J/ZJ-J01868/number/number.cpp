#include<bits/stdc++.h>
using namespace std;
int tong[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			tong[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=tong[i];j>0;j--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
