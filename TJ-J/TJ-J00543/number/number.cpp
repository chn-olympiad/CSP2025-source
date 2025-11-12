#include<bits/stdc++.h>
using namespace std;
int tong[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			tong[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(tong[i]==0){
			continue;
		}
		for(int j=0;j<tong[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
