#include<bits/stdc++.h>
using namespace std;
char c;
string s;
int len,i,f[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s,len=s.size();
	for(i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9') f[s[i]]++;
	for(c='9';c>='0';c--)
		for(i=1;i<=f[c];i++)
			cout<<c;
}
