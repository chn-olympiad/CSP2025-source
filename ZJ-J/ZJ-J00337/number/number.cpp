#include<bits/stdc++.h>
using namespace std;
string s,ans;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end(),cmp);
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			ans+=s[i];
		}
	}
	cout<<ans;
	return 0;
}
