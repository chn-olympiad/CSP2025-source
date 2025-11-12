#include <bits/stdc++.h>
using namespace std;
string s,s1 = "";
int z[1000003] = {0};
int cnt = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.length()==1&&s[0]-'0'>=0&&s[0]-'0'<=9){
		cout<<s;
		return 0;
	}
	for(int i = 0;i<=s.length()-1;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			s1+=s[i];
			cnt++;
		}
	}
	for(int i = 0;i<=cnt-1;i++){
		z[i] = s1[i]-'0';
	}
	sort(z,z+cnt);
	for(int i = cnt-1;i>=0;i--){
		cout<<z[i];
		
	}
	
	return 0;
}
