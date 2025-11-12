#include <bits/stdc++.h>
using namespace std;
int a[1000010],zhizhen=1;
int main(){
	string s;
	string ans;
	freopen("number.in","r",stdin);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[zhizhen++]=s[i]-'0';
		}
	}
	sort(a+1,a+zhizhen+1);
	for(int i=zhizhen;i>1;i--){
		ans+=a[i]+'0';		
	}
	freopen("number.out","w",stdout);
	cout<<ans;
	return 0;
}
