#include<bits/stdc++.h>
using namespace std;
string st,ans;
int s[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	int stsi=st.size();
	for(int i=0;i<stsi;i++){
		if(st[i]>='0' && st[i]<='9'){
			s[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=s[i];j++){
			ans+=i+'0';
		}
	}
	cout<<ans;
	return 0;
}
