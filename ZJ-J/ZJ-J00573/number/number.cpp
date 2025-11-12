#include <bits/stdc++.h>
using namespace std;
int cnt[10];
string s;
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i];i++)
		if(isdigit(s[i]))cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(cnt[i]--)putchar(i+'0');putchar('\n');
	return 0;
}
