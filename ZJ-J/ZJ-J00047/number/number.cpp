#include<bits/stdc++.h>
using namespace std;
char s[1100000];
int a[1100000],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int ls=strlen(s+1);
	for(int i=1;i<=ls;i++){
		if('0'<=s[i]&&'9'>=s[i]) a[++top]=s[i]-'0';
	}
	sort(a+1,a+top+1);
	for(int i=top;i>=1;i--) cout<<a[i];
	return 0;
}
