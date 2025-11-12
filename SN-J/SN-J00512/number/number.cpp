#include<bits/stdc++.h>
using namespace std;
string s;
int n,si[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')
			si[++n]=s[i]-'0';
	}
	sort(si+1,si+n+1);
	for(int i=n;i;i--) cout<<si[i];
	return 0;
}
