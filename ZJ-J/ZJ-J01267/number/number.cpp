#include<bits/stdc++.h>
using namespace std;
int l,i,f[20],j;char s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=strlen(s);
	for(i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9') f[s[i]-48]++;
	for(i=9;i>=0;i--)
		for(j=1;j<=f[i];j++)
			cout<<i;
	return 0;
}