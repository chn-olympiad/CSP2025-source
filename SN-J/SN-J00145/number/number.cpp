#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],cnt=0;
int main(){
	std::ifstream cin("number.in");
	std::ofstream cout("number.out");
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(cnt-=1;cnt>=0;cnt--) cout<<a[cnt];
	return 0;
}
