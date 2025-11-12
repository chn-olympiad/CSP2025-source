#include <bits/stdc++.h>
using namespace std;
int i,l,f[1000001],pop;
char s[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	l=strlen(s+1);
	for(i=1;i<=l;i++)
		if(s[i]>='0'&&s[i]<='9')f[s[i]-48]++;
	for(i=9;i>=0;i--)while(f[i]>0)cout<<i,f[i]--;
	return 0;
}