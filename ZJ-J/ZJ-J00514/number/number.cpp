#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<int> t(20,0);
	for(char x:s){
		if(x>='0' and x<='9'){
			t[x-'0']++;
		}
	}
	string res;
	for(int i=9;i>=0;i--){
		while(t[i]){
			res.push_back(i+'0');
			t[i]--;
		}
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}