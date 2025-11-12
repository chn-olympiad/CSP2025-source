#include<bits/stdc++.h>
using namespace std;
int n[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			n[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(n,n+cnt);
	for(int i=cnt-1;i>=0;i--){

		cout<<n[i];
 }
	return 0;
}