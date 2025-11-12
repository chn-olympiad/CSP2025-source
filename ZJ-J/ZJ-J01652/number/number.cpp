#include <bits/stdc++.h>

using namespace std;
const int N=1e6+5;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++len]=s[i]-'0';
		}
	}
	sort(a+1,a+1+len);
	for(int i=len;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
