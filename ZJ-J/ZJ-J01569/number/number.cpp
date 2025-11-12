#include <bits/stdc++.h>
using namespace std;

string s;
int a[15];
string ans;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		char c=s[i];
		if(c>='0' && c<='9') a[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			a[i]--;
			ans+=('0'+i);
		}
	}
	cout<<ans<<endl;
	return 0;
}