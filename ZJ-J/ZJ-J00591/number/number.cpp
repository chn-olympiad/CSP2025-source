#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int len,b[1000005],t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
		if(s[i]>='0'&&s[i]<='9')b[++t]=s[i]-48;
	sort(b+1,b+1+t);
	for(int i=t;i>=1;i--)cout<<b[i];
	return 0;
}
