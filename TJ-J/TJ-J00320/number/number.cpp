#include<bits/stdc++.h>
using namespace std;
string s,tmp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') tmp+=s[i];
	}
	sort(tmp.begin(),tmp.end());
	for(int i=tmp.size()-1;i>=0;i--){
		cout<<tmp[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
