#include <bits/stdc++.h>
using namespace std;
long long n,i,t,a[1000010];
char s[1000010];
bool cmp(int t,int w){return t>w;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;n=strlen(s+1);
	for (i=1;i<=n;i++)
		if (s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
	sort(a+1,a+1+t,cmp);
	for (i=1;i<=t;i++) cout<<a[i];
	return 0;
}
