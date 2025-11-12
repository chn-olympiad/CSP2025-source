#include<bits/stdc++.h>
using namespace std;
int a[11];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]<='9' and s[i]>='0') a[int(s[i]-'0')]++;
	for(int i=9;i>=0;i--) while(a[i]--) printf("%c",char(i+'0'));
	return 0;
}
