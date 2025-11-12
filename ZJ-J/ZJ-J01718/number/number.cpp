#include <bits/stdc++.h>
using namespace std;
int n,l,f[100];
char str[1000010];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str+1;
	l=strlen(str+1);
	for(int i=1;i<=l;i++)
		if(str[i]>='0'&&str[i]<='9') {
			f[str[i]-48]++;
		}
	for(int i=9;i>=0;i--)
		while(f[i]--)
			cout<<i;
	return 0;
}
