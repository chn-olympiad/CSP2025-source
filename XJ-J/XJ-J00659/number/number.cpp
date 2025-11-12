#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	int flag;
	cin>>s;
	char maxx='0';
	for(int i = 0;i<=s.size()-1;i++){
		maxx=' ';
		for(int j=0;j<=s.size()-1;j++){
			if(s[j]>='0'&&s[j]<='9'&&s[j]>=maxx){
				maxx=s[j];
				flag=j;
			}
		}
		s[flag]=' ';
		ans+=maxx;
	}
	cout<<ans;
	return 0;
}
