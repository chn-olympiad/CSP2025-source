#include<bits/stdc++.h>
using namespace std;
string st,s[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//=================
	cin>>st;
	for(int i=0;i<st.size();i++){
		if(st[i]<='9'&&st[i]>='0'){
			s[st[i]-'0']+=st[i];
		}
	}
	for(int i=9;i>=0;i--){
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
